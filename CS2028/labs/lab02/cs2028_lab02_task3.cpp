// Melanie Mai, Neha Chawla
// This program produces a sales report for DLC, Inc.
#include <iostream>
#include <iomanip>
#include <fstream>
#include <array>
#include <string>
#include "cs2028_lab02_task03._class.h"

using namespace std;


// function to find the data after the colon
string productSubstring(string str){
    // find position of ": " using find()
    unsigned long long pos = str.find(": ");
    // copy substring after position
    string subStr = str.substr(pos + 1);
    return subStr;
}

void productOrder(Products p[], ofstream&);
void productTotals(Products p[], ofstream&);

int main()
{
    // create object p of 9 elements
    Products p[9];

    ifstream infile;
    ofstream outfile;
    string inputfile, outputfile;
    string line;        // keep track of each line in the file
    bool check;         // variable to be used to check whether the inputfile is okay
    int i = 0;          // array position
    string colon = ": ";    // will be used to navigate through the text file. we'll get the data after the colon
    int pID, pUnits;        // variables for product ID and units
    double pPrice;          // variable for product prices
    string pDescription;    // varible for product descriptions
    string pTax;              // variable for product tax


    // ask for file and check if file exists/if it can be opened
    do {
        cout << "Enter the input file/path: ";
        cin >> inputfile;
        infile.open(inputfile, ios::in);
        check = infile.good();
        if(check == false){
            cout << "There was an error with the file. The file may not exist." << endl;
        }
        infile.close();

    } while(!check);

    // open inputfile again since it was closed
    infile.open(inputfile);
    getline(infile, line);

    // check if entered text file is empty
    if(infile.peek() == EOF){
        cout << "File is empty." << endl;
    }


    // iterate through while number of elements (i) is still less than 9
    while(i < 9){
        // check to see if there enough values for each element in array
        if(infile.eof() && i < 9){
            cout << "The file doesn't have enought values." << endl;
            break;
        }

        pID = stoi(productSubstring(line));         // convert string to int
        getline(infile, line);
        pUnits = stoi(productSubstring(line));      // convert string to int
        getline(infile, line);
        pPrice = stod(productSubstring(line));      // convert string to double
        getline(infile, line);
        pDescription = productSubstring(line);
        getline(infile, line);
        pTax = productSubstring(line);

        p[i].setID(pID);
        cout << p[i].getID() << endl;
        p[i].setUnits(pUnits);
        cout << p[i].getUnits() << endl;
        p[i].setPrices(pPrice);
        cout << p[i].getPrices() << endl;
        p[i].setDesc(pDescription);
        cout << p[i].getDesc() << endl;
        p[i].setTaxStr(pTax);
        cout << p[i].getTaxStr() << endl << endl;

        getline(infile, line);                      // skips blank line in text file
        getline(infile, line);

        i++;        // increases iteration by 1
    }

    infile.close();

    // Ask for output file
    cout << "Enter output file/path: ";
    cin >> outputfile;
    outfile.open(outputfile, ios::app);

    // Set the numeric output formatting.
    cout << setprecision(2) << fixed << showpoint;  // Taken from Lab1, Task3

    productOrder(p, outfile);
    productTotals(p, outfile);

    outfile.close();
    return 0;
}

//****************************************************************
// Definition of productOrder function. Accepts Product object   *
// array and output file. The function first displays a heading, *
// then the product numbers and sales.                           *
//****************************************************************
void productOrder(Products p[], ofstream& ofile){
    int num = 9;
    ofile << "Product Number\tSales\n";
    ofile << "----------------------------------\n";
    for (int index = 0; index < num; index++)
    {
        ofile << p[index].getID() << "\t\t$";
        ofile << setw(8) << p[index].getSales() << endl;
    }
    ofile << endl;
}

//****************************************************************
// Definition of productTotals function. Accepts Product object  *
// array and output file. The function first calculates the      *
// total units (of all products) sold and the total sales. It    *
// then displays these amounts.                                  *
//****************************************************************
void productTotals(Products p[], ofstream& ofile){
    int num = 9;
    int totalUnits = 0;
    double totalSales = 0.0;


    for (int index = 0; index < num; index++)
      {
         totalUnits += p[index].getUnits();
         totalSales += p[index].getSales();
      }
      ofile << "Total units Sold:  " << totalUnits << endl;
      ofile << "Total sales:      $" << totalSales << endl;
}
