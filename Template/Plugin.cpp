#include "pch.h"
#include <EventAPI.h>
#include <LoggerAPI.h>
#include <MC/Level.hpp>
#include <MC/BlockInstance.hpp>
#include <MC/Block.hpp>
#include <MC/BlockSource.hpp>
#include <MC/BlockLegacy.hpp>
#include <MC/Actor.hpp>
#include <MC/Player.hpp>
#include <MC/ItemStack.hpp>
#include <LLAPI.h>
#include <Utils/PluginOwnData.h>
#include "WarpUtil.h"

Logger logger("YourWarp");

void PluginInit()
{
	LL::registerPlugin("YourWarp", "An easy-to-use warp plugin", LL::Version(1, 0, 0));
	WarpUtil::loadConfig();
}



