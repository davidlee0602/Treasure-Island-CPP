/*********************************************************************
** Program name: Grass.cpp
** Author: David Lee
** Date: 06/08/2019
** Description: Implementation - Derived class from Space class. Grass class has member function dig that overrides
 * pure virtual function dig() from Space class. Digging from Grass gives chance to get berries item.
*********************************************************************/

#include "Grass.hpp"

Grass::Grass() : Space(nullptr, nullptr, nullptr, nullptr, false, "Grass"){ //constructor

}

Grass::~Grass(){ //destructor

}

void Grass::dig(Character *&character) { //override virtual dig function from Space
    int chance = rand() % 2 + 1;
    if(chance == 2){ //chance to find item
        cout << "You found berries!" << endl;
        character->addItem(2); //berries
    }else{ //loses life if character does not find item
        character->set_life(character->get_life() - 20);
        cout << "You found nothing! You hurt yourself while digging and take 20 damage." << endl;
    }
}