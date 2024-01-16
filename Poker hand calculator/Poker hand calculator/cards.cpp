#include "cards.h"
#include <map>
#include <random>

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

	int occur;
	for (const int target: {2, 3, 4, 5, 6, 7, 8, 9, 10 ,11 ,12 ,13,14})
	{
		occur = std::count(begin(values), end(values), target);
		if (occur == 2)
		{
			if (handType.empty() == false)
			{
				if (handType.back() == "OnePair")
				{
					handType.clear();
					handType.push_back("TwoPair");
				}

				if (handType.back() == "ThreeOfAKind")
				{
					handType.clear();
					handType.push_back("FullHouse");
				}
			}
			
			else
			{
				handType.push_back("OnePair");
			}			
		}
		else if(occur == 3)
		{
			if (handType.empty() == false)
			{
				if (handType.back() == "OnePair")
				{
					handType.clear();
					handType.push_back("FullHouse");
				}
			}			
			else
			{
				handType.push_back("ThreeOfAKind");
			}			
		}
		else if (occur == 4)
		{
			handType.push_back("FourOfAKind");
		}
	}
	if (handType.empty())
	{
		handType.push_back("");
	}
	
	return handType;
}

std::vector<std::string> cards::checkSuits(std::vector<std::string> values)
{
	if (std::all_of(begin(values), end(values), [](auto val) {return val == "Diamonds"; }))
	{
		handType.push_back("Flush");
	}
	else if (std::all_of(begin(values), end(values), [](auto val) {return val == "Hearts"; }))
	{
		handType.push_back("Flush");
	}
	else if (std::all_of(begin(values), end(values), [](auto val) {return val == "Spades"; }))
	{
		handType.push_back("Flush");
	}
	else if (std::all_of(begin(values), end(values), [](auto val) {return val == "Clubs"; }))
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
	if (val.empty() && suiteVal.empty() || val.back() == "")
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
	else if (val == suiteVal && fullHand.back() != "HighCard")
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
	std::string hand;
	char suit[] = { 'H','C','S','D' };
	char val[] = { '2', '3', '4', '5', '6', '7', '8', '9', '10', '11', '12', '13', '14'};
	std::random_device random;
	std::mt19937 generator(random());
	for (size_t i = 0; i <= 3; i++)
	{
		std::shuffle(std::begin(suit), std::end(suit), generator);
		std::shuffle(std::begin(val), std::end(val), generator);
		hand.push_back(suit[0]);
		hand.push_back(val[0]);
		hand.push_back(' ');
	}
	
}

int cards::getHandValue()
{
	return handValue;
}
