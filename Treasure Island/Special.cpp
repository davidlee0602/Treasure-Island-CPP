/*********************************************************************
** Program name: Special.cpp
** Author: David Lee
** Date: 06/08/2019
** Description: Implementation - Derived class from Space class. Special class has member function dig that overrides
 * pure virtual function dig() from Space class. Digging from Special gives chance to get telephone item, win condition.
*********************************************************************/

#include "Special.hpp"

Special::Special() : Space(nullptr, nullptr, nullptr, nullptr, false, "Special"){ //constructor

}

Special::~Special(){ //destructor

}

void Special::dig(Character *&character) { //override virtual dig function from Space
    int chance = rand() % 3 + 1;
    if(chance == 3){ //chance to find item
        cout << "You found a field telephone!" << endl;
        character->addItem(4); //field telephone - win condition item
    }else{ //loses life if character does not find item
        character->set_life(character->get_life() - 20);
        cout << "You found nothing! You hurt yourself while digging and take 20 damage." << endl;
    }
}