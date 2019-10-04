// This program demonstrates a two-dimensional array.
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
    ofstream myfile;
    myfile.open("lab2t2.txt", ios::app | ios::out);
  
    const int NUM_DIVS = 3;           // Number of divisions
    const int NUM_QTRS = 4;           // Number of quarters
    double sales[NUM_DIVS][NUM_QTRS]; // Array with 3 rows and 4 columns.
    double totalSales = 0;            // To hold the total sales.
    int div, qtr;                     // Loop counters.

    cout<< "This program will calculate the total sales of\n";
    cout<< "all the company's divisions.\n";
    cout<< "Enter the following sales information:\n\n";

    // Nested loops to fill the array with quarterly
    // sales figures for each division.
    for (div = 0; div < NUM_DIVS; div++)
    {
        for (qtr = 0; qtr < NUM_QTRS; qtr++)
        {
            cout<< "Division " << (div + 1);
            cout<< ", Quarter " << (qtr + 1) << ": $";
            cin >> sales[div][qtr];
            totalSales = totalSales + sales[div][qtr];
        }
        cout<< endl; // Print blank line.
    }

    myfile<< fixed << showpoint << setprecision(2);
    myfile<< "The sales for the company is: $" << totalSales << endl;
    myfile<< "Div" << "\t" << "Q1" << "\t" << "Q2" << "\t" << "Q3" << "\t" << "Q4" << endl;


    // Nested loops to display the quarterly sales figures for each division.
    for (div = 0; div < NUM_DIVS; div++)
    {
        myfile<< div + 1 << "\t";
        for (qtr = 0; qtr < NUM_QTRS; qtr++)
        {
            myfile<< "$" << sales[div][qtr] << "\t";
        }
        myfile<< endl; // Print blank line.
    }

    myfile<< endl;
    myfile<< "The total sales for the company are: $";
    myfile<< totalSales << endl;
    return 0;
}
