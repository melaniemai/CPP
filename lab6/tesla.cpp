// Lab6 - tesla.cpp
// Melanie Mai, June 30, 2019
// Find the Roadster without getting caught by Elon


#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <array>

using namespace std;

void gameStory(){
    cout << "THE STORY:" << endl;
    cout << "You find your way to SpaceX the night before the Roadster is mounted atop the rocket " << endl;
    cout << "which is to send it into space. The building is dark and the roadster is hidden somewhere in a " << endl;
    cout << "large open dark room (15x15). In addition to the roadster, two other cars (a Yugo and " << endl;
    cout << "ford pinto) are being stored in this facility as well. BTW: Elon Musk is sleeping somewhere " << endl;
    cout << "in the same room and you have to avoid waking him to find your way to the roadster. Once " << endl;
    cout << "awoken he will randomly move through the building looking for you. If he lands next to you, " << endl;
    cout << "you can get away from him only once. The second time you will be the ""Starman"" and blasted " << endl;
    cout << "into space with his roadster. Once he is a awake your only chance to avoid being ""Starman"" is " << endl;
    cout << "to make your escape in his roadster. If you get into either of the other two cars you will be " << endl;
    cout << "caught and become the ""Starman""." << endl << endl;
    cout << "-------------------------------------------------------------------------------------------------" << endl;
}

// Generate random numbers for row and column positions
int randPosition(){
    return (rand() % 15) + 1;
}


