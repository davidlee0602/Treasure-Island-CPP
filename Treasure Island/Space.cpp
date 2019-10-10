/*********************************************************************
** Program name: Space.cpp
** Author: David Lee
** Date: 06/08/2019
** Description: Implementation - Base class for Dirt, Grass, Sand, Special class. Has 4 space pointers to store addresses
 * to other spaces - linked structure. Has data member to identify space type and if character is positioned in current space.
 * As an abstract class, has virtual functions (polymorphism) for accessor, mutator member functions.
 * The dig function is a pure virtual function which gets overridden by dig functions from derived classes.
*********************************************************************/

#include "Space.hpp"
#include <random>
#include "Character.hpp"
#include <iostream>
#include <random>
#include <ctime>
using std::srand;
using std::rand;
using std::cout;
using std::rand;
using std::endl;

Space::Space(){ //constructor
    top = nullptr;
    right = nullptr;
    left = nullptr;
    bottom = nullptr;
    active_character = false;
    type = "";
}

Space::~Space(){ //destructor

}

Space::Space(Space* top, Space* right, Space* left, Space* bottom, bool active_character, string type){ //constructor with parameters to initialize data member
    this->top = top;
    this->right = right;
    this->left = left;
    this->bottom = bottom;
    this->active_character = active_character;
    this->type = type;
}

//accessor
Space* Space::get_top(){ //returns address of top space
    return top;
}

Space* Space::get_right(){ //returns address of right space
    return right;
}

Space* Space::get_left(){ //returns address of left space
    return left;
}

Space* Space::get_bottom(){ //returns address of bottom space
    return bottom;
}

bool Space::get_character_active(){ //returns true if character exists in space
    return active_character;
}

string Space::get_type(){ //returns type of space
    return type;
}
//mutator
void Space::set_top(Space* top){ //mutator for top space pointer
    this->top = top;
}

void Space::set_right(Space* right){ //mutator for right space pointer
    this->right = right;
}

void Space::set_left(Space* left){ //mutator for left space pointer
    this->left = left;
}

void Space::set_bottom(Space* bottom){ //mutator for bottom space pointer
    this->bottom = bottom;
}

void Space::set_character_active(bool active_character) { //mutator to indicate if character exists in space
    this->active_character = active_character;
}

//game function
void Space::dig(Character*& character){ //pure virtual function //character digs for items
    int chance = rand() % 3 + 1;
    if(chance == 3){
        character->addItem(0);
    }else{ //character loses life if item is not found
        character->set_life(character->get_life() - 20);
        cout << "You found nothing! You hurt yourself while digging and take 20 damage."  << endl;
    }
}

