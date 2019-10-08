// Melanie Mai - DONE

#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <cmath>

using namespace std;

const double epsilon = 0.0000001;

// Please replace this Point class with your version from Part B
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

class Triangle {
  // implement cout for Line classes objects
  friend ostream & operator<<( ostream &output, const Triangle &T ){
      output << "Point 1 (a): " << T.P1 << endl << "Point 2 (b): " << T.P2 << endl << "Point 3 (c): " << T.P3;
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
          return false;
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
          if((l1 == l2) && (l2 == l3) && (l3 == l1)){
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

private:
  Point P1, P2, P3;
};

int main(){
  Triangle T1; Triangle T2;
  // Triangle L2(5,6,7,8);

  cout << "Enter Three Points: ";
  cin >> T1;
  cout << T1 << endl;
  T1.display();



  cout << "Enter another Three Points: ";
  cin >> T2;
  cout << T2 << endl;
  T2.display();

  cout << endl;

  // Check if T1 and T2 are triangles to check if they are the same
  if(T1.isObjectTriangle() == true && (T2.isObjectTriangle() == true)){
      if(T2.isBothTrianglesSame(T1, T2) == true){
          cout << "Triangles are the same." << endl;
      }
  } else{
      cout << "Cannot compare triangles." << endl;
  }

  return 0;
}
