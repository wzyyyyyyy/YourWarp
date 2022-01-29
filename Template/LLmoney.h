#pragma once
#include "Money.h"
class LLMoney :public Money {
public:
	virtual int getMoney(Player* pl);
	virtual bool addMoney(Player* pl, int num);
	virtual bool reduceMoney(Player* pl, int num);
	virtual bool setMoney(Player* pl, int num);
	virtual bool transMoney(Player* pla, Player* plb, int num);
};