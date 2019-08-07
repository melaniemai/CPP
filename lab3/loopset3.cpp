#include <iostream>

using namespace std;

int main()
{
    double startingPoint;

    cout << "For an input value of: ";
    cin >> startingPoint;
    cout << "Output is: " << endl;
    while(startingPoint >= 0.0) {
        cout << startingPoint;
        if(startingPoint == 0.0) {
            break;
        }
        startingPoint -= 0.5;
        cout << ",";
    }
    cout << endl;

    return 0;
}
