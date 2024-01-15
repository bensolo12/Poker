#include "cards.h"
#include <map>

std::vector<std::string> cards::checkValues(std::vector<int> values)
{
	handType.clear();
	if (values[0] == 10 && values[0] + 1 == values[1] && values[1] + 1 == values[2] && values[2] + 1 == values[3] && values[3] + 1 == values[4])
	{
		handType.push_back("Royal");
	}
	else if (values[0] + 1 == values[1] && values[1] + 1 == values[2] && values[2] + 1 == values[3] && values[3] + 1 == values[4])
	{
		handType.push_back("Straight");
	}		
	std::map<int, int> duplicate;

	auto beg = begin(values) + 1;
	for (; beg != end(values); ++beg) {
		if (*beg == *(beg - 1)) {
			duplicate[*beg]++;
		}
	}
	for (const auto& i : duplicate) {		
		if (i.second + 1 == 2)
		{
			handType.push_back("OnePair");
		}
		else if (i.second + 1 == 3)
		{
			handType.push_back("ThreeOfAKind");
		}
		else if (i.second + 1 == 4)
		{
			handType.push_back("FourOfAKind");
		}		
	}
	if (handType.size() > 1)
	{		
		if (handType[0] == "OnePair" && handType[1] == "ThreeOfAKind" || handType[1] == "OnePair" && handType[0] == "ThreeOfAKind")
		{
			handType.clear();
			handType.push_back("FullHouse");
		}
		if (handType[0] == "OnePair" && handType[1] == "OnePair")
		{
			handType.clear();
			handType.push_back("TwoPair");
		}
	}
	
	return handType;
}

std::vector<std::string> cards::checkSuits(std::vector<std::string> values)
{
	if (values[0] == "Diamonds" && values[1] == "Diamonds"&& values[2] == "Diamonds"&& values[3] == "Diamonds"&& values[4] == "Diamonds")
	{
		handType.push_back("Flush");
	}
	else if (values[0] == "Spades" && values[1] == "Spades" && values[2] == "Spades" && values[3] == "Spades" && values[4] == "Spades")
	{
		handType.push_back("Flush");
	}
	else if (values[0] == "Clubs" && values[1] == "Clubs" && values[2] == "Clubs" && values[3] == "Clubs" && values[4] == "Clubs")
	{
		handType.push_back("Flush");
	}
	else if (values[0] == "Hearts" && values[1] == "Hearts" && values[2] == "Hearts" && values[3] == "Hearts" && values[4] == "Hearts")
	{
		handType.push_back("Flush");
	}	
	return handType;
}



std::vector<std::string> cards::convertHand(std::string handString)
{
	std::vector<int> allValues;
	std::vector<std::string> allSuits;
	std::string currentCard;
	currentHand = getCards(handString);
	handValue = 0;
	for (size_t i = 0; i < currentHand.size(); i++)
	{
		currentValue = 0;
		currentCard = currentHand[i].substr();
		if (currentCard[0] == 'H')
		{
			currentSuit = "Hearts";
		}
		else if (currentCard[0] == 'C')
		{
			currentSuit = "Clubs";
		}
		else if (currentCard[0] == 'S')
		{
			currentSuit = "Spades";
		}
		else if (currentCard[0] == 'D')
		{
			currentSuit = "Diamonds";
		}
		if (currentCard[1] == '1' && currentCard[2] == '0')
		{
			currentValue = std::stoi("10");
			allValues.push_back(currentValue);
		}
		else if (currentCard[1] == 'J')
		{
			currentValue = std::stoi("11");
			allValues.push_back(currentValue);
		}
		else if (currentCard[1] == 'Q')
		{
			currentValue = std::stoi("12");
			allValues.push_back(currentValue);
		}
		else if (currentCard[1] == 'K')
		{
			currentValue = std::stoi("13");
			allValues.push_back(currentValue);
		}
		else if (currentCard[1] == 'A')
		{
			currentValue = std::stoi("14");
			allValues.push_back(currentValue);
		}
		else
		{
			std::string s;
			s.push_back(currentCard[1]);
			currentValue = stoi(s);
			allValues.push_back(currentValue);
		}
		handValue += currentValue;		
		allSuits.push_back(currentSuit);
	}
	std::sort(allValues.begin(), allValues.end());
	std::vector<std::string> val = checkValues(allValues);
	std::vector<std::string> suiteVal = checkSuits(allSuits);
	fullHand.clear();
	if (val.size() == 0 && suiteVal.size() == 0)
	{
		fullHand.push_back("HighCard");
	}
	if (val != suiteVal)
	{
		std::string s = checkValues(allValues)[0];
		std::string s2 = checkSuits(allSuits)[1];
		fullHand.push_back(s);
		fullHand.push_back(s2);
	}
	else if (allSuits.size() == 0)
	{
		fullHand = checkSuits(allSuits);
	}
	else if (allValues.size() == 0)
	{
		fullHand = checkValues(allValues);
	}
	else if (val == suiteVal)
	{
		fullHand = val;
	}
	allValues.clear();
	allSuits.clear();
	return fullHand;
}

std::vector<std::string> cards::getCards(std::string handString)
{
	std::vector<std::string> currentHand;
	std::string delimiter = " ";

	size_t pos = 0;
	std::string token;
	while ((pos = handString.find(delimiter))!= std::string::npos)
	{
		token = handString.substr(0, pos);
		currentHand.push_back(token);
		handString.erase(0, pos + delimiter.length());
	}
	return std::vector<std::string>(currentHand);
}

std::string cards::getHand(std::string handString)
{
	std::string fullHand;
	std::vector<std::string> temp = convertHand(handString);
	for (size_t i = 0; i < temp.size(); i++)
	{
		fullHand += temp[i];
	}
	return fullHand;
}

void cards::drawCards()
{
	std::string genCards;
	for (size_t i = 0; i < 2; i++)
	{
		srand(time(0));
		char letters[] = "hcsd";
		char suit = letters[rand() % 26];
		genCards.push_back(suit);

		srand(time(0));		
		for (int i = 0; i < 10; i++) {
			char val = (rand() % 10) + 1;
			genCards.push_back(val);
		}
		genCards.push_back(' ');
	}	
}

int cards::getHandValue()
{
	return handValue;
}
