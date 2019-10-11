#include <iostream>
#include <string>
#include "base.h"
#include "board.h"
#include "shelf.h"

using namespace std;

int main()
{
    shelf *s = new shelf();
    int choice = 0;
    string name;
    int value = 0;

    do{
        cout << "Press 1 to add a board game to the shelf." << endl;
        cout << "Press 2 to remove a board game from the shelf." << endl;
        cout << "Press 3 to see how many board games are currently on the shelf." << endl;
        cout << "Press 4 to quit." << endl;
        cout << "Enter number: ";
        cin >> choice;

        if(choice == 1){
            // try doing these steps first and if there is a full shelf (10 games) it'll go to the catch section
            try {
                cout << "Enter name for new board game: ";
                cin >> name;
                cout << "Enter a value for new board game: ";
                cin >> value;
                board *game = new board();
                game->setName(name);
                game->setValue(value);
                s->add(game);
            } catch (shelf::FullShelf) {
                cout << endl << "It's a full shelf!" << endl << endl;
            }

        }

        // try to remove a game but if there are 0 games, it'll go to the catch section
        else if(choice == 2){
            try {
                board removeGame;
                removeGame = s->remove();
                cout << "Game removed: " << removeGame.getName() << endl;
            } catch (shelf::EmptyShelf) {
                cout << endl << "There aren't any games on the shelf to remove." << endl << endl;
            }

        }

        // just tells user how many games are on the shelf
        else if(choice == 3){
            cout << "There are " << s->getNumOfBoardGames() << " games on the shelf." << endl;
        }

    } while(choice != 4);


    return 0;
}
