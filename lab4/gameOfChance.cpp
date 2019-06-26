// RECIEVED HELP FROM TA GEET TRIPATHI

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


// Generates a random number between 1 and 6 for the die roll.
int rollDie() {
    return (rand() % 6) + 1;
}

// Determines if player won game by comparing point value and value of the die rolled. Returns true if match, false if otherwise.
bool playOneGame(){
    bool winner = true;
    int point = 0;
    cout << endl;
    cout << "Enter your point value (1-6): ";
    cin >> point;
    while(point > 6 || point < 1){  // Check whether point value is within 1 and 6
        cout << "Error: Enter your point value, must be between 1 and 6: ";
        cin >> point;
    }
    int rollNum = 1; int rollValue = 0;
    while(point != rollValue && rollNum < 4){
        rollValue = rollDie();
        cout << "Roll #" << rollNum << " is " << rollValue << endl;
        rollNum++;
    }
    if(point == rollValue){
        winner = true;  // Values match so winner is set to true
    } else {
        winner = false;
    }
    return winner;
}


// Outputs message to player if they won wager money. Doesn't return value.
void winnerMessage(){
    cout << "** You win! **" << endl;
}

// Outputs message to player if they lost wager money. Doesn't return value.
void loserMessage(){
    cout << "** You lose! **" << endl;
}

// Calculates account balance when player won wager money.
double wonWager(double accountBalance, double wager){
    return (accountBalance + wager);
}

// Calculates account balance when player lost wager money.
double loseWager(double accountBalance, double wager){
    return (accountBalance - wager);
}

int main()
{
    double wins = 0; // Counter for amount of games won
    int totalPlays = 0; // Counter for amount of times user has played
    double accountBalance = 100.0; // Bank account balance
    double wager = 0.0; // Wager, player bet
    double percentage = 0.0;
    bool winner = 0;
    bool game = true;

    srand(time(NULL)); // Seeds random number

    do {
        cout << "Account balance $" << accountBalance << endl;
        cout << "Enter wager (0 to exit): ";
        cin >> wager;
        if(wager == 0.0){
            game = false;
            break;
        }

        while(wager < 0 || wager > 100){ // Check if wager is less than 0 or greater than 100.
            cout << "Error: You must enter a wager between $1 and $100: ";
            cin >> wager;
        }

        if(wager == 0.0){
            game = false; // When user enters 0, bool game will be changed to false and exit do-while loop to end game
            break;
        }
        winner = playOneGame(); // Call function

        if(winner){
            winnerMessage();
            wins++;
            accountBalance = wonWager(accountBalance, wager);
        } else{
            loserMessage();
            accountBalance = loseWager(accountBalance, wager);
        }
        totalPlays++;

        if(accountBalance == 0.0){ // Check whether or not player account balance has reached $0
            game = false;
            break;
        }

    } while(!false);
    percentage = (wins / totalPlays) * 100; // Game stats

    if(wager == 0.0){ // Game stats when player hasn't won any game
        percentage = 0.0;
    }

    cout << "Your final account balance is $" << accountBalance << endl;
    cout << "You won " << wins << " time(s) out of " << totalPlays << " for a winning percentage of " << percentage << "%" << endl;


    return 0;

}
