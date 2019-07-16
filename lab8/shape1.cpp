#include <iostream>
#include <cmath>

using namespace std;

// Making a class for Cube object
class Cube {
    public:
        // Default constuctor
        Cube() {
            edge = 0.0;
        }

        // Override constructor
        Cube(double aEdge){
            edge = aEdge;
        }

        // Calculate SA
        double SurfaceArea(){
            return pow(edge, 2) * 6;
        }

        // Calculate Volume
        double Volume(){
            return pow(edge, 3);
        }

        void display() {
            cout << "Surface Area: " << SurfaceArea() << endl;
            cout << "Volume: " << Volume() << endl;
        }


    private:
        double edge;
};

int main()
{
    Cube cube1; // Should return edge is 0.0 SA and Vol is 0
    cout << "Cube 1: Should have values 0 and 0" << endl;
    cube1.display();
    cout << endl;

    Cube cube2(5); // Should return SA: 150, Vol: 125
    cout << "Cube 2: Should have values SA: 150 and V: 125 " << endl;
    cube2.display();
    cout << endl;

    Cube cube3(8.79); //Shouldd return SA: 463.5, Vol: 679.15
    cout << "Cube 3: Should have values SA: 463.5 and V: 679.15" << endl;
    cube3.display();
    cout << endl;




    return 0;
}
