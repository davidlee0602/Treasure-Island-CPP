/*********************************************************************
** Program name: Dirt.hpp
** Author: David Lee
** Date: 06/08/2019
** Description: Header - Derived class from Space class. Dirt class has member function dig that overrides
 * pure virtual function dig() from Space class. Digging from Dirt gives chance to get can of beans item.
*********************************************************************/

#ifndef DIRT_HPP
#define DIRT_HPP
#include "Space.hpp"
#include <iostream>
using std::cout;
using std::endl;

class Dirt: public Space{ //inherits from Space class

public:
    Dirt(); //constructor
    ~Dirt(); //destructor
    void dig(Character*& character) override; //override virtual dig function from Space

};


#endif
