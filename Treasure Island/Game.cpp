/*********************************************************************
** Program name: Game.cpp
** Author: David Lee
** Date: 06/08/2019
** Description: Implementation file for Game class. Data members contain 6 Space pointers and 1 Character pointer.
 * It creates the link between 6 spaces for character object to navigate through and interact.
 * The Game class is the control class for the game, Island Escape!
*********************************************************************/

#include "Game.hpp"
#include "Dirt.hpp"
#include "Grass.hpp"
#include "Sand.hpp"
#include "Special.hpp"
#include "Character.hpp"
#include <ctime>
#include <iostream>
#include <sstream>
using std::cin;
using std::stringstream;

Game::Game(){ //constructor
    srand(time(0)); //seed for all random functions
    area1 = nullptr;
    area2 = nullptr;
    area3 = nullptr;
    area4 = nullptr;
    area5 = nullptr;
    area6 = nullptr;
    character = nullptr;
}

Game::~Game(){ //destructor

}

void Game::deallocate(){ //de-allocates and deletes objects - Prevent memory leaks
    delete area1;
    delete area2;
    delete area3;
    delete area4;
    delete area5;
    delete area6;
    delete character;

    area1 = nullptr;
    area2 = nullptr;
    area3 = nullptr;
    area4 = nullptr;
    area5 = nullptr;
    area6 = nullptr;
    character = nullptr;
}

void Game::setMap(){ //initializes unique spaces for character to move through
    area1 = new Dirt(); //area1 pointer to Dirt object
    area2 = new Grass(); //area2 pointer to Grass object
    area3 = new Dirt(); //area3 pointer to Dirt object
    area4 = new Grass(); //area4 pointer to Grass object
    area5 = new Sand(); //area5 pointer to Sand object
    area6 = new Special(); //area6 pointer to Special object
}

void Game::setGrid() { //sets links between 6 spaces (top, right, left, bottom)
    //area1 pointers to other areas
    area1->set_top(nullptr);
    area1->set_right(area2);
    area1->set_left(nullptr);
    area1->set_bottom(area4);
    //area2 pointers to other areas
    area2->set_top(nullptr);
    area2->set_right(area3);
    area2->set_left(area1);
    area2->set_bottom(area5);
    //area3 pointers to other areas
    area3->set_top(nullptr);
    area3->set_right(nullptr);
    area3->set_left(area2);
    area3->set_bottom(area6);
    //area4 pointers to other areas
    area4->set_top(area1);
    area4->set_right(area5);
    area4->set_left(nullptr);
    area4->set_bottom(nullptr);
    //area5 pointers to other areas
    area5->set_top(area2);
    area5->set_right(area6);
    area5->set_left(area4);
    area5->set_bottom(nullptr);
    //area6 pointers to other areas
    area6->set_top(area3);
    area6->set_right(nullptr);
    area6->set_left(area5);
    area6->set_bottom(nullptr);
    //sets character start position at area1
    area1->set_character_active(true);
}

void Game::printGrid(){ //prints game map
    Space* top_row = area1; //first row - top row
    Space* bot_row = area4; //second row - bottom row
    cout << "MAP: " << endl;
    while(top_row != nullptr){
        if(top_row->get_character_active() == true){
            cout << '*';
        }else{
            cout << '#';
        }
        top_row = top_row->get_right();
        cout << ' ';
    }
    cout << endl;
    while(bot_row != nullptr){
        if(bot_row->get_character_active() == true){
            cout << '*'; //indicate character location
        }else{
            cout << '#'; //empty space
        }
        bot_row = bot_row->get_right();
        cout << ' ';
    }
    cout << endl;
}

void Game::movement(){ //takes user instruction and moves character through spaces
    int moveDirection = inputValidation("Which direction? \n[1]UP \n[2]RIGHT \n[3]LEFT \n[4]DOWN", 1, 4);
    switch(moveDirection){
        case 1:
            moveCharacter(findCharacterPosition(), Move::UP); //moves character to space above
            break;
        case 2:
            moveCharacter(findCharacterPosition(), Move::RIGHT); //moves character to space to right
            break;
        case 3:
            moveCharacter(findCharacterPosition(), Move::LEFT); //moves character to space to left
            break;
        case 4:
            moveCharacter(findCharacterPosition(), Move::DOWN); //moves character to space below
            break;
        default:
            break;
    }
}

