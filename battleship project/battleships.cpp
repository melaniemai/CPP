/*
 * Project Title:
 * - Battleships
 * Description: (should be a few sentences)
 * This program is a basic concept of the game Battleships. In order to win the game, you must sink all 4 ships 
 * within 15 tries. If not, you lose the game. If you sink part of a ship, an 'X' will appear on the board at the 
 * coordinate you entered. If you miss a ship, a 'O' will appear at the coordinate you inputted. You have the
 * option to review the rules before you play or quit the game. 
 *
 * Developers:
 * - Maddie Waite - waitemj@mail.uc.edu
 * - Melanie Mai - maims@mail.uc.edu
 *
 * Help Received:
 * - None
 *
 * Special Instructions:
 * 
 * - All code testing was done in Qt Creator and therefore would be best to run in Qt Creator.
 *
 * Developer comments: 
 * 
 * Developer 1 (Maddie Waite):
 * Developed the Board class, each method function within the class and helped to build part of the gameplay() function. 
 * From this experience, I learned how to work on a team and troubleshoot issues with other. I gained a better grasp
 * on all of the aspects that need to be considered when creating a game like this with code. This helped to solidify and reinforce 
 * the importance of the topics we covered in class this semester.  
 * 
 * Developer 2 (Melanie Mai):
 * Developed the Ships class, each method function within the class, implemented the userShot() member function in the 
 * Board class, and created and implemented part of the gameplay() function. 
 * From this experience, I learned how to work in a team setting and combine ideas. I gained a better understanding
 * of OOP using classes to solve problems, and understand code better. 
 */


#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>			// time
#include <stdlib.h> 	// srand, rand

using namespace std;

const int rows = 10;
const int columns = 10;



/* Class Name: Ships
 *
 * Description:
 * This class creates each ship involved in the game and sets the direction of 
 * how they will be placed on the board. 
 */
class Ships{
public:
    bool isShipSunken;
    int shipSize;
    int xposition;      // x position of the base element of ship
    int yposition;      // y position of the base element of ship
    char direction;
    int xArray[5];
    int yArray[5];

    Ships(){            // default constructor

    }

    Ships(string boatname, int boatsize){       // Overloading constructor
        shipName = boatname;
        shipSize = boatsize;
        health = shipSize;
        isShipSunken = false;

        for(int i = 0; i < 5; i++){         // Array filler
            xArray[i] = -1;
            yArray[i] = -1;
        }

        if(direction == 'N'){
            for(int i = 0; i < shipSize; i++){
                xArray[0] = xposition;
                yArray[i] = yposition - i;          // have to go up columns
            }
        } else if(direction == 'E'){
            for(int i = 0; i < shipSize; i++){
                xArray[i] = xposition + i;          // have to go right rows
                yArray[0] = yposition;
            }
        } else if(direction == 'S'){
            for(int i = 0; i < shipSize; i++){      // have to go down columns
                xArray[0] = xposition;
                yArray[i] = yposition + i;
            }
        } else if(direction == 'W'){
            for(int i = 0; i < shipSize; i++){
                xArray[i] = xposition - i;          // have to go left rows
                yArray[0] = yposition;
            }
        }

    }

    /* Member Function Name: setDirection
     *
     * Description:
     * Sets the direction in which the ship fill face.
     *
     * Parameters:
     * none
     *
     * return value:
     * none - void function
     */
    char setDirection(){
        int xposition;
        xposition = (rand() % 4) + 1;
        int i = 0;
        while(i < 1){
            if(xposition == 1){
                direction = 'N';
                i++;
            } else if(xposition == 2){
                direction = 'E';
                i++;
            } else if(xposition == 3){
                direction = 'S';
                i++;
            } else if(xposition == 4){
                direction = 'W';
                i++;
            }
        }
        return direction;
    }

    /* Member Function Name: getDirection
     *
     * Description:
     * Gets the char of where the ship will face
     *
     * Parameters:
     * none
     *
     * return value:
     * char - char function
     */
    char getDirection(){
        return direction;
    }

