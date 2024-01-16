#pragma once
#include "Player.h"

class Dealer: public Player
{
public:
	std::vector<std::string> dealCards(int cardsToDeal);
	std::string getDealtCards();
	Dealer();
private:
	std::vector<std::string> dealtCards;
};

