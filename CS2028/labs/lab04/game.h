#ifndef GAME_H
#define GAME_H
#include<iostream>
#include<string>

using namespace std;

class game
{
private:
    string str1 ;
    string str2 ;

public:
        string get_string1() { return str1;}
        string get_string2() { return str2; }

        void set_string1( string str) {  str1 = str; }
        void set_string2( string str) {  str2 = str; }

        game() {
             str1 = "new_game\n";
             str2 = "main_character\n";
        }

        game(string str1, string str2) {
             str1 = str1;
             str2 = str2;
        }

        virtual void play(){
            cout<< "Let's Play\n";
        }

        void winner(){
        cout<< "Not yet\n";
        }

};

#endif // GAME_H