    /* Member Function Name: setXDirection
     *
     * Description:
     * Sets the x direction of the ship.
     *
     * Parameters:
     * none
     *
     * return value:
     * none - void function
     */
    int setXDirection(){
        direction = setDirection();
        if(direction == 'E'){
            xposition = (rand() % (10 - shipSize)) + 1;     // x position have to be able to fit ship length, hence randomizing the options from 10 = shipSize. Ship also can't fit to the right so have to subtract ship length.
        } else if(direction == 'W'){
            xposition = (rand() % (10 - shipSize)) + shipSize;
        } else{
            xposition = (rand() % 10) + 1;
        }
        return xposition;
    }

    /* Member Function Name: getSetXDirection
     *
     * Description:
     * Gets the value of the x position
     *
     * Parameters:
     * none
     *
     * return value:
     * int - int function
     */
    int getSetXDirection(){
        int xposition = setXDirection();
        return xposition;
    }

    /* Member Function Name: setYDirection
     *
     * Description:
     * Sets the y direction in which the ship fill face.
     *
     * Parameters:
     * none
     *
     * return value:
     * none - void function
     */
    int setYDirection(){
        direction = getDirection();
        if(direction == 'N'){
            yposition = (rand() % (10 -shipSize)) + shipSize;
        } else if(direction == 'S'){
            yposition = (rand() % (10 - shipSize)) + 1;
        } else{
            yposition = (rand() % 10) + 1;
        }
        return yposition;
    }

    /* Member Function Name: getSetYDirection
     *
     * Description:
     * Gets the value of the y position
     *
     * Parameters:
     * none
     *
     * return value:
     * int - int function
     */
    int getSetYDirection(){
        return yposition;
    }

    /* Member Function Name: getShipName
     *
     * Description:
     * Gets the name of the ship
     *
     * Parameters:
     * none
     *
     * return value:
     * string - string function
     */
    string getShipName(){
        return shipName;
    }

    /* Member Function Name: setShipHealth
     *
     * Description:
     * Set's the value of the ship's health based on x parameter
     *
     * Parameters:
     * int x
     *
     * return value:
     * none - void function
     */
    void setShipHealth(int x){
        health = x;
    }

    /* Member Function Name: getShipHealth
     *
     * Description:
     * Gets the value of the ship's health
     *
     * Parameters:
     * none
     *
     * return value:
     * int - int function
     */
    int getShipHealth(){
        return health;
    }

    /* Member Function Name: displayHealth
     *
     * Description:
     * Displays the health/ how much of ship is remaining
     *
     * Parameters:
     * none
     *
     * return value:
     * none - void function
     */
    void displayHealth(){
        cout << shipName << " health: " << getShipHealth() << " /" << shipSize << endl;
    }

    /* Member Function Name: shipIsHit
     *
     * Description:
     * Decrement's ship's health when it has been shot at and
     * determines if the ship is sunken.
     *
     * Parameters:
     * none
     *
     * return value:
     * none - void function
     */
    void shipIsHit(){
        health--;
        if(health == 0){
            isShipSunken = true;
        }
    }

    /* Member Function Name: getSunkenShip
     *
     * Description:
     * Gets the value of whether or not the ship is sunken
     *
     * Parameters:
     * none
     *
     * return value:
     * bool - bool function
     */
    bool getSunkenShip(){
        return isShipSunken;
    }

private:
    string shipName;
    int health;         // number of hits before ship is destroyed
};



/* Class Name: Board
 *
 * Description:
 *This class controls the board that the user sees
 */
class Board{
public:
    char board[10][10];
    Ships fleet[4];								// fleet of all our ships
    int xShotCoord;
    int yShotCoord;

    Board(){ // default constructor
        Ships carrier("Carrier", 5);		// name of ship and length of ship
        Ships battleship("Battleship", 4);
        Ships destroyer("Destroyer", 3);
        Ships cruiser("Cruiser", 2);

        fleet[0] = carrier;
        fleet[1] = battleship;
        fleet[2] = destroyer;
        fleet[3] = cruiser;

        createBoard();

        AddShips(carrier);
        AddShips(battleship);
        AddShips(destroyer);
        AddShips(cruiser);

    }
   
    /* Member Function Name: createBoard
     *
     * Description:
     * Creates a board and a hidden board to display to the user
     *
     * Parameters:
     * none
     *
     * return value:
     * none - void function
     */

    void createBoard(){ 
        for (int i = 0; i < 10; i++){
            for(int j = 0; j < 10; j++){
                board[i][j] = '-';
            }
        }
        for (int i = 0; i < 10; i++){
            for(int j = 0; j < 10; j++){
                hiddenboard[i][j] = 0;
            }
        }
    }
  
