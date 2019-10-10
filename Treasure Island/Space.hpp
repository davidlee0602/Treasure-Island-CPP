/*********************************************************************
** Program name: Space.hpp
** Author: David Lee
** Date: 06/08/2019
** Description: Header - Base class for Dirt, Grass, Sand, Special class. Has 4 space pointers to store addresses
 * to other spaces - linked structure. Has data member to identify space type and if character is positioned in current space.
 * As an abstract class, has virtual functions (polymorphism) for accessor, mutator member functions.
 * The dig function is a pure virtual function which gets overridden by dig functions from derived classes.
*********************************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP
#include "Character.hpp"
#include <string>
using std::string;

class Space { //abstract class - base class used in inheritance - Dirt, Grass, Sand, Special

private:
    Space* top; //pointer to top
    Space* right; //pointer to right
    Space* left; //pointer to left
    Space* bottom; //pointer to bottom
    string type; //stores type of space
    bool active_character; //stores if character exists in space


public:
    //constructor and destructor
    Space(); //constructor
    virtual ~Space(); //destructor
    Space(Space* top, Space* right, Space* left, Space* bottom, bool active_character, string type); //constructor with parameters to initialize data member

    //accessor
    virtual Space* get_top(); //returns address of top space
    virtual Space* get_right(); //returns address of right space
    virtual Space* get_left(); //returns address of left space
    virtual Space* get_bottom(); //returns address of bottom space
    virtual bool get_character_active(); //returns true if character exists in space
    virtual string get_type(); //returns type of space

    //mutator
    virtual void set_top(Space* top); //mutator for top space pointer
    virtual void set_right(Space* right); //mutator for right space pointer
    virtual void set_left(Space* left); //mutator for left space pointer
    virtual void set_bottom(Space* bottom); //mutator for bottom space pointer
    virtual void set_character_active(bool active_character); //mutator to indicate if character exists in space

    //game function
    void virtual dig(Character*& character) = 0; //pure virtual function

};


#endif
