#include <iostream>
#include <string>

using namespace std;

int main()
{
    double x, y;
    cout << "Enter X Y Pair: " << endl;
    cin >> x >> y;

    if (x == 0.0 && y == 0.0) {
        cout << "Center Point" << endl;
    }
    else if (x == 0.0 && y > 0.0) {
        cout << "On Y-Axis" << endl;
    }
    else if (x > 0.0 && y == 0.0) {
        cout << "On X-Axis" << endl;
    }
    else if (x > 0.0 && y > 0.0) {
        cout << "Quadrant is Q1" << endl;
    }
    else if (x < 0.0 && y > 0.0) {
        cout << "Quadrant is Q2" << endl;
    }
    else if (x < 0.0 && y < 0.0) {
        cout << "Quadrant is Q3" << endl;
    }
    else if (x > 0.0 && y < 0.0) {
        cout << "Quadrant is Q4" << endl;
    }

    return 0;
}

