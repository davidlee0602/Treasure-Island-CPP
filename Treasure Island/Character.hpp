/*********************************************************************
** Program name: Character.hpp
** Author: David Lee
** Date: 06/08/2019
** Description: Header file for the Character class. Character class keeps track of
 * user life, and win condition via its data members. Additionally, it has accessor and mutator functions to
 * life, win condition and the item bag.
*********************************************************************/

#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <queue>
using std::queue;

class Character {
private:
    int life; //stores character life
    queue<int> itemBag; //queue STL to store character items
    bool winCondition; //win condition flag when character uses telephone

public:
    //constructor and destructor
    Character(); //constructor
    ~Character(); //destructor

    //accessor
    int get_life(); //character life accessor
    bool get_win(); //character win flag accessor

    //mutator
    void set_life(int life); //character life mutator
    void set_win(bool winCondition); //character win flag mutator

    //game function
    void addItem(int item); //adds item to queue list
    void clearItemBag(); //resets queue list
    void useItem(); //function for character to use item
    void printItemBag(); //prints items in item bag


};


#endif
