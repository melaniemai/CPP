#include <iostream>
#include <string>

using namespace std;

template<class S>
class Stack{
private:
    int arraySize;
    int headValue = 0;
    S **stack;              // will become an array of pointers of arraySize
public:
    // overflow and underflow exceptions
    class StackOverflow{
    private:
        int num;
    public:
        StackOverflow(int n){
            num = n;
        }
        int getNum(){
            return num;
        }
    };

    class StackUnderflow{
    private:
        int num;
    public:
        StackUnderflow(int n){
            num = n;
        }
        int getNum(){
            return num;
        }
    };

    // constructors and member functions
    Stack();
    Stack(int size);
    int getArraySize();
    void setArraySize(int);
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

// Function mutates the value of the array size.
template<class S>
void Stack<S>::setArraySize(int s){
    arraySize = s;
}

// Push function should accept a pointer and add that pointer to top of stack.
// Doesn't need to create any memory.
template<class S>
void Stack<S>::push(S *ptr){
    if(headValue == arraySize){
        throw StackOverflow(headValue);
    }
    stack[headValue] = ptr;
    headValue++;
}

// The pop function should return a pointer. It doesn't need to delete any memory.
template<class S>
S *Stack<S>::pop(){
    if(headValue == 0){
        throw StackUnderflow(headValue);
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
        throw StackUnderflow(headValue);
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
        }
        else{
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

//int main(){
//    cout << "Towers of Hanoi game." << endl;
//    return 0;
//}
