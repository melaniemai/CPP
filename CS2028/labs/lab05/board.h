#ifndef BOARD_H
#define BOARD_H
#include <string>
#include <iostream>
#include "base.h"

using namespace std;

class board : public base{
private:
    string name;
public:
    board(){
        name = "JohnSmith";
    }
    void winner(){
        cout << "Dancing time." << endl;
    }
    void play(){
        cout << "Roll the dice." << endl;
    }
    string getName(){
        return name;
    }
    void setName(string n){
        name = n;
    }
};

#endif // BOARD_H
