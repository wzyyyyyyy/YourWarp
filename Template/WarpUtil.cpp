#include "pch.h"
#include "Global.h"
#include "WarpUtil.h"
#include <MC/BlockPos.hpp>
#include <KVDBAPI.h>

namespace WarpUtil {
	Config loadConfig() {
		config = Config::load(CONFPATH);
		return config;
	}

	void initDB() {
		db = KVDB::create(DBPATH);
		std::string tmp;
		if (db->get("__warplist__", tmp))
			return;
		db->put("__warplist__", "{}");
	}

	int distanceBetTwoPoints(Pos4 a, Pos4 b) {
		auto x = a.x - b.x;
		auto y = a.y - b.y;
		auto z = a.z - b.z;
		return (int)sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
	}

	bool hasWarp(std::string warpname) {
		std::string tmp;
		return db->get(warpname, tmp);
	}

	std::string getWarpOwner(std::string warpname) {
		std::string tmp;
		db->get(warpname, tmp);
		auto json = nlohmann::json::parse(tmp);
		return json["owner"].get<std::string>();
	}

	Pos4 getWarpPos(std::string warpname) {
		std::string tmp;
		db->get(warpname, tmp);
		auto json = nlohmann::json::parse(tmp);
		auto x = json["x"].get<int>();
		auto y = json["y"].get<int>();
		auto z = json["z"].get<int>();
		auto dim = json["dim"].get<int>();
		return Pos4{ x,y,z,dim };
	}

	int getPlayerWarpNumber(std::string pl) {
		std::string tmp;
		if (db->get(pl, tmp))
			return atoi(tmp.c_str());
		return 0;
	}

	void setPlayerWarpNumber(std::string pl, int num) {
		std::string tmp;
		if (db->get(pl, tmp))
			db->set(pl, std::to_string(num));
		else db->put(pl, std::to_string(num));
	}

	bool createWarp(std::string warpname, std::string owner, Pos4 pos) {
		auto num = getPlayerWarpNumber(owner);
		setPlayerWarpNumber(owner, num++);
		nlohmann::json json;
		json["owner"] = owner;
		json["x"] = pos.x;
		json["y"] = pos.y;
		json["z"] = pos.z;
		json["dim"] = pos.dim;
		std::string tmp;
		db->get("__warplist__", tmp);
		auto json_ = nlohmann::json::parse(tmp);
		json_[warpname] = owner;
		db->set("__warplist__", json_.dump());
		return db->put(warpname, json.dump());
	}

	bool delWarp(std::string warpname) {
		auto owner = getWarpOwner(warpname);
		auto num = getPlayerWarpNumber(owner);
		setPlayerWarpNumber(owner, num--);
		std::string tmp;
		db->get("__warplist__", tmp);
		auto json = nlohmann::json::parse(tmp);
		json.erase(warpname);
		db->set("__warplist__", json.dump());
		return db->del(warpname);
	}

	std::vector<std::string> getWarpList() {
		std::vector<std::string> list;
		std::string tmp;
		db->get("__warplist__", tmp);
		auto json = nlohmann::json::parse(tmp);
		for (auto& [k, v] : json.items()) {
			list.push_back(k);
		}
		return list;
	}
}