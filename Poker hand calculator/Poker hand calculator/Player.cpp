#include "Player.h"

std::string Player::getPlayerCards()
{
	return playerCards;
}

std::string Player::dealCards()
{
	char suit[] = { 'H','C','S','D' };
	char val[] = { '2', '3', '4', '5', '6', '7', '8', '9', '10', 'J', 'Q', 'K', 'A' };
	std::random_device random;
	std::mt19937 generator(random());
	for (size_t i = 0; i <= 2; i++)
	{
		std::shuffle(std::begin(suit), std::end(suit), generator);
		std::shuffle(std::begin(val), std::end(val), generator);
		playerCards.push_back(suit[0]);
		if (val[0] == 0)
		{
			playerCards.push_back(10);
		}
		else
		{
			playerCards.push_back(val[0]);
		}		
		playerCards.push_back(' ');
	}
	return playerCards;
}

Player::Player(std::string playerName, int playerNum)
{
}

Player::Player()
{
}

bool Player::playHand()
{
	std::cout << "Would you like to play, or fold? " << std::endl;
	std::string c;
	std::getline(std::cin, c);
	if (c == "play")
	{
		return true;
	}
	return false;
}
