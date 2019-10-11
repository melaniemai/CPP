#ifndef SHELF_H
#define SHELF_H
#include <string>
#include <iostream>
#include "base.h"
#include "board.h"

using namespace std;

const int numOfBoardGames = 10;

class shelf{
private:
    board *Shelf;
    int value;          // holds the # of board games currently being stored in shelf
public:
    // for exceptions if shelf is full, you just want to return value to make sure shelf is really full
    class FullShelf{
    private:
        int value;
    public:
        FullShelf(int v){
            value = v;
        }
        int getValue(){
            return value;
        }
    };

    // for exception if shelf is empty, return value to see if shelf is empty
    class EmptyShelf{
    private:
        int value;
    public:
        EmptyShelf(int v){
            value = v;
        }
        int getValue(){
            return value;
        }
    };

    // default constructor
    shelf(){
        value = 0;
        Shelf = new board[numOfBoardGames];     // allocated 10 memory slots for number of board games
    }
    int getNumOfBoardGames(){
        return value;
    }

    // add new board game function
    void add(board *game){
        // throw exception when shelf is full
        if(value == 10){
            throw FullShelf(value);
        }
        else{
            // we're just setting a name and value for the game at its position on the shelf
            Shelf[value].setName(game->getName());
            Shelf[value].setValue(game->getValue());
            value++;
        }
    }

    // removing a game
    board remove(){    // changes the number of games on the shelf making last game overwriteable
        // throw exception when shelf doesn't have anything on it
        if(value <= 0){
            throw EmptyShelf(value);
        }
        else{
            value--;
            return Shelf[value];
        }
    }

    // checks if shelf is full with max 10 games
    bool full(){
        return value == numOfBoardGames;
    }

    // checks if number of games on shelf is 0
    bool empty(){
        return value == 0;
    }

};

#endif // SHELF_H
