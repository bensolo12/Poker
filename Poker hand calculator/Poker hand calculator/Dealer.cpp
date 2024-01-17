#include "Dealer.h"

std::vector<std::string> Dealer::dealCards(int cardsToDeal)
{
	std::string suit[] = { "H","C","S","D" };
	std::string val[] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
	std::random_device random;
	std::mt19937 generator(random());
	for (size_t i = 0; i <= cardsToDeal - 1; i++)
	{
		std::shuffle(std::begin(suit), std::end(suit), generator);
		std::shuffle(std::begin(val), std::end(val), generator);
		dealtCards.push_back(suit[0]);
		if (val[0] == "0")
		{
			dealtCards.push_back("10");
		}
		else
		{
			dealtCards.push_back(val[0]);
		}
		dealtCards.push_back(" ");
	}
	return dealtCards;
}

std::string Dealer::getDealtCards()
{
	std::string cardsToReturn;
	cardsToReturn = std::accumulate(begin(dealtCards), end(dealtCards), std::string{});
	//std::cout << cardsToReturn;
	return cardsToReturn;
}

Dealer::Dealer()
{
}
