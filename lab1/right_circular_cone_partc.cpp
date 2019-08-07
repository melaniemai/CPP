#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.14159265359;

int main() {

   double radius, height, surfaceArea, volume;

   cout << "Radius: ";
   cin >> radius;

   cout << "Height: ";
   cin >> height;

   surfaceArea = (PI * radius) * (radius + sqrt(pow(height,2) + pow(radius,2)));

   cout << "Surface Area: " << surfaceArea;

   volume = (PI * pow(radius,2)) * (height / 3);

   cout << "Volume: " << volume;
   return 0;
}
