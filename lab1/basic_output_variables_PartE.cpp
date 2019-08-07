#include <iostream>
#include <string>

using namespace std;

int main()
{
    int userNum, userNum2, square, cubed, sum, product;

    cout << "Enter integer:" << endl;
    cin >> userNum;

    cout << "You entered: " << userNum << endl;

    square = userNum * userNum;
    cubed = userNum * userNum * userNum;

    cout << userNum << " squared is " << square << endl;
    cout << "And " << userNum << " cubed is " << cubed << "!!" << endl;

    cout << "Enter another integer:" << endl;
    cin >> userNum2;

    sum = userNum + userNum2;
    product = userNum * userNum2;

    cout << userNum << " + " << userNum2 << " is " << sum << endl;
    cout << userNum << " * " << userNum2 << " is " << product << endl;

    return 0;
}

