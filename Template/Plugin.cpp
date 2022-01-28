#include "pch.h"
#include "Global.h"
#include "WarpUtil.h"
#include "Command.h"
#include <LoggerAPI.h>
#include <KVDBAPI.h>
#include <LLAPI.h>

Logger logger("YourWarp");
std::unique_ptr<KVDB> db;
Config config;

void PluginInit()
{
	LL::registerPlugin("YourWarp", "An easy-to-use warp plugin", LL::Version(1, 0, 0));
	WarpUtil::loadConfig();
	WarpUtil::initDB();
	reinitWARPGUI();
	initCommand();
	logger.info("load sucess!");
}



