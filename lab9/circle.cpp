//// Melanie Mai - DONE

//#include <iostream>
//#include <string>
//#include <vector>
//#include <cctype>
//#include <cmath>

//using namespace std;

//const double PI = 3.14159265359;

//// Please replace this Point class with your version from Part B
//class Point {

//    // cout implementation for Point class
//    friend ostream & operator<<( ostream &output, const Point &P ){
//        output << "x: " << P.x << " y: " << P.y;
//        return output;
//    }

//    // cin implementation for Point class
//    friend istream & operator>>( istream &input, Point &P ){
//        input >> P.x >> P.y;
//        return input;
//    }

//public:
//    // Default constructor
//    Point(){
//        x = 0;
//        y = 0;
//    }

//    // Override constructor
//    Point(double in_x, double in_y){
//        x = in_x;
//        y = in_y;
//    }

//    // Setter
//    double setXY(double in_x, double in_y){
//        x = in_x;
//        y = in_y;
//    }

//    // Getter, get value of x to use from private
//    int getX(){
//        return x;
//    }

//    // Getter, get value of y to use from private
//    int getY(){
//        return y;
//    }

//    bool operator == (Point &rhs){
//        return (rhs.x == x && rhs.y == y);
//    }

//    Point operator + (Point P_in){
//        return { x + P_in.getX(), y + P_in.getY()};
//    }
//private:
//    double x,y;
//};

//class Circle {
//    // implement cout for Line classes objects
//    friend ostream & operator<<( ostream &output, const Circle &C ){
//        output << "Point 1 (Center): " << C.P1 << endl << "Point 2 (Point on Circle): " << C.P2;
//        return output;
//    }

//    // implement cin for Line classes objects
//    friend istream & operator>>( istream &input, Circle &C ){
//        input >> C.P1 >> C.P2;
//        return input;
//    }

//public:

//    // Default Constructor
//    Circle(){
//        Point P1(0,0);
//        Point P2(0,0);
//    }

//    // Override constructor
//    Circle(Point aP1, Point aP2){
//        P1 = aP1;
//        P2 = aP2;
//    }

//    // Sets argument points to P1 and P2
//    void setCircle(Point& aP1, Point& aP2){
//        P1 = aP1;
//        P2 = aP2;
//    }

//    // Get center value
//    Point getP1(){
//        return P1;
//    }

//    // Get p1 value
//    Point getP2(){
//        return P2;
//    }

//    // Determine if a circle
//    bool objectCircle(){
//        // Check if points are the same
//        if((P1.getX() == P2.getX()) && (P1.getY() == P2.getY())){
//            return true; // Not a circle
//        } else{
//            return false; // Object a circle
//        }
//    }

//    // Determine radius using line distance formula
//    double radius(){
//        double r = 0.0;
//        if(objectCircle() == true){
//            return r;
//        } else{
//            r = sqrt(pow(P1.getX() - P2.getX(), 2) + pow(P1.getY() - P2.getY(), 2 ));
//        }
//        return r;
//    }

//    // Determine diameter
//    double diameter(){
//        double d = 0.0;
//        if(objectCircle() == true){
//            return d;
//        } else{
//            d = radius() * radius();
//        }
//        return d;
//    }

//    // Determine Area of circle
//    double area(){
//        double a = 0.0;
//        if(objectCircle() == true){
//            return a;
//        } else{
//            a = PI * radius() * radius();
//        }
//        return a;
//    }

//    // Determine circumference
//    double circumference(){
//        double c = 0.0;
//        if(objectCircle() == true){
//            return c;
//        } else{
//            c = 2 * PI * radius();
//        }
//        return c;
//    }

//    // Determine if two circles are the same
//    bool sameCircle(Circle x){
//        if(x.objectCircle() == false && (objectCircle() == false)){
//            if(compareFloats(x.radius(), radius())){
//                if(x.P1.getX() == P1.getX() && (x.P1.getY()) == P1.getY()){
//                    return true;
//                }
//            }
//        }
//        return false;
//    }

//    // Display info
//    void display(){
//        cout << "Radius: " << radius() << endl;
//        cout << "Diameter: " << diameter() << endl;
//        cout << "Area: " << area() << endl;
//        cout << "Circumference: " << circumference() << endl;
//    }

//    // Comparing values of floats
//    bool compareFloats(double firstFloat, double secondFloat, double epsilon = 0.000001){
//        return (fabs(firstFloat - secondFloat) < epsilon);
//    }

//private:
//    Point P1, P2;
//};

//int main(){
//    Circle C1; Circle C2;
//    // Circle L2(5,6,7,8);

//    cout << "Enter Center Point and One point on circle: ";
//    cin >> C1;
//    cout << C1 << endl;
//    if(C1.objectCircle()){
//        cout << "Not a circle." << endl;
//    } else {
//        cout << "Object a circle." << endl;
//    }
//    C1.display();

//    cout << endl;

//    cout << "Enter Center Point and One point on circle: ";
//    cin >> C2;
//    cout << C2 << endl;
//    if(C2.objectCircle()){
//        cout << "Not a circle." << endl;
//    } else{
//        cout << "Object a circle." << endl;
//    }
//    C2.display();
//    cout << endl;


//    // Check if circles are the same or not
//    if(C1.sameCircle(C2)){
//        // Circles have the same center and radius
//        cout << "Same circles." << endl;
//    } else{
//        // One or two invalid circles
//        cout << "Not the same circles." << endl;
//    }




//    return 0;
//}
