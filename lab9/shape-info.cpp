#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <sstream>
#include <functional>

using namespace std;

const double PI = 3.14159265359;

class Point {

   // cout implementation for Point class
   friend ostream & operator<<( ostream &output, const Point &P ){
       output << "x: " << P.x << " y: " << P.y;
       return output;
   }

   // cin implementation for Point class
   friend istream & operator>>( istream &input, Point &P ){
       input >> P.x >> P.y;
       return input;
   }

public:
   // Default constructor
   Point(){
       x = 0;
       y = 0;
   }

   // Override constructor
   Point(double in_x, double in_y){
       x = in_x;
       y = in_y;
   }

   // Setter
   double setXY(double in_x, double in_y){
       x = in_x;
       y = in_y;
   }

   // Getter, get value of x to use from private
   double getX(){
       return x;
   }

   // Getter, get value of y to use from private
   double getY(){
       return y;
   }

   Point operator + (Point P_in){
       return { x + P_in.getX(), y + P_in.getY()};
   }

   bool operator==(Point &rhs) {
       return (rhs.x == x && rhs.y == y);
   }

private:
   double x,y;
};

class Circle {
   // implement cout for Line classes objects
   friend ostream & operator<<( ostream &output, Circle &C ){
       if(C.objectCircle() == false){
           output /*<< "Point 1 (Center): " << C.P1 << endl << "Point 2 (Point on Circle): " << C.P2 << endl*/
                   << "Radius: " << C.radius() << " unit" << endl
                   << "Diameter: " << C.diameter() << " units" << endl
                   << "Area: " << C.area() << " sq units" << endl
                   << "Circumference: " << C.circumference() << " units" << endl;
       } else{
           output << "The object is not a circle." << endl;
       }
       return output;
   }

   // implement cin for Line classes objects
   friend istream & operator>>( istream &input, Circle &C ){
       input >> C.P1 >> C.P2;
       return input;
   }

public:

   // Default Constructor
   Circle(){
       Point P1(0,0);
       Point P2(0,0);
   }

   // Override constructor
   Circle(Point aP1, Point aP2){
       P1 = aP1;
       P2 = aP2;
   }

   // Sets argument points to P1 and P2
   void setCircle(Point& aP1, Point& aP2){
       P1 = aP1;
       P2 = aP2;
   }

   // Get center value
   Point getP1(){
       return P1;
   }

   // Get p1 value
   Point getP2(){
       return P2;
   }

   // Determine if a circle
   bool objectCircle(){
       // Check if points are the same
       if((compareFloats(P1.getX(), P2.getX())) && (compareFloats(P1.getY(), P2.getY()))){
           return true;
       } else{
           return false;
       }
   }

   // Determine radius using line distance formula
   double radius(){
       double r = 0;
       if(objectCircle() == true){
           return r;
       } else{
           r = sqrt(pow(P2.getX() - P1.getX(), 2) + pow(P2.getY() - P1.getY(), 2));
       }
       return r;
   }

   // Determine diameter
   double diameter(){
       double d = 0.0;
       if(objectCircle() == true){
           return d;
       } else{
           d = radius() * 2.0;
       }
       return d;
   }

   // Determine Area of circle
   double area(){
       double a = 0.0;
       if(objectCircle() == true){
           return a;
       } else{
           a = PI * radius() * radius();
       }
       return a;
   }

   // Determine circumference
   double circumference(){
       double c = 0.0;
       if(objectCircle() == true){
           return c;
       } else{
           c = 2 * PI * radius();
       }
       return c;
   }

   // Determine if two circles are the same
   bool sameCircle(Circle x){
       if(x.objectCircle() == false && (objectCircle() == false)){
           if(compareFloats(x.radius(), radius())){
               if(compareFloats(x.P1.getX(), P1.getX()) && (compareFloats(x.P1.getY(), P1.getY()))){
                   return true;
               }
           }
       }
       return false;
   }

