/*********************************************************************
** Program name: Sand.hpp
** Author: David Lee
** Date: 06/08/2019
** Description: Header - Derived class from Space class. Sand class has member function dig that overrides
 * pure virtual function dig() from Space class. Digging from Sand gives chance to get shells item.
*********************************************************************/

#ifndef SAND_HPP
#define SAND_HPP
#include "Space.hpp"
#include <iostream>
using std::cout;
using std::endl;

class Sand: public Space{ //inherits from Space class

public:
    Sand(); //constructor
    ~Sand(); //destructor
    void dig(Character*& character) override; //override virtual dig function from Space

};


#endif
