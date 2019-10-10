/*********************************************************************
** Program name: Sand.cpp
** Author: David Lee
** Date: 06/08/2019
** Description: Implementation - Derived class from Space class. Sand class has member function dig that overrides
 * pure virtual function dig() from Space class. Digging from Sand gives chance to get can of shells item.
*********************************************************************/

#include "Sand.hpp"

Sand::Sand() : Space(nullptr, nullptr, nullptr, nullptr, false, "Sand"){ //constructor

}

Sand::~Sand(){ //destructor

}

void Sand::dig(Character *&character) { //override virtual dig function from Space
    int chance = rand() % 2 + 1;
    if(chance == 2){ //chance to find item
        cout << "You found shells!" << endl;
        character->addItem(3); //shells, useless
    }else{ //loses life if character does not find item
        character->set_life(character->get_life() - 20);
        cout << "You found nothing! You hurt yourself while digging and take 20 damage." << endl;
    }
}