void Game::moveCharacter(Space* room, Move direction){ //character movement through changing set_character_active mutator
    if(direction == Move::UP){ //move to top
        if(room->get_top() == nullptr){
            cout << "Character did not move up. No space above... You wasted time wandering..." << endl;
        }else{
            room->set_character_active(false);
            room->get_top()->set_character_active(true);
            cout << "Character moved up." << endl;
        }
    }else if(direction == Move::RIGHT){ //move to right
        if(room->get_right() == nullptr){
            cout << "Character did not move right. No space to the right... You wasted time wandering..." << endl;
        }else{
            room->set_character_active(false);
            room->get_right()->set_character_active(true);
            cout << "Character moved right." << endl;
        }
    }else if(direction == Move::LEFT){ //move to left
        if(room->get_left() == nullptr){
            cout << "Character did not move left. No space to the left... You wasted time wandering..." << endl;
        }else{
            room->set_character_active(false);
            room->get_left()->set_character_active(true);
            cout << "Character moved left." << endl;
        }
    }else if(direction == Move::DOWN){ //move to bottom
        if(room->get_bottom() == nullptr){
            cout << "Character did not move down. No space below... You wasted time wandering..." << endl;
        }else{
            room->set_character_active(false);
            room->get_bottom()->set_character_active(true);
            cout << "Character moved down." << endl;
        }
    }else{
        cout << "Error" << endl;
    }
    cout << endl;
}

Space* Game::findCharacterPosition() { //finds which space character is active on and returns location
    if(area1->get_character_active()){
        return area1;
    }else if(area2->get_character_active()){
        return area2;
    }else if(area3->get_character_active()){
        return area3;
    }else if(area4->get_character_active()){
        return area4;
    }else if(area5->get_character_active()){
        return area5;
    }else if(area6->get_character_active()){
        return area6;
    }else{
        return nullptr; //error
    }
}

int Game::inputValidation(string message, int min, int max){ //re-usable input validation function that takes integers only
    double input;
    bool repeatEntry = true;
    char errorTest;
    string inputLine;
    while (repeatEntry == true) {
        cout << message << endl;
        getline(cin, inputLine);
        stringstream lineStream(inputLine);
        if (!(lineStream >> input)) {
            cout << "Input was not a number. Please try again." << endl;
        } else if ((input < min) || (input > max)) {
            cout << "Input out of range. Please try again." << endl;
        } else if (input - static_cast<int>(input) != 0) {
            cout << "Input with decimals and not an integer. Please try again." << endl;
        } else if (lineStream >> errorTest) {
            cout << "Input with extra symbols and/or characters. Please try again." << endl;
        } else {
            repeatEntry = false;
            input = input;
            cout << "Input accepted." << endl;
        }
    }
    return input;
}

void Game::identifyTerrain(){ //identify the type of derived object stores in area / space pointer
    if(findCharacterPosition()->get_type() == "Dirt"){
        cout << "Terrain Type: Dirt" << endl;
    }else if(findCharacterPosition()->get_type() == "Grass"){
        cout << "Terrain Type: Grass" << endl;
    }else if(findCharacterPosition()->get_type() == "Sand"){
        cout << "Terrain Type: Sand" << endl;
    }else if(findCharacterPosition()->get_type() == "Special"){
        cout << "Terrain Type: ????" << endl;
    }else{
        cout << "Error" << endl;
    }
}

