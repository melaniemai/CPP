#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

struct Book{
    string Title;
    string Author;
    string AuthorFirstN;
    string AuthorLastN;
    int WordCount = 0;
    int LetterFrequency[26];
    int LineCount = 0;
};

static string inputfile;
static int linecount = 0;
static int wordcount = 0;

// function to get user to input filename and attempt to open file
void openInputFile(ifstream& infile){
    bool check;

    do{
        cout << "Enter in filename/path: ";
        cin >> inputfile;
        infile.open(inputfile, ios::in);
        check = infile.good();
        if(check == false){
            cout << "Error. The file cannot be opened." << endl;
            cout << "Enter in filename/path: ";
            cin >> inputfile;
        }
    } while(!check);
}

// function to get word count
// ***** NEED TO FIX BECAUSE GIVES THE WRONG AMOUNT OF WORDS*****
void wordCount(ifstream& ifile){
    ifile.open(inputfile, ios::in);
    char letter;
    // count all the words until the end of the file
    while(!ifile.eof()){
        ifile.get(letter);
        if(letter == ' '){
            wordcount++;
        }
    }
    ifile.close();
}

int main(){
    Book b;
    ifstream ifile;
    ofstream ofile;
    string line;
    string firstname, lastname;
    char add, see;

// *****************************************
// ** also need to debug code bc it gives **
// ** the wrong amount of lines yikes     **
// *****************************************

    do{
        openInputFile(ifile);
        cout << endl;
        while(!ifile.eof()){
            // since linecount is at 0 can get title name
            if(linecount == 0){
                getline(ifile, b.Title);
                // get next line to find author name
                getline(ifile, line);
                b.Author = line;
                firstname = line.substr(0, line.find(' '));     // find first name using substring of the whole line
                lastname = line.substr(line.find(' ') + 1);     // find last name using next position of first name
                b.AuthorFirstN = firstname;
                b.AuthorLastN = lastname;
                linecount++;
            }
            getline(ifile, line);
            linecount++;
        }
        ifile.close();
        b.LineCount = linecount;
        wordCount(ifile);
        b.WordCount = wordcount;

        // print out all the data gathered
        cout << "Title: " << b.Title << endl;
        cout << "Full Author: " << b.Author << endl;
        cout << "Author First Name: " << b.AuthorFirstN << endl;
        cout << "Author Last Name: " << b.AuthorLastN << endl;
        cout << "Word Count: " << b.WordCount << endl;
        cout << "Line Count: " << b.LineCount << endl;

        ofile.open("CardCatalog.txt", ios::app | ios::out);
        ofile << "Title: " << b.Title << endl;
        ofile << "Full Author: " << b.Author << endl;
        ofile << "Author First Name: " << b.AuthorFirstN << endl;
        ofile << "Author Last Name: " << b.AuthorLastN << endl;
        ofile << "Word Count: " << b.WordCount << endl;
        ofile << "Line Count: " << b.LineCount << endl << endl;
        ofile.close();

        cout << "Would you like to see the letter frequency? (Y or N): ";
        cin >> see;
        if(see == 'Y' || see == 'y'){
            // *********************************
            // *** code for letter frequency ***
            // *********************************
        }


        // ask user if they want to add another book to get info on
        cout << "Add another book? (Y or N): ";
        cin >> add;

    } while(add == 'Y' || add == 'y');

    return 0;
}
