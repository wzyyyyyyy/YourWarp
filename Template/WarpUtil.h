#pragma once
#include <LoggerAPI.h>
#include "Config.hpp"

extern Logger logger;

class Config;

namespace WarpUtil {
	void test(std::string t);
	Config loadConfig();
}