#include <iostream>

using namespace std;

int main()
{
    double V0 = 0; // intitial velocity in m/s
    const double G = 9.8; // gravitational constant in m/s^2
    int time = 0; // current time in seconds
    int time2 = 0;
    double max = 0.0;
    double height = ((V0 * time) - (0.5 * G * (time * time)));

    cout << "Enter Initial V0: ";
    cin >> V0;

    cout << "Initial Velocity of Object: " << V0 << "-m/s" << endl;
    cout << "Time\tHeight" << endl;


    do {
        if (V0 == 0.0){
            height = ((V0 * time) - (0.5 * G * (time * time)));
            cout << time << "\t" << height << endl;
            time++;
            height = ((V0 * time) - (0.5 * G * (time * time)));
            cout << time << "\t" << height <<  endl;
            if(height > max) {
                max = height;
            }
            break;
        }

        time++;
        height = ((V0 * time) - (0.5 * G * (time * time)));
        cout << time << "\t" << height << endl;
        if(height > max) {
            max = height;
            time2 = time;
        }
    } while (!(height <= 0));

    if(time == 1) {
        cout << "Total Time: " << time -1 << "-seconds" << endl;
        cout << "Maximum Height: " << max << " @ " << time-1 << "-seconds" << endl;
    } else {
        cout << "Total Time: " << time << "-seconds" << endl;
        cout << "Maximum Height: " << max << " @ " << time2 << "-seconds" << endl;
    }

    return 0;
}
