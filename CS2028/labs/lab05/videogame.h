#ifndef VIDEOGAME_H
#define VIDEOGAME_H
#include <iostream>
#include <string>
#include "base.h"
#include "board.h"
#include "shelf.h"

using namespace std;

class videogame : public base{
private:
    string name;
    int val;
public:
    videogame(){
        name = "JohnSmith";
        val = 0;
    }

    videogame(string n, int v){
        name = n;
        val = v;
    }
    string getName(){
        return name;
    }
    void setName(string n){
        name = n;
    }

    int getValue(){
        return val;
    }
    void setValue(int v){
        val = v;
    }

    void Play(){
        cout << "Mash the buttons." << endl;
    }
    void Winner(){
        cout << "Winner music." << endl;
    }
};

#endif // VIDEOGAME_H
