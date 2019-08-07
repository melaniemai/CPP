#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double width = 0.0, tolerance = 0.0;
    int temp = 0;
    double x;
    cout << "Width: ";
    cin >> width;
    cout << "Tolerance: ";
    cin >> tolerance;
    cout << "Temperature\tWidth\tWithin Tolerance" << endl;

    for(temp = 60; temp <= 85; temp++){
        x = width + (temp - 70) * (0.0001);
        cout << temp << "\t\t" << fixed << setprecision(7) << x << "\t";
        if((x < width + tolerance) && (x > (width - tolerance))){
            cout << "*" << endl;
        }
        else {
            cout << endl;
        }
    }

    return 0;
}
