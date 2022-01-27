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
		if (!(bool)ori.getPlayer()) {
			outp.addMessage(u8"ֻ����ҿ���ʹ�ô�����!");
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
					//	outp.addMessage(u8"���Ĵ��͵������Ѿ��ﵽ����: " +
							//std::to_string(WarpUtil::getPlayerWarpNumber(xuid)));
						return;
					}

					//check money
					if (LLMoneyGet(xuid) < config.set_warp_cost) {
						//outp.addMessage(u8"��������: " +
							//std::to_string(LLMoneyGet(xuid)));
						return;
					}
					LLMoneyReduce(xuid, config.set_warp_cost);

					//check warpname
					std::regex express(config.warp_name_regex);
					if (!std::regex_match(val, express)
						&& val.length() >= config.max_warp_name_length
						&& val.length() <= config.min_warp_name_length) {
					//	outp.addMessage(u8"������Ĵ��͵����ƹ�������̻����Υ���ַ�!");
					}

					//check distance
					auto list = WarpUtil::getWarpList();
					auto curpos = ori.getWorldPosition();
					for (auto& i : list) {
						auto pos = WarpUtil::getWarpPos(i);
						if (pos.dim == pl->getDimensionId()) {
							auto distance = WarpUtil::distanceBetTwoPoints(pos, { (int)curpos.x,(int)curpos.y,(int)curpos.z,0 });
							if (distance <= config.warp_distance) {
							  //  outp.addMessage(u8"�����Ѿ���һ�����͵���!");
								return;
							}
						}
					}
				}

				if (WarpUtil::hasWarp(val)) {
					//outp.addMessage(u8""+val+u8"�Ĵ��͵���!");
					return;
				}
				
				auto curpos = ori.getWorldPosition();
				WarpUtil::createWarp(val, xuid, { (int)curpos.x,(int)curpos.y,(int)curpos.z,pl->getDimensionId() });
				//outp.addMessage(u8"�ѳɹ��������͵�");
			}
			break;
		}

		case del: {
			if (val_isSet) {
				if (!pl->isOP()
					&& (WarpUtil::getWarpOwner(val) != xuid)){
					//outp.addMessage(u8"�˴��͵�����˲�����!");
					return;
				}

				if (!WarpUtil::hasWarp(val)) {
				//	outp.addMessage(u8"û������"+val+u8"�Ĵ��͵�");
					return;
				}

				WarpUtil::delWarp(val);
				//outp.addMessage(u8"�ɹ�ɾ���˴��͵�");
			}
			break;
		}

		case ls: {
			std::string msg;
			for (auto& i : WarpUtil::getWarpList()) {
				auto pos = WarpUtil::getWarpPos(i);
				auto owner = WarpUtil::getWarpOwner(i);
				msg += u8"======== ���͵�: " + i + "=========";
				msg += "\nX: " + std::to_string(pos.x);
				msg += "\nY: " + std::to_string(pos.y);
				msg += "\nZ: " + std::to_string(pos.z);
				msg += u8"\n����: " + std::to_string(pos.dim);
				msg += "\n===========================";
			}
			outp.addMessage(msg);
			break;
		}

		case go: {
			if (val_isSet) {
				if (!pl->isOP()) {
					if (LLMoneyGet(xuid) < config.set_warp_cost) {
					//	outp.addMessage(u8"��������: " +
						//	std::to_string(LLMoneyGet(xuid)));
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
		registry->registerCommand("warp", "Teleport", CommandPermissionLevel::Any, { (CommandFlagValue)0 }, { (CommandFlagValue)0x80 });
		registry->addEnum<WarpCommand::WARPOP>("WARPOP", { {"add", WARPOP::add}, {"del", WARPOP::del}, {"go", WARPOP::go}, {"gui", WARPOP::gui}, {"ls", WARPOP::ls} });
		registry->registerOverload<WarpCommand>("warp", makeMandatory<CommandParameterDataType::ENUM>(&WarpCommand::op, "op", "WARPOP"), makeOptional(&WarpCommand::val, "warp", &WarpCommand::val_isSet));
	}
};


