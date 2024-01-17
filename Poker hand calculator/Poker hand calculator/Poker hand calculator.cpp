#include "hands.h"
#include "game.h"

void menu() {
    int menuOption;
    std::cout << "1. View hand order 2. Calculate Hand 3. Play Game 0. Exit" << std::endl ;
    std::cin >> menuOption;
    hands h;
    game g;
    switch (menuOption)
    {
    case 1: 
    {
        h.showHandOrder();
        menu();
    }        
    case 2: 
    {
        h.enterHands();
        menu();
    }
    case 3:
        g.playGame();
    case 0:
        break;
    default:
        std::cout << "Invalid option";
        menu();
    }
}
int main()
{
    std::cout << "Hello, welcome to poker, what would you like to do?" << std::endl;
    menu();
}