#include <iostream>
using namespace std;

int main() {

   int width, height, area, perimeter;

   cout << "Width: ";
   cin >> width;

   cout << "Height: ";
   cin >> height;

   area = width * height;
   perimeter = 2*(width + height);

   cout << "Area: " << area << endl;
   cout << "Perimeter: " << perimeter << endl;


   return 0;
}
