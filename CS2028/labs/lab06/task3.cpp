#include <iostream>
#include <string>
#include <exception>

using namespace std;

class StackOverflow : public std::exception{
public:
    const char * what() const throw() override{
        return "Stack overflow.";
    }
};

class StackUnderflow : public std::exception{
public:
    const char * what() const throw() override{
        return "Stack underflow.";
    }
};

class Disk{
private:
    int player, size;
public:
    Disk();
    Disk(int p, int s);
    int getSize();
    void setSize(int si);
    int getPlayer();
    void setPlayer(int pl);
};


Disk::Disk(){
    player = 1;
    size = 1;
}

Disk::Disk(int s, int p){
    player = p;
    size = s;
}

int Disk::getPlayer(){
    return player;
}

void Disk::setPlayer(int pl){
    player = pl;
}

int Disk::getSize(){
    return size;
}

void Disk::setSize(int si){
    size = si;
}

template<class S>
class Stack{
private:
    int arraySize;
    int headValue = 0;
    S **stack;              // will become an array of pointers of arraySize
public:
    // constructors and member functions
    Stack();
    Stack(int size);
    int getArraySize();
    void push(S *ptr);
    S *pop();
    S *top();
    int length();
    void empty();
    void deleteWholeStack();
    S check(int i);
    bool full();

    template<class F>
    friend void printStack(Stack<F> *stack);
};


// Default constructor
template<class S>
Stack<S>::Stack(){
    arraySize = 0;
    headValue = 0;
}

// Overloaded constructor
template<class S>
Stack<S>::Stack(int size){
    arraySize = size;
    stack = new S *[size];
}

// Function accesses the value of the size of the array.
template<class S>
int Stack<S>::getArraySize(){
    return arraySize;
}

// Push function should accept a pointer and add that pointer to top of stack.
// Doesn't need to create any memory.
template<class S>
void Stack<S>::push(S *ptr){
    if(headValue == arraySize){
        throw StackOverflow();
    }
    stack[headValue] = ptr;
    headValue++;
}

// The pop function should return a pointer. It doesn't need to delete any memory.
template<class S>
S *Stack<S>::pop(){
    if(headValue == 0){
        throw StackUnderflow();
    }
    headValue--;
    return stack[headValue];
}

// The top function should return a pointer to the item on the top of the stack
// without removing it.
template<class S>
S *Stack<S>::top(){
    return stack[headValue - 1];
}

// The length function will return an int indicating the # of items in the stack.
template<class S>
int Stack<S>::length(){
    return headValue;
}

// The empty function should empty the stack of all contents. It needs to call
// delete to avoid memory leaks. It doesn't need to return any value.
template<class S>
void Stack<S>::empty(){
    for(int i = 0; i < arraySize; i++){
        delete stack[i];
    }
}

// This function deletes the whole stack when there's no contents in it.
template<class S>
void Stack<S>::deleteWholeStack(){
    empty();
    delete stack;
}

// Function checks value of headValue and returns the disk if the headValue
// isn't 0.
template<class S>
S Stack<S>::check(int i){
    if(headValue == 0){
        throw StackUnderflow();
    }
    return *stack[i];
}

template<class S>
bool Stack<S>::full(){
    return headValue == arraySize;
}


// The stack should declare a friend function that can access the underlying array
// for the purposes of printing it to the screen.
template<class S>
void printStack(Stack<S> *s){
    int arraySize = s->arraySize;
    int numOfDisks = s->headValue;
    string temp = "";
    string out = "";
    string extra = "";
    int sizeOfDisk, amountFilled;

    for(int i = arraySize; i >= 0; i--){
        extra = "";
        temp = "";
        if(numOfDisks <= i){
            sizeOfDisk = 0;
        } else{
            sizeOfDisk = s->check(i).getSize();
        }

        amountFilled = arraySize - sizeOfDisk;

        for(int j = 0; j < amountFilled; j++){
            extra += " ";
        }

        for(int x = 0; x < sizeOfDisk; x++){
            if(s->check(i).getPlayer() == 0){
                temp += "1";
            }
            else{
                temp += "2";
            }
        }

        out = out + extra + temp + "|" + temp + extra + "\n";
    }
    cout << out << endl << endl;
}


