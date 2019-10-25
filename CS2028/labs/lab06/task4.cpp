#include <iostream>
#include <vector>
#include <string>
#include <exception>

using namespace std;

class QueueUnderflow : public std::exception{
public:
    const char * what() const throw() override{
        return "Queue underflow.";
    }
};

class StackUnderflow : public std::exception{
public:
    const char * what() const throw() override{
        return "Stack underflow.";
    }
};

class StackOverflow : public std::exception{
public:
    const char * what() const throw() override{
        return "Stack overflow.";
    }
};

// --------------------------------------------------------------------------------------------------

struct PlayerMoves{
    int origin, destination;
};

// --------------------------------------------------------------------------------------------------

template<class Q>
class Queue{
private:
    vector<Q> queue;
    int length;
public:
    Queue();
    int getLength();
    void enqueue(Q data);
    Q dequeue();

    friend void printPlayerMoves(Queue<PlayerMoves>& moves);
};

template<class Q>
Queue<Q>::Queue(){
    length = 0;
}

template<class Q>
int Queue<Q>::getLength(){
    return length;
}

template<class Q>
void Queue<Q>::enqueue(Q data){
    queue.insert(queue.begin(), data);
    length++;
}

template<class Q>
Q Queue<Q>::dequeue(){
    if(length <= 0){
        throw QueueUnderflow();
    }
    Q data = queue.back();
    queue.pop_back();
    length--;
    return data;
}

// ------------------------------------------------------------------------------------------------

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
    int sizeOfDisk;
    int amountFilled;

    for(int i = arraySize; i >= 0; i--){
        extra = "";
        temp = "";
        if(numOfDisks <= i){
            sizeOfDisk = 0;
        } else{
            sizeOfDisk = s->check(i);
        }

        amountFilled = arraySize - sizeOfDisk;

        for(int j = 0; j < amountFilled; j++){
            extra += " ";
        }

        for(int x = 0; x < sizeOfDisk; x++){
            temp += "=";
        }

        out = out + extra + temp + "|" + temp + extra + "\n";
    }
    cout << out << endl << endl;
}

// -------------------------------------------------------------------------------------------

// Function creates initial tower.
void initialTower(Stack<int> *stacks[]){
    for(int i = stacks[0]->getArraySize(); i > 0; i--){
        // push disk from top of tower
        stacks[0]->push(new int(i));
    }
}

// Checks if the move the user wants to make is valid or not (can't move a large
// disk on a smaller disk.
bool valid(Stack<int> *stacks[], int destination, int origin, int numDisc){
    // empty stack
    if(stacks[destination - 1]->length() == 0){
        return true;
    } else if(stacks[origin - 1]->length() == 0){
        cout << "No disc on stack " << origin << "!" << endl;
    } else if(stacks[destination - 1]->length() > numDisc){
        cout << "Stack " << destination << " is full!" << endl;
    } else{
        // get top disk from the original stack
        int x = *stacks[origin - 1]->top();
        int y = *stacks[destination - 1]->top();

        // checks to make sure the disk being places on top is smaller than the
        // disk at the bottom of the stack.
        if(x > y){
            cout << "ERROR. You can't put a larger piece on a smaller one." << endl;
            return false;
        }
        return true;
    }
}


// Function determines how player will make their moves.
void playermoves(int origin, int destination, Stack<int> *stacks[], int nDisc){
    if(valid(stacks, destination, origin, nDisc)){
    // place the disk from the original stack to the stack the user wants to place at
        stacks[destination - 1]->push(stacks[origin - 1]->pop());
    }
    else{
        cout << "" << endl;
    }

}

void printPlayerMoves(Queue<PlayerMoves>& moves){
    for(int i = 0; i < moves.getLength(); i++){
        PlayerMoves move = moves.dequeue();
        cout << "Move from peg " << move.origin << " to peg " << move.destination << endl;
    }
}

// -------------------------------------------------------------------------------------------

int main()
{
    int numOfDisks, origin, destination;
    cout << "Enter number of disks wanted for use: ";
    cin >> numOfDisks;

    // Create 3 towers
    Stack<int> *stack[3];
    Stack<int> *tOne = new Stack<int>(numOfDisks);
    Stack<int> *tTwo = new Stack<int>(numOfDisks);
    Stack<int> *tThree = new Stack<int>(numOfDisks);

    // Set each stack in each index as each new tower
    stack[0] = tOne;
    stack[1] = tTwo;
    stack[2] = tThree;

    Queue<PlayerMoves> moves;

    // Creates initial tower
    initialTower(stack);

    cout << "GOAL: Move all the discs to third stack." << endl;

    while (!stack[2]->full()) {
        cout << endl << endl << endl << endl;

        printStack(stack[0]);
        printStack(stack[1]);
        printStack(stack[2]);

        cout << "Enter stack to take disc from: ";
        cin >> origin;
        cout << "Enter stack to place disc on: ";
        cin >> destination;

        playermoves(origin, destination, stack, numOfDisks);

        moves.enqueue(PlayerMoves{origin, destination});
    }

    printStack(stack[0]);
    printStack(stack[1]);
    printStack(stack[2]);

    cout << "You got it!" << endl;
    cout << "Moves: " << moves.getLength() << endl;
    printPlayerMoves(moves);


    return 0;
}
