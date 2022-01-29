#include "pch.h"
#include "Global.h"
#include "Money.h"
#include "LLmoney.h"
#include "ScoreBoardMoney.h"
#include "WarpUtil.h"
#include <regex>
#include <EventAPI.h>
#include <LLMoney.h>
#include <PlayerInfoAPI.h>
#include <GuiAPI.h>
#include <RegCommandAPI.h>
#include <MC/Player.hpp>
#include <MC/ServerPlayer.hpp>

//from lltpa https:github.com/LiteLDev/LiteLoaderPlugins/blob/main/LLtpa/Teleport.cpp
std::shared_ptr<GUI::SimpleForm> WARPGUI;
void reinitWARPGUI() {
	using namespace GUI;
	if (!WARPGUI) WARPGUI = std::make_shared<SimpleForm>();
	WARPGUI->title = "§9§l传送点列表 ";
	WARPGUI->content = "";
	WARPGUI->reset();
	auto list = WarpUtil::getWarpList();
	for (auto& k : list) {
		WARPGUI->addButton(GUIButton(string(k)));
	}
}

void sendWARPGUI(ServerPlayer* wp) {
	using namespace GUI;
	sendForm(*wp, SimpleFormBinder(WARPGUI, [](ServerPlayer& wp, SimpleFormBinder::DType d) {
		if (d.set) {
			wp.runcmd("ywarp go \"" + d.val().second + "\"");
		}
		}));
}

