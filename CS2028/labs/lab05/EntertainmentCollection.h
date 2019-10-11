#ifndef ENTERTAINMENTCOLLECTION_H
#define ENTERTAINMENTCOLLECTION_H
#include <string>
#include <iostream>
#include "base.h"
#include "board.h"
#include "videogame.h"

using namespace std;

const int maxBoardGames = 10;

template <class E>
class EntertainmentCollection{
private:
    int value;
    E *collection;
public:
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

    EntertainmentCollection();
    int getNumBoardGames();
    void add(E *g);
    E remove();
    bool full();
    bool empty();
};

template<class E>
EntertainmentCollection<E>::EntertainmentCollection(){
    value = 0;
    collection = new E[maxBoardGames];
}

template<class E>
int EntertainmentCollection<E>::getNumBoardGames(){
    return value;
}

template<class E>
void EntertainmentCollection<E>::add(E *g){
    if(value == 10){
        throw FullShelf(value);
    }
    else{
        collection[value].setName(g->getName());
        collection[value].setValue(g->getValue());
        value++;
    }
}

template<class E>
E EntertainmentCollection<E>::remove(){
    if(value <= 0){
        throw EmptyShelf(value);
    }
    else{
        value--;
        return collection[value];
    }
}

template<class E>
bool EntertainmentCollection<E>::full(){
    return value == numOfBoardGames;
}

template<class E>
bool EntertainmentCollection<E>::empty(){
    return value == 0;
}




#endif // ENTERTAINMENTCOLLECTION_H
