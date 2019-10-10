/*********************************************************************
** Program name: Special.hpp
** Author: David Lee
** Date: 06/08/2019
** Description: Header - Derived class from Space class. Special class has member function dig that overrides
 * pure virtual function dig() from Space class. Digging from Special gives chance to get telephone item, win condition.
*********************************************************************/

#ifndef SPECIAL_HPP
#define SPECIAL_HPP
#include "Space.hpp"
#include <iostream>
using std::cout;
using std::endl;

class Special: public Space{ //inherits from Space class

public:
    Special(); //constructor
    ~Special(); //destructor
    void dig(Character*& character) override; //override virtual dig function from Space

};


#endif
