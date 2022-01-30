#include "pch.h"
#include "ScoreBoardMoney.h"
#include <MC/Player.hpp>
#include <MC/Scoreboard.hpp>

ScoreBoardMoney::ScoreBoardMoney(std::string scoreboardname)
{
	this->name = scoreboardname;
}

int ScoreBoardMoney::getMoney(Player* pl)
{
	return Scoreboard::getScore(pl, name);
}

bool ScoreBoardMoney::addMoney(Player* pl, int num)
{
	return Scoreboard::addScore(pl, name, num);
}

bool ScoreBoardMoney::reduceMoney(Player* pl, int num)
{
	return Scoreboard::reduceScore(pl, name, num);
}

bool ScoreBoardMoney::setMoney(Player* pl, int num)
{
	return Scoreboard::setScore(pl, name, num);
}

bool ScoreBoardMoney::transMoney(Player* pla, Player* plb, int num)
{
	auto score = pla->getScore(name);
	if (score >= num) {
		return pla->reduceScore(name, num) && plb->addScore(name, num);
	}
	return false;
}
