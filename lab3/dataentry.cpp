#include <iostream>

using namespace std;

int main()
{
    float guess;
    float sum = 0;

    do {
        cout << "Enter Positive Number to Add or Enter Zero or Negative Number to End: ";
        cin >> guess;
        if(guess > 0){
            sum += guess;
        }
    } while(!(guess <= 0));

    cout << "Sum of Entered Numbers: " << sum << endl;

    return 0;
}