// Function creates initial tower. Fixed for 2 players.
void initialTower(Stack<Disk> *stacks[]){
    for(int i = stacks[0]->getArraySize(); i > 0; i--){
        Disk *p1 = new Disk(i, 0);        // Disk(size, player)
        Disk *p2 = new Disk(i, 1);
        // push disk from top of tower
        stacks[0]->push(p1);
        stacks[4]->push(p2);
    }
}

// Checks if the move the user wants to make is valid or not (can't move a large
// disk on a smaller disk.
bool valid(Stack<Disk> *stacks[], int destination, int origin, int player, int numD){
    if(stacks[destination - 1]->length() == 0){
        return true;
    }
    // empty stack
    else if(stacks[origin - 1]->length() == 0){
        cout << "No disk on stack " << origin << "!" << endl;
        return false;
    }
    // Check to see if disk is from correct player
    else if(stacks[origin - 1]->top()->getPlayer() != player){
        cout << "That piece isn't yours!" << endl;
        return false;
    } else if(stacks[destination - 1]->length() > numD){
        cout << "Stack " << destination << " is full!" << endl;
        return false;
    } else{
        // get top disk from the original stack
        int x = stacks[origin - 1]->top()->getSize();
        int y = stacks[destination - 1]->top()->getSize();

        // checks to make sure the disk being places on top is smaller than the
        // disk at the bottom of the stack.
        if(x > y){
            cout << "ERROR. You can't put a larger disc on a smaller disc." << endl;
            return false;
        }
        return true;
    }
}

// Function determines how player will make their moves.
void playermoves(Stack<Disk> *stacks[], int player, int numD){
    int origin, destination, takeFrom, putOn;
    bool validation;

    if(player == 0){
        cout << "Player 1 is denoted by number 1s:" << endl;
    }
    if(player == 1){
        cout << "Player 2 is denoted by number 2s:" << endl;
    }

    do{
        cout << "Enter stack to take disk from: ";
        cin >> takeFrom;
        cout << "Enter stack to put disk on: ";
        cin >> putOn;

        origin = takeFrom;
        destination = putOn;

        if(validation = valid(stacks, destination, origin, player, numD)){
            // place the disk from the original stack to the stack the user wants to place at
            stacks[destination - 1]->push(stacks[origin - 1]->pop());
        }
        else{
            cout << "" << endl;
        }
    } while(!validation);

}


int main(){
    int numOfDisks;
    bool game = true;
    cout << "Enter number of disks wanted for use: ";
    cin >> numOfDisks;

    // Create 5 towers since 2 on each side and 1 in middle
    Stack<Disk> *stack[5];
    Stack<Disk> *tOne = new Stack<Disk>(numOfDisks);
    Stack<Disk> *tTwo = new Stack<Disk>(numOfDisks);
    Stack<Disk> *tThree = new Stack<Disk>(numOfDisks);
    Stack<Disk> *tFour = new Stack<Disk>(numOfDisks);
    Stack<Disk> *tFive = new Stack<Disk>(numOfDisks);

    // Set each stack in each index as each new tower
    stack[0] = tOne; stack[1] = tTwo; stack[2] = tThree; stack[3] = tFour; stack[4] = tFive;

    initialTower(stack);

    int players = -1;

    do{
        players++;

        cout << endl << endl << endl << endl;

        printStack(stack[0]);
        printStack(stack[1]);
        printStack(stack[2]);
        printStack(stack[3]);
        printStack(stack[4]);

        playermoves(stack, players%2, numOfDisks);

        // Loop to determine winner of game.
        if(players == 1){
            for(int i = 0; i < 3; i++){
                if(stack[i]->full()){
                    for(int j = 0; j < stack[i]->getArraySize(); j++){
                        if(stack[i]->check(j).getPlayer() != 1 && j == (stack[i]->getArraySize()-1)){
                            cout << "Player 1 won!" << endl;
                            game = false;
                        }
                    }
                }
            }
        }
        else{
            for(int i = 3; i < 5; i++){
                if(stack[i]->full()){
                    for(int j = 0; j < stack[i]->getArraySize(); j++){
                        if(stack[i]->check(j).getPlayer() == 0 && (j == (stack[i]->getArraySize()-1))){
                            cout << "Player 2 won!" << endl;
                            game = false;
                        }
                    }
                }
            }
        }

    } while(game);




    return 0;
}
