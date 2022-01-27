#include "pch.h"
#include "Global.h"
#include "WarpUtil.h"
#include <EventAPI.h>
#include <LLMoney.h>
#include <RegCommandAPI.h>
#include <MC/Player.hpp>
#include <MC/ServerPlayer.hpp>
#include <regex>

//from lltpa https:github.com/LiteLDev/LiteLoaderPlugins/blob/main/LLtpa/Teleport.cpp
class WarpCommand :public Command {
	enum WARPOP :int {
		go = 1,
		add = 2,
		ls = 3,
		del = 4,
		gui = 5
	} op;
	bool val_isSet;
	std::string val;
public:
	void execute(CommandOrigin const& ori, CommandOutput& outp) const {
		if (!ori.getPlayer()) {
			outp.addMessage(u8"只有玩家可以使用此命令!");
			return;
		}
		auto pl = ori.getPlayer();
		auto xuid = pl->getXuid();
		switch (op)
		{
		case gui: {
			return;
		}

		case add: {
			if (val_isSet) {
				if (!pl->isOP()) {
					//check warpnum
					if (WarpUtil::getPlayerWarpNumber(xuid) >= config.max_warp_per_user) {
						outp.addMessage(u8"您的传送点数量已达到限制: " +
							std::to_string(WarpUtil::getPlayerWarpNumber(xuid)));
						return;
					}

					//check money
					if (LLMoneyGet(xuid) < config.set_warp_cost) {
						outp.addMessage(u8"您的余额不足: " +
							std::to_string(LLMoneyGet(xuid)));
						return;
					}
					LLMoneyReduce(xuid, config.set_warp_cost);

					//check warpname
					std::regex express(config.warp_name_regex);
					if (!std::regex_match(val, express)
						|| val.length() >= config.max_warp_name_length
						|| val.length() <= config.min_warp_name_length) {
						outp.addMessage(u8"你输入的传送点名称过长或过短或包含违规字符!");
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
								outp.addMessage(u8"附近已经有一个传送点了!");
								return;
							}
						}
					}
				}

				if (WarpUtil::hasWarp(val)) {
					outp.addMessage(u8"已经有名为" + val + u8"的传送点了!");
					return;
				}

				auto curpos = ori.getWorldPosition();
				WarpUtil::createWarp(val, xuid, { (int)curpos.x,(int)curpos.y,(int)curpos.z,pl->getDimensionId() });
				outp.addMessage(u8"成功创建传送点！");
			}
			break;
		}

		case del: {
			if (val_isSet) {
				if (!pl->isOP()
					&& (WarpUtil::getWarpOwner(val) != xuid)) {
					outp.addMessage(u8"此传送点的主人不是你!");
					return;
				}

				if (!WarpUtil::hasWarp(val)) {
					outp.addMessage(u8"没有名为" + val + "的传送点！");
					return;
				}

				WarpUtil::delWarp(val);
				outp.addMessage(u8"成功删除此传送点！");
			}
			break;
		}

		case ls: {
			std::string msg;
			for (auto& i : WarpUtil::getWarpList()) {
				auto pos = WarpUtil::getWarpPos(i);
				auto owner = WarpUtil::getWarpOwner(i);
				msg += u8"======== 传送点: " + i + "=========";
				msg += "\nX: " + std::to_string(pos.x);
				msg += "\nY: " + std::to_string(pos.y);
				msg += "\nZ: " + std::to_string(pos.z);
				msg += u8"\n世界: " + std::to_string(pos.dim);
				msg += "\n===========================\n";
			}
			outp.addMessage(msg);
			break;
		}

		case go: {
			if (val_isSet) {
				if (!pl->isOP()) {
					if (LLMoneyGet(xuid) < config.set_warp_cost) {
						outp.addMessage(u8"您的余额不足: " +
							std::to_string(LLMoneyGet(xuid)));
						return;
					}
					LLMoneyReduce(xuid, config.set_warp_cost);
				}

				if (WarpUtil::hasWarp(val)) {
					auto pos = WarpUtil::getWarpPos(val);
					pl->teleport({ pos.x,pos.y,pos.z }, pos.dim);
					return;
				}
			}
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
		registry->addEnum<WarpCommand::WARPOP>("WARPOP", { {"add", WARPOP::add}, {"del", WARPOP::del}, {"go", WARPOP::go}, {"gui", WARPOP::gui}, {"ls", WARPOP::ls} });
		registry->registerOverload<WarpCommand>("ywarp", makeMandatory<CommandParameterDataType::ENUM>(&WarpCommand::op, "op", "WARPOP"), makeOptional(&WarpCommand::val, "warp", &WarpCommand::val_isSet));
	}
};

void initCommand() {
	Event::RegCmdEvent::subscribe([](const Event::RegCmdEvent& e) {
		WarpCommand::setup(e.mCommandRegistry);
		return true;
		});
}
