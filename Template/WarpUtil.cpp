#include "pch.h"
#include "WarpUtil.h"

namespace WarpUtil {
	void test(std::string t) {
		logger.info(t);
	}

	Config loadConfig() {
		return Config::Load("./plugins/YourWarp/setting.json");
	}
}