// Author: Fill name in here
// Source File: myComplex.cpp
// Description: Implements complex number class, capable of doing typical
// operations using overloaded operators.

#include <iostream>
#include <cmath>
#include <sstream>

#include "myComplex.h"

using namespace std;

static const double eq_delta = 0.0001;

  myComplex::myComplex(){
    real = 0.0;
    imaginary = 0.0;
  }

  myComplex::myComplex(double in_real){
    setComplex(in_real, 0.0);
  }

  myComplex::myComplex(double in_real, double in_imaginary){
    setComplex(in_real, in_imaginary);
  }

  void myComplex::setReal(const double in_real){
    real = in_real;
  }

  void myComplex::setImaginary(const double in_imaginary){
    imaginary = in_imaginary;
  }

  void myComplex::setComplex(const double in_real, const double in_imaginary){
    setReal(in_real);
    setImaginary(in_imaginary);
  }

  double myComplex::getReal() const {
    return real;
  }

  double myComplex::getImaginary() const {
    return imaginary;
  }
  
  double myComplex::getMagnitude() const {
    return hypot(real, imaginary);
  }

  double myComplex::getAngle() const {
    //if(real == 0 && imaginary == 0) return 0;
    //return atan( imaginary/real)*180.0/3.1415927;
    return atan2( imaginary,real)*180.0/3.1415927;
  }

  void myComplex::displayPolar() const {
    cout << getMagnitude();
    cout << "@ "  << getAngle() << endl;
  }

//OPERATOR OVERLOAD TO COMPLETE IS BELOW
//OPERATOR OVERLOAD TO COMPLETE IS BELOW
//OPERATOR OVERLOAD TO COMPLETE IS BELOW
//OPERATOR OVERLOAD TO COMPLETE IS BELOW
//OPERATOR OVERLOAD TO COMPLETE IS BELOW
//OPERATOR OVERLOAD TO COMPLETE IS BELOW
//OPERATOR OVERLOAD TO COMPLETE IS BELOW
//OPERATOR OVERLOAD TO COMPLETE IS BELOW
//OPERATOR OVERLOAD TO COMPLETE IS BELOW
//OPERATOR OVERLOAD TO COMPLETE IS BELOW
  myComplex myComplex::addition(const myComplex &right) const{
    myComplex retval;

    retval.real = real + right.real;
    retval.imaginary = imaginary + right.imaginary;

    return retval;
    //HINT: LOOK TO SUBTRACTION OVERLOAD UNDERNEATH TO SEE HOW THIS SHOULD BE DONE.
  }

  myComplex myComplex::subtraction(const myComplex &right) const{
    myComplex retval;

    retval.real = real - right.real;
    retval.imaginary = imaginary - right.imaginary;

    return retval;
  }

  myComplex myComplex::multiplication(const myComplex &right) const{
    myComplex retval;

    retval.real     = real*right.real       - imaginary*right.imaginary;
    retval.imaginary  = imaginary * right.real  + real * right.imaginary;

    return retval;
  }

  myComplex myComplex::division(const myComplex &right) const{
    myComplex retval;
    double denom = right.real*right.real + right.imaginary*right.imaginary;

    retval.real    = (real*right.real + imaginary*right.imaginary)/denom;
    retval.imaginary = (imaginary*right.real - real*right.imaginary)/denom;

    return retval;
  }

  string myComplex::display() const{
    stringstream retval;
    retval << "(" << real << " + " << imaginary << "i)";
    return retval.str();
  }

  myComplex myComplex::operator+ (const myComplex& right){
    return(addition(right));
  }

  myComplex myComplex::operator- (const myComplex& right){
    return(subtraction(right));
  }

  myComplex myComplex::operator* (const myComplex& right){
    return(multiplication(right));
  }

  myComplex myComplex::operator/ (const myComplex& right){
    return(division(right));
  }

  myComplex myComplex::conjugate(){
    return myComplex(real, 0-imaginary);
  }

  bool myComplex::operator== (const myComplex& right){
    double diff_real = abs(real - right.real);
    double diff_im = abs(imaginary - right.imaginary);

    return diff_real < eq_delta && diff_im < eq_delta;
  }

  bool myComplex::operator!= (const myComplex& right){
    return !(*this == right);
  }

  
  
ostream& operator<<( ostream& output, const myComplex &thing ){
  output << thing.display();
  return output;
}
  
istream& operator>>( istream &input, myComplex &thing ){
  cout << "Enter Real Part: ";
  input >> thing.real;
  cout << "Enter Imaginary Part: ";
  input >> thing.imaginary;
  return input;
}