void Game::observeTerrain(){ //function for character interaction with space
    if(findCharacterPosition()->get_type() == "Dirt"){
        cout << "You see debris from the crash. You might find some food." << endl;
    }else if(findCharacterPosition()->get_type() == "Grass"){
        if (character->get_life() < 100){
            cout << "You gain 1 health from eating grass. It's not nutritious."<< endl;
            character->set_life(character->get_life() + 1);
        }else{
            cout << "You gain 0 health from eating grass. It's not nutritious."<< endl;
        }
    }else if(findCharacterPosition()->get_type() == "Sand"){
        int sandEvent = rand() % 2 + 1;
        if(sandEvent == 2){
            cout << "PIRATES caught you and steal your items." << endl;
            character->clearItemBag();
        }else{
            cout << "You hear nothing back..." << endl;
        }
    }else if(findCharacterPosition()->get_type() == "Special"){
        cout << "You see a shiny object in the ground..." << endl;
    }else{
        cout << "Error" << endl;
    }
}

void Game::option(){ //character actions selectable by user
    cout << endl; //unique interactions with space
    if (findCharacterPosition()->get_type() == "Dirt"){
        cout << "Choose an action: \n[1]Walk Around... \n[2]Dig \n[3]View ItemBag \n[4]Use Item \n[5]Move" << endl;
    }else if (findCharacterPosition()->get_type() == "Grass"){
        cout << "Choose an action: \n[1]Eat Grass \n[2]Dig \n[3]View ItemBag \n[4]Use Item \n[5]Move" << endl;
    }else if (findCharacterPosition()->get_type() == "Sand"){
        cout << "Choose an action: \n[1]Yell for HELP!!! \n[2]Dig \n[3]View ItemBag \n[4]Use Item \n[5]Move" << endl;
    }else if (findCharacterPosition()->get_type() == "Special"){
        cout << "Choose an action: \n[1]Observe \n[2]Dig \n[3]View ItemBag \n[4]Use Item \n[5]Move" << endl;
    }else{
        cout << "Error" << endl;
    }
    int playerOption = inputValidation("ENTER a number from 1 through 5:", 1, 5); //shows result of user selected action
    cout << "------------------Action Result:------------------" << endl;
    switch(playerOption){
        case 1:
            observeTerrain(); //interact with space
            break;
        case 2:
            findCharacterPosition()->dig(character); //dig from space
            break;
        case 3:
            character->printItemBag(); //print character item bag
            break;
        case 4:
            character->useItem(); //uses item from item bag
            break;
        case 5:
            movement(); //move character
            break;
        default:
            break;
    }
}

