// Description: A simple program that prints a user-input x 12 multiplication table.
// @author Melanie Mai
// @version 20190505

#include <iostream>
using namespace std;

int main() {
  int usernum;
  cout << "Enter a number: ";
  cin >> usernum;
  cout << " 1\t2\t3\t4\t5\t6\t7\t8\t9\t10\t11\t12" << endl << "" << endl;
  for (int i = 1; i < (usernum+1); i++) {
    cout << i << "| ";
    for (int j = 1; j < 13; j++) {
      cout << j * i << '\t';
    }
    cout << endl;
  }

  return 0;
}