   // Display info
   void display(){
       cout << "Radius: " << radius() << endl;
       cout << "Diameter: " << diameter() << endl;
       cout << "Area: " << area() << endl;
       cout << "Circumference: " << circumference() << endl;
   }

   // Comparing values of floats
   bool compareFloats(double firstFloat, double secondFloat, double epsilon = 0.000001){
       return (fabs(firstFloat - secondFloat) < epsilon);
   }

private:
   Point P1, P2;
};


class Triangle {
   // implement cout for Line classes objects
   friend ostream & operator<<( ostream &output, Triangle &T ){
       if(T.isObjectTriangle() == true){
           output /*<< "Point 1 (a): " << T.P1 << endl << "Point 2 (b): " << T.P2 << endl << "Point 3 (c): " << T.P3 << endl*/
                  << "Area of the triangle: " << T.area() << " sq. units " << endl
                  << "Perimeter of the triangle: " << T.perimeter() << " units" << endl;
           if(T.isEquilateralTriangle() == true){
               output << "The triangle is an Equilateral Triangle. " << endl;
           } else{
               output << "The triangle is not an Equilateral Triangle." << endl;
           }
       } else{
           output << "The object is not a triangle." << endl;
       }
       return output;
   }

  // implement cin for Line classes objects
  friend istream & operator>>( istream &input, Triangle &T ){
      input >> T.P1 >> T.P2 >> T.P3;
      return input;
  }

public:

  // Default Constructor
  Triangle(){
      Point P1(0,0);
      Point P2(0,0);
      Point P3(0,0);
  }

  // Override constructor
  Triangle(Point aP1, Point aP2, Point aP3){
      P1 = aP1;
      P2 = aP2;
      P3 = aP3;
  }

  // Sets argument points to P1 and P2
  void setTriangle(Point& aP1, Point& aP2, Point& aP3){
      P1 = aP1;
      P2 = aP2;
      P3 = aP3;
  }

  // Get P1 value
  Point getP1(){
      return P1;
  }

  // Get P2 value
  Point getP2(){
      return P2;
  }

  // Get P3 value
  Point getP3(){
      return P3;
  }

  bool operator == (Triangle &rhs){
      return (rhs.P1 == P1 && rhs.P2 == P2 && rhs.P3 == P3);
  }


  // Determine if object is a triangle
  bool isObjectTriangle(){
      double tri;
      tri = P1.getX()*(P2.getY()-P3.getY())+ P2.getX()*(P3.getY()-P1.getY()) + P3.getX()*(P1.getY()-P2.getY());
      if(tri == 0.0){
          return false; // not a triangle
      }else{
          return true;
      }
  }

  // Calculate area of a triangle
  double area(){
      double a = 0.0;
      double l1, l2, l3;
      double pp = 0.0;
      if(isObjectTriangle() == false){
          return a;
      } else{
          pp = perimeter() / 2;
          l1 = sqrt(pow((P2.getX() - P1.getX()), 2) + pow((P2.getY() - P1.getY()), 2));
          l2 = sqrt(pow((P3.getX() - P2.getX()), 2) + pow((P3.getY() - P2.getY()), 2));
          l3 = sqrt(pow((P3.getX() - P1.getX()), 2) + pow((P3.getY() - P1.getY()), 2));
          a = sqrt(pp*(pp-l1)*(pp-l2)*(pp-l3));
      }
      return a;
  }

  // Calculate perimeter of a triangle
  double perimeter(){
      double p = 0.0;
      double l1, l2, l3;
      if(isObjectTriangle() == false){
          return p;
      } else {
          l1 = sqrt(pow((P2.getX() - P1.getX()), 2) + pow((P2.getY() - P1.getY()), 2));
          l2 = sqrt(pow((P3.getX() - P2.getX()), 2) + pow((P3.getY() - P2.getY()), 2));
          l3 = sqrt(pow((P3.getX() - P1.getX()), 2) + pow((P3.getY() - P1.getY()), 2));
          p = l1 + l2 + l3;
      }
      return p;
  }