  	/* Member Function Name: AddShips
     *
     * Description:
     * Generates the location of the ships
     *
     * Parameters:
     * Ship
     *
     * return value:
     * none - void function
     */

    void AddShips(Ships current){
        int length = current.getShipHealth();
        char direction = current.setDirection();
        int x, y;
        do{
            x = current.setXDirection();
            y = current.setYDirection();
        }while(hiddenboard[x][y] !=0 || hiddenboard[x+1][y] !=0 || hiddenboard[x+2][y] !=0 || hiddenboard[x+3][y] !=0 || hiddenboard[x+4][y] !=0 || hiddenboard[x][y+1] !=0 || hiddenboard[x][y+2] !=0 || hiddenboard[x][y+3] !=0 || hiddenboard[x][y+4] !=0 || hiddenboard[x-1][y] !=0 || hiddenboard[x-2][y] !=0 || hiddenboard[x-3][y] !=0 || hiddenboard[x-4][y] !=0 || hiddenboard[x][y-1] !=0 || hiddenboard[x][y-2] !=0 || hiddenboard[x][y-3] !=0 || hiddenboard[x][y-4] !=0);

        cout << length << " " << x << " " << y << " " << direction << endl;

        if (direction == 'N'){ // up
            for (int i = 0; i < length; i ++){
                hiddenboard[x-i][y] = length;
            }
        }
        else if (direction == 'S'){ // down
            for (int i = 0; i < length; i ++){
                hiddenboard[x+i][y] = length;
            }
        }
        else if (direction == 'E'){ // right
            for (int i = 0; i < length; i ++){
                hiddenboard[x][y+i] = length;
            }
        }
        else if (direction == 'W'){ // left
            for (int i = 0; i < length; i ++){
                hiddenboard[x][y-i] = length;
            }
        }
    }
  
    /* Member Function Name: outputBoard
     *
     * Description:
     * Displays the board to the user
     *
     * Parameters:
     * none
     *
     * return value:
     * none - void function
     */
  
    void outputBoard(){
        cout << "  0 1 2 3 4 5 6 7 8 9" << endl;
        for (int i = 0; i < 10; i++){
            cout << i << " ";
            for(int j = 0; j < 10; j++){
                cout<< board[i][j] << " ";
            }
            cout << endl;
        }
    }
    /* Member Function Name: userShot
     *
     * Description:
     * Takes in the users coordinates of where they are firing at
     *
     * Parameters:
     * none
     *
     * return value:
     * int - returns which ship is hit or 0 if it is missed
     */

    int userShot(){
        cout << "Enter coordinate, seperated by comma \", \": " << endl;
        string userInput;
        cin >> userInput;
        int checkBreak = 0;
        while(checkBreak == 0){
            if((userInput.length() != 3) || (!(isdigit(userInput[0]))) || (userInput[1] != ',') || (!(isdigit(userInput[2]))) || (userInput[2] < 1)){
                cout << "Coordinate is invalid. Please try again: ";
                cin >> userInput;
            } else{
                if((userInput[0] >= 'a') && (userInput[0] <= 'z')){
                    userInput[0] = userInput[0] - 32;               
                } else if(userInput[0] > 'J'){                     
                    userInput[0] = 'J';
                }
            }
            checkBreak++;       
        }

        int xShotCoord = userInput[0] -48;          
        int yShotCoord = userInput[2] -48;
        if(hiddenboard[xShotCoord][yShotCoord] != 0 && (board[xShotCoord][yShotCoord] != 'X')){
            cout << "YOU HIT A SHIP!" << endl;
            board[xShotCoord][yShotCoord] = 'X';
            int shipNumber = hiddenboard[xShotCoord][yShotCoord];
            return shipNumber;
        } else if(board[xShotCoord][yShotCoord] == 'X' || (board[xShotCoord][yShotCoord] == 'O')){
            cout << "YOU ALREADY SHOT THERE!" << endl;
        } else {
            cout << "YOU MISSED!" << endl;
            board[xShotCoord][yShotCoord] = 'O';
            int ship = 0;
            return ship;
        }
    }
  
