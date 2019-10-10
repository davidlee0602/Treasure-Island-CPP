/*********************************************************************
** Program name: Game.hpp
** Author: David Lee
** Date: 06/08/2019
** Description: Header file for Game class. Data members contain 6 Space pointers and 1 Character pointer.
 * It creates the link between 6 spaces for character object to navigate through and interact.
 * The Game class is the control class for the game, Island Escape!
*********************************************************************/

#ifndef GAME_HPP
#define GAME_HPP
#include "Space.hpp"
#include <string>
using std::string;

class Game {
private:
    Space* area1; //location one to store space
    Space* area2; //location two to store space
    Space* area3; //location three to store space
    Space* area4; //location four to store space
    Space* area5; //location five to store space
    Space* area6; //location six to store space
    Character* character;
public:
    enum class Move{UP = 1, RIGHT = 2, LEFT = 3, DOWN = 4}; //enum types used for character movement
    Game(); //constructor
    ~Game(); //destructor
    void deallocate(); //de-allocates and deletes objects
    void setMap(); //initializes unique spaces for character to move through
    void setGrid(); //sets links between 6 spaces (top, right, left, bottom)
    void printGrid(); //prints game map
    void movement(); //takes user instruction and moves character through spaces
    void moveCharacter(Space* room, Move direction); //character movement through changing set_character_active mutator
    Space* findCharacterPosition(); //finds which space character is active on and returns location
    int inputValidation(string message, int min, int max); //re-usable input validation function that takes integers only
    void identifyTerrain(); //identify the type of derived object stores in area / space pointer
    void observeTerrain(); //function for character interaction with space
    void option(); //character actions selectable by user
    void play(); //driver function for the game
    void menu(); //game menu function - allows re-play and de-allocates objects


};


#endif
