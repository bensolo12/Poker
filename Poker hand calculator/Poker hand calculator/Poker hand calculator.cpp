// Poker hand calculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "hands.h"
#include "cards.h"

void menu() {
    int menuOption;
    std::cout << "1. View hand order 2. Calculate Hand 0. Exit" << std::endl ;
    std::cin >> menuOption;
    hands h;
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
    case 0:
        break;
    default:
        std::cout << "Invalid option";
        menu();
    }
}
int main()
{
    std::cout << "Hello, welcome to the poker hand calculator, what would you like to do?" << std::endl;
    menu();
}