#pragma once
#include "includes.h"
#include "Dealer.h"
#include "hands.h"
class game
{
public:
	void playGame();
	std::string getAllCards(std::string playerCards, std::string dealerCards);
private:
	std::string allCards;
};

