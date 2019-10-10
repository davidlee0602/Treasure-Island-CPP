/*********************************************************************
** Program name: Character.cpp
** Author: David Lee
** Date: 06/08/2019
** Description: Implementation file for the Character class. Character class keeps track of
 * user life, and win condition via its data members. Additionally, it has accessor and mutator functions to
 * life, win condition and the item bag.
*********************************************************************/

#include "Character.hpp"
#include <iostream>
using std::cout;
using std::endl;

Character::Character(){ //constructor - initializes value to data members
    life = 100; //character starts with 100 life
    winCondition = false; //winCondition changes when character finds and uses telephone item
}

Character::~Character(){ //destructor

}

//accessor
int Character::get_life(){ //character life accessor
    return life;
}

bool Character::get_win(){ //character win flag accessor
    return winCondition;
}


//mutator
void Character::set_life(int life){ //character life mutator
    this->life = life;
}

void Character::set_win(bool winCondition){ //character win flag mutator
    this->winCondition = winCondition;
}
//game function
void Character::addItem(int item){ //adds item to queue list [FILO]
    if(itemBag.size() < 3){ //item bag max size is 3
        itemBag.push(item);
        cout << "Item was added to your bag: ";
        if(itemBag.back() == 1){
            cout << "[beans]" << ' ';
        }else if(itemBag.back() == 2){
            cout << "[berries]" << ' ';
        }else if(itemBag.back() == 3){
            cout << "[shells]" << ' ';
        }else if(itemBag.back() == 4){
            cout << "[telephone]" << ' ';
        }else{
            cout << "Error" << ' ';
        }
        cout << endl;
    }else{
        cout << "ItemBag is full. Cannot add item. ItemBag can carry upto three items." << endl; //item not added if item bag is at max limit
    }
}

void Character::clearItemBag(){ //resets queue list
    while(!itemBag.empty()){
        itemBag.pop();
    }
}

void Character::useItem() { //function for character to use item [FILO]
    if(!itemBag.empty()){
        cout << "Using item: ";
        if(itemBag.front() == 1){
            cout << "[beans]" << endl;
        }else if(itemBag.front() == 2){
            cout << "[berries]" << endl;
        }else if(itemBag.front() == 3){
            cout << "[shells]" << endl;
        }else if(itemBag.front() == 4){
            cout << "[telephone]" << endl;
        }else{
            cout << "Error" << ' ';
        }
        if (itemBag.front() == 1){ //can of beans
            if(get_life() <= 60){
                set_life(get_life() + 40); //regenerate life by 40
                cout << "You recovered 40 life" << endl;
            }else{
                set_life(100); //full life
                cout << "You recovered to full life" << endl;
            }
        }else if(itemBag.front() == 2){ //berries
            int edible = rand() % 2 + 1;
            if (edible == 1){
                cout << "You ate non-poisonous berries." << endl;
                if(get_life() <= 90){
                    set_life(get_life() + 10); //regenerate life by 10
                    cout << "You recovered 10 life" << endl;
                }else{
                    set_life(100); //full life
                    cout << "You recovered to full life" << endl;
                }
            }else{
                cout << "You ate poisonous berries." << endl;
                set_life(get_life() - 10); //lost 10 life
                cout << "You lost 10 life" << endl;
            }
        }else if (itemBag.front() == 3){ //shells
            cout << "Shells... These are useless. You threw them away." << endl;
        }else if (itemBag.front() == 4){ //telephone - win condition item
            cout << "You used a field telephone to call for help! You can now go home!" << endl;
            set_win(true);
        }
        itemBag.pop();
    }else{
        cout << "Your item bag is empty." << endl;
    }

}

void Character::printItemBag() { //prints items in item bag
    cout << "--------------------------------------------------" << endl;
    queue<int> tempItemList = itemBag;
    cout << "Items in your bag:" << endl;
    while(!tempItemList.empty()){
        if(tempItemList.front() == 1){
            cout << "[beans]" << ' ';
        }else if(tempItemList.front() == 2){
            cout << "[berries]" << ' ';
        }else if(tempItemList.front() == 3){
            cout << "[shells]" << ' ';
        }else if(tempItemList.front() == 4){
            cout << "[telephone]" << ' ';
        }else{
            cout << "Error" << ' ';
        }
        tempItemList.pop();
    }
    cout << endl;
    cout << "--------------------------------------------------" << endl;
}