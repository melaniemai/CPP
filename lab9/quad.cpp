// Melanie Mai - DONE

#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <cmath>

using namespace std;

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
   int x,y;
};

class Quad {
   // implement cout for Line classes objects
   friend ostream & operator<<( ostream &output, const Quad &Q ){
       output << "Point 1 (a): " << Q.P1 << endl << "Point 2 (b): " << Q.P2 << endl << "Point 3 (c): " << Q.P3 << endl
              << "Point 4 (d): " << Q.P4;
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

int main(){
   Quad Q1; Quad Q2;
   // Quad L2(5,6,7,8);

   cout << "Enter Four Points (Q1): ";
   cin >> Q1;
   cout << Q1 << endl;
   Q1.display();

   cout << endl;

   cout << "Enter Four Points (Q2): ";
   cin >> Q2;
   cout << Q2 << endl;
   Q2.display();


   return 0;
}
