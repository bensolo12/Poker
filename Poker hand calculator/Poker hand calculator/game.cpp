#include "game.h"



void game::playGame()
{
	std::string playerName;
	std::cout << "Enter your name" << std::endl;
	std::cin.ignore();
	std::getline(std::cin, playerName);
	Player p1 = Player(playerName, 1);

	Dealer d;
	/*std::cout << "Player 2, enter your name" << std::endl;
	std::cin.ignore();
	std::getline(std::cin, playerName);
	Player p2 = Player(playerName, 1);*/

	p1.dealCards();
	std::cout << "Your cards are: " << p1.getPlayerCards() << std::endl;
	size_t c = 3;
	size_t c2 = 0;
	while (p1.playHand() && c2 < 3)
	{
		if (c == 3)
		{
			d.dealCards(c);
			std::cout << "Dealing... " << std::endl << d.getDealtCards() << std::endl;
			c = 1;
			c2++;
		}
		else
		{
			d.dealCards(c);
			std::cout << "Dealing... " << std::endl << d.getDealtCards() << std::endl;
			c2++;
		}
	}
	allCards = getAllCards(p1.getPlayerCards(), d.getDealtCards());
	hands h;
	h.calculateHandValue(allCards);

	std::cout << "You folded, play again? (y/n)";
}

std::string game::getAllCards(std::string playerCards, std::string dealerCards)
{
	allCards = playerCards + dealerCards;
	return allCards;
}


