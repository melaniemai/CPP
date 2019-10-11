//#include <iostream>
//#include <string>
//#include "EntertainmentCollection.h"
//#include "base.h"
//#include "board.h"
//#include "videogame.h"
//#include "shelf.h"

//using namespace std;

//int main(){
//    EntertainmentCollection<videogame> *b;
//    b = new EntertainmentCollection<videogame>();
//    int choice = 0;
//    string name;
//    int value = 0;

//    do{
//        cout << "Press 1 to add a video game to the shelf. " << endl;
//        cout << "Press 2 to remove a video game from the shelf." << endl;
//        cout << "Press 3 to see how many video games are currently on the shelf." << endl;
//        cout << "Press 4 to quit." << endl;
//        cout << "Enter number: ";
//        cin >> choice;

//        if(choice == 1){
//             // try doing these steps first and if there is a full shelf (10 games) it'll go to the catch section
//            try {
//                cout << "Enter name for new video game: ";
//                cin >> name;
//                cout << "Enter a value for new video game: ";
//                cin >> value;
//                videogame *game = new videogame();
//                game->setName(name);
//                game->setValue(value);
//                b->add(game);
//            } catch (EntertainmentCollection<videogame>::FullShelf) {
//                cout << endl << "It's a full shelf!" << endl << endl;
//            }

//        }

//        // try to remove a game but if there are 0 games, it'll go to the catch section
//        else if(choice == 2){
//            try {
//                videogame removeGame;
//                removeGame = b->remove();
//                cout << "Game removed: " << removeGame.getName() << endl;
//            } catch (EntertainmentCollection<videogame>::EmptyShelf) {
//                cout << endl << "There aren't any games on the shelf to remove." << endl << endl;
//            }

//        }

//        // just tells user how many games are on the shelf
//        else if(choice == 3){
//            cout << "There are " << b->getNumBoardGames() << " games on the shelf." << endl;
//        }

//    } while(choice != 4);


//    return 0;
//}
