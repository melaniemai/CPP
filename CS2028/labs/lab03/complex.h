#ifndef COMPLEX_H
#define COMPLEX_H

class Complex{
private:
    double real, imaginary;
    int type;
public:
    Complex();  // default constructor
    Complex(double a, double b);    // overloaded cartesian plane constructor
    Complex(double r, double angle, bool pOrC);   // overloaded polar complex plane

    double getReal();
    void setReal(double a);

    double getImag();
    void setImag(double b);

    double getR();
    void setR(double);

    double getAngle();
    void setAngle(double);

    void printComplex();
    void printPolar();

    void operator+ (Complex &right);
    void operator- (Complex &right);
    void operator* (double);
    void operator* (Complex &right);
    void operator/ (double);
    void operator/ (Complex &right);
    bool operator== (Complex &right);
};


#endif // COMPLEX_H