int main()
{
    srand(time(NULL));

    // Create 15x15 dark room
    char room[16][16];

    cout << "Welcome..." << endl << endl;

    // Print out story of the game
    gameStory();

    char yn; // Input if user would like to play again.
    bool game = true;

    while(game == true){
        // Create room but don't show
        for(int i = 1; i <= 15; i++){
            for(int j = 1; j <= 15; j++){
                room[i][j] = '*';
            }
            cout << endl;
        }

        cout << "Would you like to play? y/n: ";
        cin >> yn;
        cout << endl;

        int n = 1; // Size of array is 1
        int* tries = new int [n]; // Array stores and keeps track of how many tries user has / if Elon is next to user, user gets one more chance
        tries[0] = {0}; // Element in array is 0

        char move = 'z'; // input for user's choice of movement (w, a, s, d) or quit (q).
        int findroadster = 0; // Number of turns to find roadster.
        int roadsterfound = 0; // Number of times the roadster was found.
        int starman = 0; // Number of times the user became "Starman".
        int turns = 0; // Number of tries the user took before finding something

        // From lines 72-112, randomize everyone's positions.
        // Make sure no one overlaps one another's coordinates
        int userRow = randPosition();
        int userCol = randPosition();
        room[userRow][userCol] = 'U'; // User's position

        int pintoRow = randPosition();
        int pintoCol = randPosition();
        // Check if pinto's position is the same as the user's position:
        if(pintoRow == userRow && pintoCol == userCol){
            pintoRow =  randPosition();
            pintoCol = randPosition();
        }
        room[pintoRow][pintoCol] = 'P'; // Pinto position

        int roadsterRow = randPosition();
        int roadsterCol = randPosition();
        // Check if Roadster's position is the same as user or pinto positions:
        if((roadsterRow == userRow && roadsterCol == userCol) || (roadsterRow == pintoRow && roadsterCol == pintoCol)){
            roadsterRow = randPosition();
            roadsterCol = randPosition();
        }
        room[roadsterRow][roadsterCol] = 'R'; // Roadster position

        int yugoRow = randPosition();
        int yugoCol = randPosition();
        // Check if Yugo's position is the same as the user, pinto, or roadster's position
        if((yugoRow == userRow && yugoCol == userCol) || (yugoRow == pintoRow && yugoCol == pintoCol) ||
                (yugoRow == roadsterRow && yugoCol == roadsterCol)){
            yugoRow = randPosition();
            yugoCol = randPosition();
        }
        room[yugoRow][yugoCol] = 'Y'; // Yugo position

        int elonRow = randPosition();
        int elonCol = randPosition();
        // Check if Elon's position is the same as user, pinto, roadster, or yugo's position
        if((elonRow == userRow && elonCol == userCol) || (elonRow == pintoRow && elonCol == pintoCol) ||
                (elonRow == roadsterRow && elonCol == roadsterCol) || (elonRow == yugoRow && elonCol == yugoCol)){
            elonRow = randPosition();
            elonCol = randPosition();
        }
        room[elonRow][elonCol] = 'E'; // Sleeping Elon's position

        while(yn == 'y'){
            // Let user know their starting position
            cout << "Your position is U:(" << userRow << "," << userCol << ")." << endl;
            room[userRow][userCol] = 'U';

            cout << "Enter w (forward/north), a (left/west), s (backward/south), d (right/east) for movement directions. Enter q to quit: ";
            cin >> move;
            findroadster += 1;
            turns += 1;

            // Mask position of user and Elon so game board doesn't show the moves or positions user has went
            room[userRow][userCol] = '*'; room[elonRow][elonCol] = '*';

            // Movements
            if(move == 'w'){
                userRow -= 1;
            } if(move == 's'){
                userRow += 1;
            } if(move == 'a'){
                userCol -= 1;
            } if(move == 'd'){
                userCol += 1;
            } if(move == 'q'){
                break;
            } if((move != 'w') && (move != 's') && (move != 'a') && (move != 'd') && (move != 'q')){
                cout << "Please enter a valid movement: ";
                cin >> move;
                turns += 1;
                findroadster += 1;
            }

            // Ensure user is not off the map when moving
            if(userRow > 15){
                userRow = 15;
            } if(userRow <= 0){
                userRow = 1;
            } if(userCol > 15){
                userCol = 15;
            } if(userCol <= 0){
                userCol = 1;
            }

            cout << "Your position is U:(" << userRow << "," << userCol << ")." << endl;
            room[userRow][userCol] = 'U';

            // Check and see if user position is same as roadster (winning condition)
            if((userRow == roadsterRow) && (userCol == roadsterCol)){
                cout << "Congratulations, you've got yourself a Roadster! Don't text and drive!" << endl;
                roadsterfound += 1;
                break;
            }

            // Check if user position is same as Pinto
            if(userRow == pintoRow && (userCol == pintoCol)){
                cout << "You got yourself a Pinto." << endl;
                break;
            }

            // Check if user position is same as Yugo
            if(userRow == yugoRow && (userCol == yugoCol)){
                cout << "You got yourself a Yugo." << endl;
                break;
            }

            // Check if user position is next to Elon
            if(abs(elonRow - userRow) <= 1 && abs(elonCol - userCol) <= 1){
                tries[0] += 1;
                // User has one more chance to find Roadster. Once their second try is used and they are by Elon they are the Starman
                if(tries[0] == 2){
                    cout << "Yikes! Elon caught you and now you're going to jail! Better luck next time!" << endl;
                    starman += 1;
                    break;
                }
                cout << "Uh-oh! Elon is right next to you! You have one more chance!" << endl;
            }

            // Determine if user is getting warmer or colder to Roadster
            if(roadsterRow <= (userRow + 2) || (roadsterCol <= (userRow + 2)) || (roadsterRow <= (userRow - 2)) || (roadsterCol <= (userCol - 2))){
                cout << "You're getting warmer!" << endl;
            } else{
                cout << "You're getting colder!" << endl;
            }

        }

        // Reveal user, pinto, roadster, and yugo positions and display board
        room[userRow][userCol] = 'U';
        room[pintoRow][pintoCol] = 'P';
        room[yugoRow][yugoCol] = 'Y';
        room[roadsterRow][roadsterCol] = 'R';
        cout << endl << "Final map: " << endl;
        for(int i = 1; i <= 15; i++){
            for(int j = 1; j <= 15; j++){
                cout << room[i][j];
            }
            cout << endl;
        }

        if(roadsterfound > 0){
            cout << "Number of turns it took to find the Roadster: " << findroadster << endl;
            cout << "Number of times the Roadster was found: " << roadsterfound << endl;
        }

        cout << "Number of attemps you made: " << turns << endl;
        cout << "Number of times you became the Starman: " << starman << endl;

        cout << "Would you like to play again? y/n: ";
        cin >> yn;
        if(yn == 'n'){
            break;
        }
        cout << endl;

        delete[] tries; // Delete array from memory and this will clear out array (array will be created again in beginning)
    }

    cout << "Exiting..." << endl;

    return 0;

}
