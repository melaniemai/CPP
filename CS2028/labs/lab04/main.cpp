#include<iostream>
#include<string>
#include<board_game.h>
#include<game.h>
#include<video_game.h>
#include<cstddef>



using namespace std;

void function(game *g1){
    g1->play();
    g1->winner();
}

int main()
{
    game *g1;
    board_game *bg1;
    video_game *vg1;
    char cont = 'a';

    while(true){
        int i = 0;
        cout<< "Press 1 for an instance of game.\nPress 2 for an instance of board game.\nPress 3 for an instance of video game.\nPress 4 for an instance of a board game declared as a game\nPress 5 for an instance of a video game declared as a game.\nEnter in number: ";
        cin >> i;

        if (i == 1) {
            g1 = new game();
            g1->play();
            g1->winner();
            function(g1);
        } else if(i == 2){
            bg1 = new board_game();
            bg1->play();
            bg1->winner();
            function(bg1);
        } else if(i == 3){
            vg1 = new video_game();
            vg1->play();
            vg1->winner();
            function(vg1);
        } else if(i == 4){
            g1 = new board_game();
            g1->play();
            g1->winner();
            function(g1);
        } else if(i == 5){
            g1 = new video_game();
            g1->play();
            g1->winner();
            function(g1);

        } else{
            cout << "Error." << endl;
        }

        cout << "Would you like to continue?: (Y or N) ";
        cin >> cont;
        if(cont == 'N' || cont == 'n'){
            break;
        }

    }
    delete g1;
    delete bg1;
    delete vg1;
}
