// Melanie Mai

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
   Point(int in_x, int in_y){
       x = in_x;
       y = in_y;
   }

   // Setter
   double setXY(int in_x, int in_y){
       x = in_x;
       y = in_y;
   }

   // Getter, get value of x to use from private
   int getX(){
       return x;
   }

   // Getter, get value of y to use from private
   int getY(){
       return y;
   }

private:
   int x,y;
};

class Line {
   // implement cout for Line classes objects
   friend ostream & operator<<( ostream &output, const Line &L ){
       output << "Point 1: " << L.P1 << endl << "Point 2: " << L.P2;
       return output;
   }

   // implement cin for Line classes objects
   friend istream & operator>>( istream &input, Line &L ){
       input >> L.P1 >> L.P2;
       return input;
   }

public:

   // Default Constructor
   Line(){
       Point P1(0,0);
       Point P2(0,0);
   }

   // Override constructor
   Line(Point aP1, Point aP2){
       P1 = aP1;
       P2 = aP2;
   }

   // Sets argument points to P1 and P2
   void setXY2(Point& aP1, Point& aP2){
       P1 = aP1;
       P2 = aP2;
   }

   // Get P1 value
   Point getP1(){
       return P1;
   }

   // Get P2 value
   Point getP2(){
       return P2;
   }

   // Calculate slope based off of point values
   double slope(){
       double slope;
       if(static_cast<double>(P2.getX()) ==  static_cast<double>(P1.getX())){
           slope = 0.0;
       } else {
           slope = ((P2.getY() - P1.getY() / (P2.getX() - P1.getX())));
       }
       return slope;
   }

   // Calculate length of a line
   double length(){
       double len;
       len = sqrt(pow((P2.getX() - P1.getX()), 2) + pow((P2.getY() - P1.getY()), 2));
       return len;
   }

   // Calculate the y-intercept of a line
   double yint(){
       double b;
       if(slope() == -999999) {
           b = -999999;
       } else {
           b = (P1.getY() - (slope() * P1.getX()));
       }
       return b;
   }

   // Determines if line is horizontal
   bool horizontal(){
       // compare y values
       if(P1.getY() == P2.getY()){
           return true;
       } else {
           return false;
       }
   }

   // Determine if line is vertical
   bool vertical(){
       // vertical if no slope
       if((P2.getX() - P1.getX()) == 0){
           return true;
       } else{
           return false;
       }
   }

   // Determines whether lines are parallel
   bool parallel(Line x){
       if((x.vertical() == true) && (vertical() == true)){
           return true;
       } else{
           return (slope() == x.slope());
       }
   }

   // Display data
   void display(){
       cout << "Slope: " << slope() << endl;
       cout << "Length: " << length() << endl;
       cout << "y-intercept: " << yint() << endl;
   }


private:
   Point P1, P2;
};

int main(){
   Line L1; Line L2;
   // Line L2(5,6,7,8);
   cout << "L1: should have all zeros for values" << endl;
   cout << L1 << endl;

   cout << "Enter Two Points For Line: ";
   cin >> L1;
   cout << L1 << endl;
   L1.display();

   if(L1.vertical()){
       cout << "The line is vertical." << endl;
   } else{
       cout << "The line isn't vertical." << endl;
   }

   if(L1.horizontal()){
       cout << "The line is horizontal." << endl;
   } else{
       cout << "The line isn't horizontal." << endl;
   }


   cout << "Enter Two Points for Line2: ";
   cin >> L2;
   cout << L2 << endl;
   L2.display();


   if(L2.vertical()){
       cout << "The line is vertical." << endl;
   } else{
       cout << "The line isn't vertical." << endl;
   }

   if(L2.horizontal()){
       cout << "The line is horizontal." << endl;
   } else{
       cout << "The line isn't horizontal." << endl;
   }

   if(L1.parallel(L2)){
       cout << "Lines 1 and 2 are parallel to one another." << endl;
   } else{
       cout << "Lines 1 and 2 are not parallel to one another." << endl;
   }



   return 0;
}
