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

struct Moves{
  int origin, destination;
};

template<class S>
class Stack{
private:
  int arraySize;
  int headValue;
  S **stack;
public:
  Stack();
  Stack(int size);
  int getArraySize();
  void push(S *ptr);
  S *pop();
  S *top();
  int length();
  void empty();
  bool isFull();
  
  friend void displayTower(Stack<int> &tower);
}
