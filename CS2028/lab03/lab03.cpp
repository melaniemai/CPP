#include <iostream>
#include <complex.h>
#include <string>

using namespace std;

int main()
{
    Complex c1, c2;
    double x = 0;
    double y = 0;
    double a = 0;
    double b = 0;
    string operation = "=";
    char complexOrScalar = 'a';
    bool cont = true;
    char contin;
    double scalarvalue = 0;
    string equal = "True";

    // prompt user to input values
    cout << "Enter value for x: ";
    cin >> x;
    cout << "Enter value for y: ";
    cin >> y;

    // instantiate object and path through constructor
    c1 = Complex(x, y);


    // enter loop for operation performance
    while(cont) {
        cout << "Enter operation to be performed: (+, -, *, /, ==): ";
        cin >> operation;
        cout << "Would you like to calculate with a scalar or another complex number? (s or c): ";
        cin >> complexOrScalar;

        if(complexOrScalar == 's' || complexOrScalar == 'S'){
            cout << "Enter scalar value: ";
            cin >> scalarvalue;
            c2 = Complex(scalarvalue, 0);
        } else if(complexOrScalar == 'C' || complexOrScalar == 'c'){
            cout << "Enter another value for x: ";
            cin >> a;
            cout << "Enter another value for y: ";
            cin >> b;
            c2 = Complex(a, b);
        } else {
            cout << "Error. Invalid input.";
        }


        // rest of the operations
        if(operation == "+"){
            c1 + c2;
        } else if(operation == "-"){
            c1 - c2;
        } else if(operation == "*"){
            c1 * c2;
        } else if(operation == "/"){
            c1 / c2;
        } else if(operation == "=="){
            scalarvalue = 0;
            if(c1 == c2){
                cout << "They are the same." << endl;
            } else{
                cout << "They are not the same." << endl;
            }
        } else{
            cout << "Error. Invalid operator." << endl;
        }

        cout << endl;

        // print out in fancy way
        cout << "In Cartesian form: " << endl;
        cout << "X " << operation << " Y = ";
        c1.printComplex();
        cout << endl;
        cout << "In Polar form: " << endl;
        c1.printPolar();


        // user should be able to continue with calculations if necessary
        cout << "Would you like to continue? (Y or N): ";
        cin >> contin;

        if(contin == 'N' || contin == 'n'){
            cont = false;
        }
    }


    return 0;
}
