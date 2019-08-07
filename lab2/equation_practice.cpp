#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    double a, b, c, d;
    double form1, form2, form3;

    cout << "Enter Four numbers: ";
    cin >> a >> b >> c >> d;

    form1 = (a + b + c) / (2*a*c);
    form2 = (pow(a,2)/b) + ((c/d)*(a+b));
    form3 = pow(a,2+b+c) + a - c + 4;

    cout << "Formula 1: " << form1 << endl;
    cout << "Formula 2: " << form2 << endl;
    cout << "Formula 3: " << form3 << endl;


}