     /* Member Function Name: isGameOver
     *
     * Description:
     * Checks if there are any ships remaining
     *
     * Parameters:
     * ships
     *
     * return value:
     * bool- if game is over or not
     */
    bool isGameOver(Ships s){
        int gameover = 1;
        for(int i = 0; i < 4; i++){
            if(fleet[i].getSunkenShip() == false){
                gameOver = false;
                gameover = 0;
                return gameOver;
            } else if(fleet[i].getSunkenShip() == true){
                gameover = true;
                gameover = 1;
                return 1;
            }
        }
    }
private:
    int hiddenboard[10][10];
    bool gameOver;				// if all ships are sunk
};

    /* Member Function Name: gameplay
     *
     * Description:
     * Controls the main game
     *
     * Parameters:
     * board
     *
     * return value:
     * none - void function
     */

void gameplay(Board p1){				
    char p1choice;
    int userTries = 0;
    int maxAmountOfTries = 20;

    cout << "WELCOME TO A GAME OF BATTLESHIP!" << endl << endl;
    cout << " ------ MENU ------ " << endl;
    cout << " Press P to play. " << endl;
    cout << " Press H for help." << endl;
    cout << " Press Q to quit. " << endl;
    cin >> p1choice;
    while((p1choice != 'P') && (p1choice != 'p') && (p1choice != 'H') && (p1choice != 'h') &&
          (p1choice != 'Q') && (p1choice != 'q')){
        cout << "Sorry. That option isn't available. Please try again: ";
        cin >> p1choice;
    }

    while(p1choice == 'H' || p1choice == 'h'){
        cout << "INSTRUCTIONS: " << endl;
        cout << "There will be four ships of four different lengths hidden throughout the board."<< endl;                           
        cout << "Enter the coordinates of the location that you would like to fire at."<< endl;
        cout << "If a ship is hit a 'X' will appear or if it is missed then a 'O' will appear."<<endl;
        cout << "Try to sink all the ships in as few moves as possible!"<<endl;
        cout << "Would you like to play (P) or quit (Q) the program?: " << endl;
        cin >> p1choice;
        while((p1choice != 'P') && (p1choice != 'p') && (p1choice != 'Q') && (p1choice != 'q')){
            cout << "Sorry. That option isn't available. Please try again: ";
            cin >> p1choice;
        }
        if(p1choice == 'Q' || p1choice == 'q'){
            cout << "Thanks for stopping by!" << endl;
            break;
        }
    }

    while(p1choice == 'P' || p1choice == 'p'){
        p1.outputBoard();
        Ships s1 = p1.fleet[0];
        Ships s2 = p1.fleet[1];
        Ships s3 = p1.fleet[2];
        Ships s4 = p1.fleet[3];

        cout << endl << endl;
        cout << "# OF TRIES: " << userTries << " /20" << endl;

        int gameCount = 0;
        while(gameCount < 1){
            if((s1.isShipSunken == true) && (s2.isShipSunken == true) && (s3.isShipSunken == true) && (s4.isShipSunken == true)){
                cout << "GAME OVER." << endl;
                cout << "YOU SUNK ALL THE SHIPS. CONGRATULATIONS! YOU'RE A BATTLESHIPS MASTER!" << endl;
                gameCount++;
            } else{
                int ship;
                ship = p1.userShot();
                userTries++;
                cout << endl << "# OF TRIES: " << userTries << " /20" << endl;
                if (ship == 5){
                    s1.shipIsHit();
                }
                else if (ship == 4) {
                    s2.shipIsHit();
                }
                else if (ship == 3) {
                    s3.shipIsHit();
                }
                else if (ship == 2) {
                    s4.shipIsHit();
                }
                p1.outputBoard();
                cout << endl;
                s1.displayHealth();
                s2.displayHealth();
                s3.displayHealth();
                s4.displayHealth();
            }
            if(userTries == maxAmountOfTries){
                cout << "YOU RAN OUT OF TRIES. YOU LOSE! BETTER LUCK NEXT TIME!" << endl;
                gameCount = 1;
            }
        }    
        cout << endl << endl << "You will be directed to the main menu..." << endl;
        gameplay(p1);
        if((p1choice == 'q') || p1choice == 'Q'){
            break;
        }
        break;
    }
    cout << "Exiting the program... " << endl;
}




int main(){
    srand(time(NULL));
    Board p1;
    gameplay(p1);


    return 0;
}