  // Determine if triangle is equilateral triangle
  bool isEquilateralTriangle(){
      double l1, l2, l3;
      if(isObjectTriangle() == false){
          return false;
      } else{
          l1 = sqrt(pow((P2.getX() - P1.getX()), 2) + pow((P2.getY() - P1.getY()), 2));
          l2 = sqrt(pow((P3.getX() - P2.getX()), 2) + pow((P3.getY() - P2.getY()), 2));
          l3 = sqrt(pow((P3.getX() - P1.getX()), 2) + pow((P3.getY() - P1.getY()), 2));
          if((compareFloats(l1, l2)) && (compareFloats(l2, l3)) && (compareFloats(l3, l1))){
              return true;
          } else{
              return false;
          }
      }
  }

  // Determine if both triangles are the same
  bool isBothTrianglesSame(Triangle x, Triangle y){
      if(x == y){
          return true;
      } else{
          return false;
      }
  }

  // Display info
  void display(){
      if(isObjectTriangle() == false){
          cout << "Not a triangle." << endl;
          cout << "Area: " << area() << endl;
          cout << "Perimeter: " << perimeter() << endl;
      } else {
          cout << "Object is a triangle." << endl;
          if(isEquilateralTriangle() == true){
              cout << "Object is an Equilateral Triangle." << endl;
          } else{
              cout << "Object is not an Equilateral Triangle." << endl;
          }
          cout << "Area: " << area() << endl;
          cout << "Perimeter: " << perimeter() << endl;

      }
  }

  // Comparing values of floats
  bool compareFloats(double firstFloat, double secondFloat, double epsilon = 0.000001){
      return (fabs(firstFloat - secondFloat) < epsilon);
  }

private:
  Point P1, P2, P3;
};


class Quad {
   // implement cout for Line classes objects
   friend ostream & operator<<( ostream &output, Quad &Q ){
       if(Q.collinearitytest() == true){
           output /*<< "Point 1 (a): " << Q.P1 << endl << "Point 2 (b): " << Q.P2 << endl << "Point 3 (c): " << Q.P3 << endl
                  << "Point 4 (d): " << Q.P4 << endl*/
                  << "The object is a Quadrilateral." << endl
                  << "Area of the Quadrilateral: " << Q.quadArea() << " sq. units" << endl;
       } else{
           output << "The object is not a Quadrilateral." << endl;
       }
       return output;
   }

   // implement cin for Line classes objects
   friend istream & operator>>( istream &input, Quad &Q ){
       input >> Q.P1 >> Q.P2 >> Q.P3 >> Q.P4;
       return input;
   }

public:

   // Default Constructor
   Quad(){
       Point P1(0,0);
       Point P2(0,0);
       Point P3(0,0);
       Point P4(0,0);
   }

   // Override constructor
   Quad(Point aP1, Point aP2, Point aP3, Point aP4){
       P1 = aP1;
       P2 = aP2;
       P3 = aP3;
       P4 = aP4;
   }

   // Sets argument points to P1 and P2
   void setXY2(Point& aP1, Point& aP2, Point& aP3, Point& aP4){
       P1 = aP1;
       P2 = aP2;
       P3 = aP3;
       P4 = aP4;
   }

   // Get P1 value
   Point getP1(){
       return P1;
   }

   // Get P2 value
   Point getP2(){
       return P2;
   }

   // Get P3 value
   Point getP3(){
       return P3;
   }

   // Get P4 value
   Point getP4(){
       return P4;
   }

