#pragma once
#include "Money.h"
#include <string>
class Player;

class ScoreBoardMoney :public Money {
	std::string name;
public:
	ScoreBoardMoney(std::string scoreboardname);
	virtual int getMoney(Player* pl);
	virtual bool addMoney(Player* pl, int num);
	virtual bool reduceMoney(Player* pl, int num);
	virtual bool setMoney(Player* pl, int num);
	virtual bool transMoney(Player* pla, Player* plb, int num);
};