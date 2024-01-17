#pragma once
#include "includes.h"
class Player
{
public:
	std::string getPlayerCards();
	std::string dealCards();
	Player(std::string playerName, int playerNum);
	Player();
	bool playHand();
private:
	std::string playerName;
	int playerNum;
	std::string playerCards;
};