void Game::play(){ //driver function for the game
    setMap(); //initialize spaces
    setGrid(); //sets links between spaces
    character = new Character; //initialize character object
    int day = 0;
    cout << "==================================================" << endl;
    cout << "================= ISLAND ESCAPE! =================" << endl;
    cout << "==================================================" << endl;
    cout << "                    _                         " << endl; //ascii image source: http://www.asciiworld.com/-Islands-.html
    cout << "                   /_'. _                     " << endl;
    cout << "                 _   | / '-.                  " << endl;
    cout << "                < ``-.;),--'`                 " << endl;
    cout << "                 '--.</()`--.                 " << endl;
    cout << "                   / |/-/`'._|                " << endl;
    cout << "                   |/ |=|                     " << endl;
    cout << "                      |_|                     " << endl;
    cout << "                 ~`   |-| ~~      ~           " << endl;
    cout << "             ~~  ~~ __|=|__   ~~              " << endl;
    cout << "           ~~   .-'`  |_|  ``""-._   ~~       " << endl;
    cout << "            ~~.'      |=|         '-.  ~      " << endl;
    cout << "              |                      |   ~    " << endl;
    cout << "          ~   |                      | ~~     " << endl;
    cout << "               '-.__.--._         .-'         " << endl;
    cout << "                    ~~   `--...-'`    ~~      " << endl;
    cout << "            ~~         ~          ~           " << endl;
    cout << "                   ~~         ~~     ~        " << endl;
    cout << "Your name is ... You remember taking an airplane... You wake up on an island." << endl;
    cout << "You see debris all around. You are the only survivor. You don't know where you are." << endl;
    cout << "Will you survive? [You have 14 days to live]" << endl;

    while(character->get_life() > 0 && day < 14 && character->get_win() == false){ //game end conditions
        cout << "**************************************************" << endl;
        cout << "[Day #" << ++day << "]" << endl;
        cout << "Character Life: " << character->get_life() << endl;
        cout << endl;
        printGrid(); //prints game map
        identifyTerrain(); //shows type of space the character is active in
        option(); //displays interactions selectable by user
        cout << "**************************************************" << endl;
    }
    cout << "**********************Result**********************" << endl; //end game results
    if (character->get_life() <= 0){ //game ends when life reaches 0
        cout << "You died from injury... RIP..." << endl;
        cout << "        _.---,._,'                             " << endl; //ascii image source: http://rip.ascii.uk/
        cout << "       /' _.--.<                               " << endl;
        cout << "         /'     `'                             " << endl;
        cout << "       /' _.---._____                          " << endl;
        cout << "       /.'   ___, .-'`                         " << endl;
        cout << "           /'                   .              " << endl;
        cout << "         /'                    -|-             " << endl;
        cout << "        |                       |              " << endl;
        cout << "        |                   .-'~~~`-.          " << endl;
        cout << "        |                 .'         `.        " << endl;
        cout << "        |                 |  R  I  P  |        " << endl;
        cout << "        |                 |           |        " << endl;
        cout << "        |                 |           |        " << endl;
        cout << "        |                 |           |        " << endl;
        cout << "   ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
    }else if(day >= 10){ //game ends when user makes 14 interactions
        cout << "You died from starvation... RIP..." << endl;
        cout << "        _.---,._,'                             " << endl; //ascii image source: http://rip.ascii.uk/
        cout << "       /' _.--.<                               " << endl;
        cout << "         /'     `'                             " << endl;
        cout << "       /' _.---._____                          " << endl;
        cout << "       /.'   ___, .-'`                         " << endl;
        cout << "           /'                   .              " << endl;
        cout << "         /'                    -|-             " << endl;
        cout << "        |                       |              " << endl;
        cout << "        |                   .-'~~~`-.          " << endl;
        cout << "        |                 .'         `.        " << endl;
        cout << "        |                 |  R  I  P  |        " << endl;
        cout << "        |                 |           |        " << endl;
        cout << "        |                 |           |        " << endl;
        cout << "        |                 |           |        " << endl;
        cout << "   ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
    }else if(character->get_win() == true){ //game ends when character finds telephone and uses it - win condition
        cout << "You were saved! You got back home safely! WIN!!!!" << endl; //ascii image source: http://www.asciiworld.com/-Boats-.html
        cout << "                 _._		  				     "<< endl;
        cout << "                  :.                            "<< endl;
        cout << "                  : :                           "<< endl;
        cout << "                  :  .                          "<< endl;
        cout << "                 .:   :                         "<< endl;
        cout << "                : :    .                        "<< endl;
        cout << "               :  :     :                       "<< endl;
        cout << "              .   :      .                      "<< endl;
        cout << "             :    :       :                     "<< endl;
        cout << "            :     :        .                    "<< endl;
        cout << "           .      :         :                   "<< endl;
        cout << "          :       :          .                  "<< endl;
        cout << "         :        :           :                 "<< endl;
        cout << "        .=w=w=w=w=:            .                "<< endl;
        cout << "                  :=w=w=w=w=w=w=.   ....        "<< endl;
        cout << "   <--.___________________________.:---/        "<< endl;
        cout << "    |      ____===================____/         "<< endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
    }
    cout << "**************************************************" << endl;
}

void Game::menu(){ //game menu function - allows re-play and de-allocates objects
    bool playGame = true;
    while(playGame){
        int playInput = inputValidation("Welcome to ISLAND ESCAPE. Would you like to play the game?\nPress 1 for YES. Press 2 for NO.", 1, 2);
        if(playInput == 1){
            play(); //driver function
            deallocate(); //deletes objects to reset game and to prevent memory leaks
        }else{
            playGame = false;
            cout << "Program ended." << endl;
        }
    }
}

