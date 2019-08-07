#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    double hours, minutes, temp, time;

    cout << "Enter Hours: ";
    cin >> hours;

    cout << "Enter Minutes: ";
    cin >> minutes;

    minutes = minutes / 60;

    time = hours + minutes;

    temp = (4*pow(time,2)) / (time + 2) - 20;

    cout << "Approximate Temperature: " << temp << endl;


}

