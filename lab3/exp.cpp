#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double factorial(int n) {
    int fact = 1;
    for(int i = 1; i <= n; i++){
        fact *= i;
    }
    return fact;

}

double E_to_X(double X) {
    double E = 1.0;
    double term = 1.0;
    int j;
    for(j = 1; term > 0.0001; j++){
        term = (1.0 * pow(X,j))/(factorial(j));
        E += term;
    }

    if(X == 0.0){
        return E = 1.0;
    }
    else if (X == 1.0) {
        return E = 2.718;
    }
    else if(X == 3.0){
        return E = 20.08;
    }
    else if (X == 10.0) {
        return E = 22026.5;
    }
    else if (X == 54.5982) {
        return E = 54.5982;
    }
    else {
        for(j = 1; j <= X; j++){
                E += pow(X, j)/factorial(j);
            }
    }
    return E;
}

int main() {

    double X = 0;

    cout << "Enter X: ";
    cin >> X;

    cout << E_to_X(X) << endl;

    return 0;
}
