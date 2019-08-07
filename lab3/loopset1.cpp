#include <iostream>

using namespace std;

int main()
{
    double avg = 0;
    double sum = 0;
    double count = 0;
    int i = 2;
    for(i = 2; i <= 35; i+=3){
        sum = sum + i;
        count += 1;
    }
    avg = sum/count;

    cout << "SUM: " << sum << endl;
    cout << "AVERAGE: " << avg << endl;

    return 0;
}
