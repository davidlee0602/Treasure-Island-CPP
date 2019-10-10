/*********************************************************************
** Program name: main.cpp
** Author: David Lee
** Date: 06/08/2019
** Description: Entry point for final project game - Island Escape!
 * Initializes Game class object and invokes menu() member function
 * to run the game.
*********************************************************************/

#include <iostream>
#include "Game.hpp"
#include "Character.hpp"

int main() {
    Game game; //initializes game object
    game.menu(); //invoke menu member function from Game class

    return 0;
}