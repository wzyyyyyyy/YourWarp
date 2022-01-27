#pragma once
#include <Nlohmann/json.hpp>
#include <Utils/FileHelper.h>
#include <LoggerAPI.h>
extern Logger logger;

class Config {
public:
	int warp_distance,
		max_warp_per_user,
		max_warp_name_length,
		min_warp_name_length,
		set_warp_cost,
		use_warp_cost;
	std::string warp_name_regex;
	Config static load(std::string path) {
		Config conf;
		try {
			auto json = nlohmann::json::parse(ReadAllFile(path).value());
			conf.max_warp_per_user = json["max_warp_per_user"].get<int>();
			conf.max_warp_name_length = json["max_warp_name_length"].get<int>();
			conf.min_warp_name_length = json["min_warp_name_length"].get<int>();
			conf.set_warp_cost = json["set_warp_cost"].get<int>();
			conf.use_warp_cost = json["use_warp_cost"].get<int>();
			conf.warp_name_regex = json["warp_name_regex"].get<std::string>();
		}
		catch (nlohmann::json::exception e) {
			logger.error(e.what());
			*((int*)0) = 0;//force crash :)
		}
		return conf;
	}
};