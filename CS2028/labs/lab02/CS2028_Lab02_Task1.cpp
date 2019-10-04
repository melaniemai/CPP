#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream infile;    // input file stream
    ofstream outfile;   // output file stream
    string inputfile;
    string line;
    int num_lines = 0;

    cout << "Enter the input file: ";
    cin >> inputfile;
    infile.open(inputfile);     // open file from user

    // check if file can be opened
    while(!infile.is_open()){
        cout << "There was a problem opening the " << inputfile << " file." << endl;
        cout << "Check to see if file exists." << endl;
        cout << "Enter the input file: ";
        cin >> inputfile;

        infile.open(inputfile);
    }

    // read till end of file
    while((num_lines < 10) && getline(infile, line)){
        cout << line << endl;
        num_lines++;

    }

    infile.close();

}
