#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
class cards
{
public:
	std::vector<std::string> checkValues(std::vector<int> values);
	std::vector<std::string> checkSuits(std::vector<std::string> values);
	std::vector<std::string> convertHand(std::string handString);
	std::vector<std::string> getCards(std::string handString);
	std::string getHand(std::string handString);
	int getHandValue();
	
private:
	std::vector<std::string> allSuits;	
	std::vector<std::string> currentHand;
	std::string currentSuit;
	int currentValue;
	int handValue = 0;
	std::vector<std::string> handType;
	std::vector<std::string> fullHand;
};