/*********************************************************************
** Program name: Dirt.cpp
** Author: David Lee
** Date: 06/08/2019
** Description: Implementation - Derived class from Space class. Dirt class has member function dig that overrides
 * pure virtual function dig() from Space class. Digging from Dirt gives chance to get can of beans item.
*********************************************************************/

#include "Dirt.hpp"

Dirt::Dirt() : Space(nullptr, nullptr, nullptr, nullptr, false, "Dirt"){ //constructor

}

Dirt::~Dirt(){ //destructor

}

void Dirt::dig(Character *&character) { //override virtual dig function from Space
    int chance = rand() % 3 + 1;
    if(chance == 3){ //chance to find item
        cout << "You found a can of beans!" << endl;
        character->addItem(1); //can of beans
    }else{ //loses life if character does not find item
        character->set_life(character->get_life() - 20);
        cout << "You found nothing! You hurt yourself while digging and take 20 damage." << endl;
    }
}