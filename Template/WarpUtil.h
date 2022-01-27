#pragma once
#include <LoggerAPI.h>
#include "Config.hpp"

class Pos4 {
public:
	int x, y, z, dim;
};

namespace WarpUtil {
	Config loadConfig();
	void initDB();
	int distanceBetTwoPoints(Pos4 a, Pos4 b);
	bool hasWarp(std::string warpname);
	std::string getWarpOwner(std::string warpname);
	Pos4 getWarpPos(std::string warpname);
	bool createWarp(std::string warpname, std::string owner, Pos4 pos);
	int getPlayerWarpNumber(std::string pl);
	void setPlayerWarpNumber(std::string pl, int num);
	bool delWarp(std::string warpname);
	std::vector<std::string> getWarpList();
}