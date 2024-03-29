#pragma once
#include "cards.h"
#include "includes.h"

class hands: public cards
{
public:
	void showHandOrder();
	std::map<std::string, int> handOrder();
	int calculateHandValue(std::string handString);
	std::string compareHands(std::vector<std::string> handStrings);
	void enterHands();
	bool validateString(std::string s);
	bool checkDuplicateCards(std::string firstHand, std::string secondHand);
private:
	std::string firstHandString;
	std::string secondHandString;
	std::string currentHand;
	std::map<std::string, int> HandOrder;
	int handValue;
	std::vector<int> handNumValue;
};