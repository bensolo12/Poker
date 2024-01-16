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

	d.dealCards(2);
	std::cout << "Dealing... " << std::endl << d.getDealtCards() << std::endl;
}
