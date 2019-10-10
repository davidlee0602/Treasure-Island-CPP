/*********************************************************************
** Program name: Grass.hpp
** Author: David Lee
** Date: 06/08/2019
** Description: Header - Derived class from Space class. Grass class has member function dig that overrides
 * pure virtual function dig() from Space class. Digging from Grass gives chance to get berries item.
*********************************************************************/

#ifndef GRASS_HPP
#define GRASS_HPP
#include "Space.hpp"
#include <iostream>
using std::cout;
using std::endl;

class Grass: public Space{ //inherits from Space class

public:
    Grass(); //constructor
    ~Grass(); //destructor
    void dig(Character*& character) override; //override virtual dig function from Space

};


#endif