class WarpCommand :public Command {
	enum WARPOP :int {
		go = 1,
		add = 2,
		ls = 3,
		del = 4,
		gui = 5,
		help = 6,
		reload = 7
	} op;
	bool val_isSet;
	std::string val;
public:
	void execute(CommandOrigin const& ori, CommandOutput& outp) const {
		if (!ori.getPlayer()) {
			outp.addMessage(u8"§c只有玩家可以使用此命令!");
			return;
		}
		auto pl = ori.getPlayer();
		auto xuid = pl->getXuid();
		switch (op)
		{
		case gui: {
			sendWARPGUI(pl);
			return;
		}

		case add: {
			if (val_isSet) {
				if (!pl->isOP()) {
					//check warpnum
					if (WarpUtil::getPlayerWarpNumber(xuid) >= config.max_warp_per_user) {
						outp.addMessage(u8"§c您的传送点数量已达到限制: " +
							std::to_string(WarpUtil::getPlayerWarpNumber(xuid)));
						return;
					}

					//check money
					if (money->getMoney(pl) < config.set_warp_cost) {
						outp.addMessage(u8"§c您的余额不足: " +
							std::to_string(money->getMoney(pl)));
						return;
					}
					money->reduceMoney(pl, config.set_warp_cost);

					//check warpname
					std::regex express(config.warp_name_regex);
					if (!std::regex_match(val, express)
						|| val.length() >= config.max_warp_name_length
						|| val.length() <= config.min_warp_name_length) {
						outp.addMessage(u8"§c你输入的传送点名称过长或过短或包含违规字符!");
						return;
					}

					//check distance
					auto list = WarpUtil::getWarpList();
					auto curpos = ori.getWorldPosition();
					for (auto& i : list) {
						auto pos = WarpUtil::getWarpPos(i);
						if (pos.dim == pl->getDimensionId()) {
							auto distance = WarpUtil::distanceBetTwoPoints(pos, { (int)curpos.x,(int)curpos.y,(int)curpos.z,0 });
							if (distance <= config.warp_distance) {
								outp.addMessage(u8"§c附近已经有一个传送点了!");
								return;
							}
						}
					}
				}

				if (WarpUtil::hasWarp(val)) {
					outp.addMessage(u8"§c已经有名为 " + val + u8" 的传送点了!");
					return;
				}

				auto curpos = ori.getWorldPosition();
				WarpUtil::createWarp(val, xuid, { (int)curpos.x,(int)curpos.y,(int)curpos.z,pl->getDimensionId() });
				reinitWARPGUI();
				outp.addMessage(u8"§a成功创建传送点！");
			}
			break;
		}

		case del: {
			if (val_isSet) {
				if (!pl->isOP()
					&& (WarpUtil::getWarpOwner(val) != xuid)) {
					outp.addMessage(u8"§c此传送点的主人不是你!");
					return;
				}

				if (!WarpUtil::hasWarp(val)) {
					outp.addMessage(u8"§c没有名为 " + val + " 的传送点！");
					return;
				}

				WarpUtil::delWarp(val);
				reinitWARPGUI();
				outp.addMessage(u8"§a成功删除此传送点！");
			}
			break;
		}

		case ls: {
			std::string msg;
			for (auto& i : WarpUtil::getWarpList()) {
				auto pos = WarpUtil::getWarpPos(i);
				auto owner = WarpUtil::getWarpOwner(i);
				msg += u8"§6§m======== §b§l传送点: §e" + i + "§6§m=========";
				msg += "\n§bX: §e" + std::to_string(pos.x);
				msg += "\n§bY: §e" + std::to_string(pos.y);
				msg += "\n§bZ: §e" + std::to_string(pos.z);
				msg += u8"\n§b世界: §e" + std::to_string(pos.dim);
				msg += u8"\n§b创建者: §e" + PlayerInfo::fromXuid(owner) + "(" + owner + ")";
				msg += "\n§6§m===========================\n";
			}
			outp.addMessage(msg);
			break;
		}

		case go: {
			if (val_isSet) {
				if (!pl->isOP()) {
					if (money->getMoney(pl) < config.set_warp_cost) {
						outp.addMessage(u8"§c您的余额不足: " +
							std::to_string(money->getMoney(pl)));
						return;
					}
					money->reduceMoney(pl, config.set_warp_cost);
				}

				if (WarpUtil::hasWarp(val)) {
					auto pos = WarpUtil::getWarpPos(val);
					pl->teleport({ pos.x,pos.y,pos.z }, pos.dim);
					return;
				}
				else outp.addMessage(u8"§c没有名为 " + val + " 的传送点！");
			}
			break;
		}

		case help: {
			outp.addMessage("§b§l传送系统帮助\n§e- §a/ywarp ls —— §e列出传送点\n- §a/ywarp gui —— §e打开传送点界面\n- §a/ywarp add —— §e添加传送点\n- §a/ywarp del —— §e删除传送点\n- §a/ywarp go —— §e前往传送点\n- §a/ywarp reload —— §e重新载入配置文件\n");
			break;
		}

		case reload: {
			if (pl->isOP()) {
				WarpUtil::loadConfig();
				outp.addMessage("reload sucess!");
				return;
			}
			outp.addMessage("§c你没有权限!");
			break;
		}
		default:
			break;
		}
	}

	static void setup(CommandRegistry* registry) {
		using RegisterCommandHelper::makeMandatory;
		using RegisterCommandHelper::makeOptional;
		registry->registerCommand("ywarp", "An easy-to-use warp plugin", CommandPermissionLevel::Any, { (CommandFlagValue)0 }, { (CommandFlagValue)0x80 });
		registry->addEnum<WarpCommand::WARPOP>("WARPOP", { {"add", WARPOP::add}, {"del", WARPOP::del}, {"go", WARPOP::go}, {"gui", WARPOP::gui}, {"ls", WARPOP::ls},{"help",WARPOP::help},{"reload",WARPOP::reload} });
		registry->registerOverload<WarpCommand>("ywarp", makeMandatory<CommandParameterDataType::ENUM>(&WarpCommand::op, "op", "WARPOP"), makeOptional(&WarpCommand::val, "warp", &WarpCommand::val_isSet));

	}
};


void initCommand() {
	Event::RegCmdEvent::subscribe([](const Event::RegCmdEvent& e) {
		WarpCommand::setup(e.mCommandRegistry);
		return true;
		});
}
