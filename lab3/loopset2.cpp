#include <iostream>

using namespace std;

int main()
{
    double avg;
    double sum = 0;
    double count;
    int counter = 0;
    int startIndex, endIndex,i;

    cout << "Starting Index: ";
    cin >> startIndex;
    cout << "Ending Index: ";
    cin >> endIndex;
    cout << "Step Count: ";
    cin >> count;

    for(i = startIndex; i <= endIndex; i += count){
        sum += i;
        counter += 1;
    }
    avg = sum / counter;


    cout << "SUM: " << sum << endl;
    cout << "AVERAGE: " << avg << endl;

    return 0;
}
