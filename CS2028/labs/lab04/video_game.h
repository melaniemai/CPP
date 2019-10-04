#ifndef VIDEO_GAME_H
#define VIDEO_GAME_H
#include<iostream>
#include<string>
#include<board_game.h>
#include<game.h>

using namespace std;


class video_game : public game
{
  private:

        string strvg ;

    public:

        string get_string_for_vg() { return strvg;}

        void set_string_for_bv( string str) {  strvg = str; }


        void play() {cout << "Mash the buttons\n";}

        void winner(){ cout<< "Winner music\n";}

        video_game(){strvg = "video_game_new";}
//        virtual ~video_game();
};

#endif // VIDEO_GAME_H
