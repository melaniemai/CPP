#include <iostream>
using namespace std;

int main() {

   int edge, volume, surfaceArea;

   cout << "Enter Edge Length: ";
   cin >> edge;

   volume = edge * edge * edge;

   cout << "Volume: " << volume;

   surfaceArea = 6 * (edge * edge);

   cout << "Surface Area: " << surfaceArea;

   return 0;
}