   // Collinearity test (Determines if object is a quadrilateral or not)
   double collinearitytest(){
       double triad1, triad2, triad3, triad4;
       triad1 = P1.getX()*(P2.getY()-P3.getY()) + P2.getX()*(P3.getY()-P1.getY())+ P3.getX()*(P1.getY()-P2.getY());
       triad2 = P2.getX()*(P3.getY()-P4.getY()) + P3.getX()*(P4.getY()-P2.getY()) + P4.getX()*(P2.getY() - P3.getY());
       triad3 = P1.getX()*(P3.getY()-P4.getY())+ P3.getX()*(P4.getY()-P1.getY()) + P4.getX()*(P3.getY()-P1.getY());
       triad4 = P1.getX()*(P2.getY()-P4.getY())+ P2.getX()*(P4.getY()-P1.getY()) + P4.getX()*(P1.getY()-P2.getY());
       if(compareFloats(triad1, 0) || compareFloats(triad2, 0) || compareFloats(triad3, 0) || compareFloats(triad4, 0)){
           return false; // quad cannot be formed
       } else{
           return true;
       }
   }

   // Calculate quad area
   double quadArea(){
       double a = 0.0; double aa = 0.0;
       // Given formula
       a = fabs((P1.getX()*P2.getY())+(P2.getX()*P3.getY()) + (P3.getX()*P4.getY())+(P4.getX()*P1.getY())-(P2.getX()*P1.getY())-(P3.getX()*P2.getY())-(P4.getX()*P3.getY())-(P1.getX()*P4.getY()));
       aa = 0.5 * a;
       return aa;
   }

   // Display info
   void display(){
       if(collinearitytest() == false){
           cout << "Not a quadrilateral." << endl;
       } else{
           cout << "Object is a quadrilateral." << endl;
           cout << "Area: " << quadArea() << endl;
       }
   }

   // Compare floating point numbers
   bool compareFloats(double firstFloat, double secondFloat, double epsilonV = 0.000006){
       return (fabs(firstFloat - secondFloat) < epsilonV);
   }

private:
   Point P1, P2, P3, P4;
};


vector<double> breakupstring(string str){
   vector<double> numdata;
   stringstream ss;     //requires sstream library included
   ss << str;

   while(!ss.eof()){
       double temp;
       ss >> temp;
       numdata.push_back(temp);
   }

   return numdata;
}

int main(){
   ifstream infile;    // Input file stream
   infile.open("C:\\Users\\suong\\Downloads\\shapes.txt");

   ofstream outfile;   // Output file stream
   outfile.open("C:\\Users\\suong\\Downloads\\shapes-info.txt");

   vector<double> numbers;
   string incontent;

   while(getline(infile, incontent)){
       istringstream inSS(incontent);
       string spaces = " ";
       for(unsigned int i = 0; i < incontent.length(); i++){
           if(incontent.substr(i, 1) == " "){  // Check to see if space
               spaces += " ";
           }
       }
       numbers = breakupstring(incontent);

       if(spaces.length() == 4){
           outfile << "Sufficient coordinates input." << endl;
           Point P1(numbers.at(0), numbers.at(1));
           Point P2(numbers.at(2), numbers.at(3));
           Circle c(P1, P2);
           outfile << c << endl;
       } else if(spaces.length() == 6){
           outfile << "Sufficient coordinates input." << endl;
           Point P1(numbers.at(0), numbers.at(1));
           Point P2(numbers.at(2), numbers.at(3));
           Point P3(numbers.at(4), numbers.at(5));
           Triangle t(P1, P2, P3);
           outfile << t << endl;
       } else if(spaces.length() == 8){
           outfile << "Sufficient coordinates input." << endl;
           Point P1(numbers.at(0), numbers.at(1));
           Point P2(numbers.at(2), numbers.at(3));
           Point P3(numbers.at(4), numbers.at(5));
           Point P4(numbers.at(6), numbers.at(7));
           Quad q(P1, P2, P3, P4);
           outfile << q << endl;
       } else{
           outfile << "Sufficient coordinates NOT input." << endl;
       }
       outfile << endl;
   }


   if(!infile.eof()){
       cout << "Error reading file." << endl;
   } else{
       cout << "Reading was successful." << endl;
   }

   outfile.close();
   infile.close();


   return 0;
}
