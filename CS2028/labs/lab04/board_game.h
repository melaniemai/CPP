#ifndef BOARD_GAME_H
#define BOARD_GAME_H
#include<iostream>
#include<string>
#include<game.h>
#include<video_game.h>

using namespace std;


class board_game : public game
{
    private:

        string strbg ;

    public:

        string get_string_for_bg() { return strbg = "newgame";}

        void set_string_for_bg( string str) {  strbg = str; }


        void play() {cout << "Role the dice\n";}

        void winner(){ cout<< "Dancing time\n";}

        board_game(){strbg = "board_game_new";}
//        virtual ~board_game();
};

#endif // BOARD_GAME_H
