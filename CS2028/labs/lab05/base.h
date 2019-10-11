#ifndef BASE_H
#define BASE_H
#include <string>
#include <iostream>
using namespace std;

class base{
private:
    string name;
    int value;
public:
    base(){
        name = "JohnSmith";
        value = 0;
    }
    base(string n, int v){
        name = n;
        value = v;
    }
    string getName(){
        return name;
    }
    void setName(string n){
        name = n;
    }
    int getValue(){
        return value;
    }
    void setValue(int v){
        value = v;
    }
    void winner(){
        cout << "Not Yet." << endl;
    }
    virtual void play(){
        cout << "Let's Play." << endl;
    }

};

#endif // BASE_H
