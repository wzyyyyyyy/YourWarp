#pragma once
class Player;

class Money {
public:
	virtual int getMoney(Player* pl) = 0;
	virtual bool addMoney(Player* pl, int num) = 0;
	virtual bool reduceMoney(Player* pl, int num) = 0;
	virtual bool setMoney(Player* pl, int num) = 0;
	virtual bool transMoney(Player* pla, Player* plb, int num) = 0;
};