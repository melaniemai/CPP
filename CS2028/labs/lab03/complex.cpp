#include <iostream>
#include <cmath>
#include <string>
#include "complex.h"

using namespace std;

const double PI = 3.1415926535897;

// default constructor
Complex::Complex(){
    this->real = 0.0;
    this->imaginary = 0.0;
    this->type = 0;
}

// overloaded constructor for cartesian
Complex::Complex(double a, double b){
    this->real = a;
    this->imaginary = b;
}

// overloaded constructor for polar
Complex::Complex(double r, double phi, bool pOrC){
    real = r * cos(phi);
    imaginary = r * sin(phi);
}

// accessor for real number
double Complex::getReal(){
    return real;
}

// setter for real number
void Complex::setReal(double a){
    real = a;
}

// accessor for imaginary number
double Complex::getImag(){
    return imaginary;
}

// setter for imaginary number
void Complex::setImag(double b){
    imaginary = b;
}

// display cartesian form
void Complex::printComplex(){
    cout << "z: " << real << " + " << imaginary << "i" << endl;
}

// r = radius
double Complex::getR(){
    double r = pow(real,2) + pow(imaginary, 2);
    return sqrt(r);
}

// angle = phi
double Complex::getAngle(){
    // calculate angles based on possible values of real and imaginary values
    if(real == 0.0 && imaginary == 0.0){
        cout << "Error - there is no polar representation of value 0." << endl;
        return 0;
    }

    double angle = atan(real/imaginary) * (180/PI);
    return angle;
}

// display results in polar form
void Complex::printPolar(){
    cout << getR() << " + " << getImag() << "i" << endl;
}

// + operators -- updates the contents of that instance
void Complex::operator+(Complex &right){
    setReal(real + right.getReal());
    setImag(imaginary + right.getImag());
}

// - operator -- updates the contents of that instance
void Complex::operator-(Complex &right){
    setReal(real - right.getReal());
    setImag(imaginary - right.getImag());
}

// * operator -- scalar multiplication
void Complex::operator*(double h){
    setReal(real * h);
    setImag(imaginary * h);
}

void Complex::operator*(Complex &right){
    setReal(real * right.getReal());
    setImag(imaginary * right.getImag());
}

// / operation -- scalar division
void Complex::operator/(double d){
//    real = real / d;
//    imaginary = imaginary / d;
    setReal(real / d);
    setImag(imaginary / d);
}

void Complex::operator/(Complex &right){
    setReal(real / right.getReal());
    setImag(imaginary / right.getImag());
}

// == operation -- checks if value is equivalent
bool Complex::operator==(Complex &right){
    double diff = 0.00001;
    double real2 = real - right.getReal();
    double imag = imaginary - right.getImag();
    if(abs(real2) <= diff && abs(imag) <= diff){
        return true;
    } else{
        return false;
    }
}
