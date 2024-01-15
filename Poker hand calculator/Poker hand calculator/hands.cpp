#include "hands.h"

void hands::showHandOrder()
{
	HandOrder = handOrder();
	std::map<std::string, int>::iterator it = HandOrder.begin();
	while (it != HandOrder.end())
	{
		std::cout << it->first << ", ";
		++it;
	}
	std::cout << std::endl;
}

std::map<std::string, int> hands::handOrder()
{
	std::map<std::string, int> handOrders;
	handOrders["HighCard"] = 1;
	handOrders["OnePair"] = 2;
	handOrders["TwoPair"] = 3;
	handOrders["ThreeOfAKind"] = 4;
	handOrders["Straight"] = 5;
	handOrders["Flush"] = 6;
	handOrders["FullHouse"] = 7;
	handOrders["FourOfAKind"] = 8;
	handOrders["StraightFlush"] = 9;
	handOrders["RoyalFlush"] = 10;
	return handOrders;
}



int hands::calculateHandValue(std::string handString)
{		
	currentHand = getHand(handString);
	handNumValue.push_back(getHandValue());
	std::cout << "current hand: " << currentHand << std::endl;
	HandOrder = handOrder();
	std::map<std::string, int>::iterator it = HandOrder.begin();
	if (HandOrder.find(currentHand) != HandOrder.end())
	{
		handValue = HandOrder[currentHand];
	}
	return handValue;
}

std::string hands::compareHands(std::vector<std::string> handStrings)
{
	std::string winner;
	int firstVal = calculateHandValue(handStrings[0]);
	int secondVal = calculateHandValue(handStrings[1]);
	if (firstVal > secondVal)
	{
		winner = "First hand is better!";
	}
	else if (secondVal > firstVal)
	{
		winner = "Second hand is better!";
	}
	else if( firstVal == secondVal)
	{
		if (handNumValue[0] > handNumValue[1])
		{
			winner = "First hand is better!";
		}
		else if (handNumValue[1] > handNumValue[0])
		{
			winner = "Second hand is better!";
		}
		else
		{
			winner = "Both hands are the same!";
		}		
	}
	else
	{
		
	}
	return winner;
}

void hands::enterHands()
{
	bool valid1 = false;
	bool valid2 = false;
	std::vector<std::string> handStrings;

	while (valid1 == false)
	{
		std::cout << "Enter your first hand in the form [Suit][Value] X5 e.g. HA CQ S6 D6 H6" << std::endl;
		std::cin.ignore();
		std::getline(std::cin, firstHandString);
		firstHandString += " ";
		valid1 = validateString(firstHandString);		
	}	
	handStrings.push_back(firstHandString);	

	while (valid2 == false)
	{
		std::cout << "Enter your second hand in the form [Suit][Value] X5 e.g. HA CQ S6 D6 H6" << std::endl;
		std::getline(std::cin, secondHandString);
		secondHandString += " ";
		valid2 = validateString(secondHandString);
	}
	handStrings.push_back(secondHandString);
	if (checkDuplicateCards(firstHandString, secondHandString) == true)
	{
		std::string winner = compareHands(handStrings);
		std::cout << winner << std::endl;
	}
	else
	{
		std::cout << "Hands contain duplicate values, please re-enter" << std::endl;
		enterHands();
	}
	
}

bool hands::validateString(std::string s) 
{

	std::vector<char> suitCheck;
	std::vector<char> valCheck;
	//Each substring must contain first char [H, C, S, D] second char [2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K, A]
	std::vector<std::string> v = getCards(s);
	for (size_t i = 0; i < v.size(); i++)
	{
		std::string currentCard = v[i];
		suitCheck.push_back(currentCard[0]);
		valCheck.push_back(currentCard[1]);
	}
	std::vector<char> needed = { 'H', 'C', 'S', 'D' };
	std::vector<char> neededNum = { '1','2','3','4','5','6','7','8','9','J','Q','K','A'};
	for (auto a_elt : suitCheck) {
		if (std::find(needed.begin(), needed.end(), a_elt) == needed.end()) {
			std::cout << "Invalid string, please try again" << std::endl;
			return false;
		}
	}
	for (auto a_elt : valCheck) {
		if (std::find(neededNum.begin(), neededNum.end(), a_elt) == neededNum.end()) {
			std::cout << "Invalid string, please try again" << std::endl;
			return false;
		}
	}
	
	return true;
}

bool hands::checkDuplicateCards(std::string firstHand, std::string secondHand)
{
	std::vector<std::string> firstHandCards = getCards(firstHandString);
	std::vector<std::string> secondHandCards = getCards(secondHandString);

	for (auto a_elt : firstHandCards) {
		if (std::find(secondHandCards.begin(), secondHandCards.end(), a_elt) == secondHandCards.end()) {
			return false;
		}
	}
	return true;
}
