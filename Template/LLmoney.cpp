#include "pch.h"
#include "LLmoney.h"
#include <LLMoney.h>
#include <PlayerInfoAPI.h>
#include <MC/Player.hpp>

int LLMoney::getMoney(Player* pl)
{
	std::cout << "getMoney" << std::endl;
	return LLMoneyGet(pl->getXuid());
}

bool LLMoney::addMoney(Player* pl, int num)
{
	return LLMoneyAdd(pl->getXuid(), num);
}

bool LLMoney::reduceMoney(Player* pl, int num)
{
	return LLMoneyReduce(pl->getXuid(), num);
}

bool LLMoney::setMoney(Player* pl, int num)
{
	return LLMoneySet(pl->getXuid(), num);
}

bool LLMoney::transMoney(Player* pla, Player* plb, int num)
{
	return LLMoneyTrans(pla->getXuid(), plb->getXuid(), num);
}
