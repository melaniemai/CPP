#include <iostream>

using namespace std;

int main()
{
    int column, row;

    cout << "Width: ";
    cin >> row;
    cout << "Height: ";
    cin >> column;

    for(int i = 0; i < column; i++){
        for(int j = 0; j < row; j++){
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}
