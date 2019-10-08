#include <iostream>
#include <cmath>

using namespace std;

// Making a class for Cube object
class Cylinder {
   public:
       // Default constuctor
       Cylinder() {
           radius = 0.0;
           height = 0.0;
       }

       // Override Constructor
       Cylinder(double aRadius, double aHeight){
           radius = aRadius;
           height = aHeight;
       }

       // Get radius
       double getRadius(){
           return radius;
       }

       // Get height
       double getHeight(){
           return height;
       }

       // Calculate SA
       double SurfaceArea(){
           return (2 * 3.14 * radius * (radius + height));
       }

       // Calculate Volume
       double Volume(){
           return (3.14 * pow(radius, 2) * height);
       }

       void display() {
           cout << "Surface Area: " << SurfaceArea() << endl;
           cout << "Volume: " << Volume() << endl;
       }


   private:
       double radius;
       double height;
};

int main()
{
   Cylinder cylinder1;
   cout << "Cylinder 1: Should have values 0 and 0" << endl;
   cylinder1.display(); // Should display SA: 0, Volume: 0
   cout << endl;

   Cylinder cylinder2(5, 5);
   cout << "Cylinder 2: Should have values ~314.16 and ~392.7" << endl;
   cylinder2.display(); // Should display SA: ~314.16, Volume: ~392.7
   cout << endl;

   Cylinder cylinder3(1.6, 4.2);
   cout << "Cylinder 3: Should have values ~58.3 and ~33.7" << endl;
   cylinder3.display(); // Should display SA: ~58.31, Volume: ~33.78
   cout << endl;

   return 0;
}
