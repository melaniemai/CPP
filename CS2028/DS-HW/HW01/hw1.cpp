#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

struct Book{
    string Title;
    string AuthorFirstN;
    string AuthorLastN;
    int WordCount;
    int LetterFrequency[26];
    int LineCount;
};

//static vec<string> fileText;

static int alphaFreq[26];

// function to get user to input filename and attempt to open file
bool openReadInputFile(vector<string> *fileLines){
    ifstream inFile;
    string inputFile;
    bool check;
    cout << "Enter in filename/path: ";
    cin >> inputFile;
    do{
        inFile.open(inputFile, ios::in);
        check = inFile.good();
        if(check == false){
            cout << "Error. The file cannot be opened." << endl;
            cout << "Enter in filename/path: ";
            cin >> inputFile;
        }
    } while(!check);



    string str= "";
    int i = 0;
    // Read the next line from File untill it reaches the end.
    while (getline(inFile, str))
    {
        // Line contains string of length > 0 then save it in vector
        if(str.size() > 0)
            fileLines->push_back(str);
        i++;
        str = "";
    }
    cout << "file read" << endl;
    //Close The File
    inFile.close();
    if (i >= 4) return true;
    else return false;
}

int wordCount(string str){
    if (str.size() == 0)
      return 0;

    bool inSpaces = true;
    int numWords = 0;
    int i=0;
    for(i=0; i<str.size(); i++)
    {
      if (str[i]!=' ')
      {
         i++;
      }
      else{
        numWords++;
      }
    }

    return numWords;
}

void alphabetFreq(string str){
    if (str.size()==0)
       return;
    int i,j = 0;
    for  (i=0; i<str.size(); i++){

        if (str[i] >= 'a' && str[i] <='z'){
            j = str[i] -  'a';
            ++alphaFreq[j];
        }
    }

   return;
}

int main(){
    Book b;
    ofstream ofile;
    vector<string> fileContents;
    string line;
    string author;
    string firstname, lastname;
    int i, words, totalchars, numberOfLines = 0;
    char add, see;
    bool result;
    cout << "initialized" << endl;

    do{
        result =  openReadInputFile(&fileContents);
        cout << "read file" << endl;
        numberOfLines = fileContents.size();
        if (!result) cout << "file does not have enough lines";
        else{
            words=0;
            for (i=0; i<26; i++){
                alphaFreq[i]=0;
            }
            b.Title = fileContents.at(0);
            author = fileContents.at(1);
            b.AuthorFirstN = author.substr(0, author.find(' '));     // find first name using substring of the whole line
            b.AuthorLastN = author.substr(author.find(' ') + 1);     //
            b.LineCount = numberOfLines - 3;

            for(i=numberOfLines; i>3; i--){
                line = fileContents.at(i-1);
                words = words + wordCount(line);
                alphabetFreq(line);
                fileContents.pop_back();
            }
            for (i=0; i<26; i++){
                b.LetterFrequency[i] = alphaFreq[i];
            }
            b.WordCount = words;
        }
        // print out all the data gathered
        cout << "Title: " << b.Title << endl;
        cout << "Author First Name: " << b.AuthorFirstN << endl;
        cout << "Author Last Name: " << b.AuthorLastN << endl;
        cout << "Word Count: " << b.WordCount << endl;
        cout << "Line Count: " << b.LineCount << endl;

        ofile.open("CardCatalog.txt", ios::app | ios::out);
        ofile << "Title: " << b.Title << endl;
        ofile << "Author First Name: " << b.AuthorFirstN << endl;
        ofile << "Author Last Name: " << b.AuthorLastN << endl;
        ofile << "Word Count: " << b.WordCount << endl;
        ofile << "Line Count: " << b.LineCount << endl << endl;
        ofile.close();

        cout << "Would you like to see the letter frequency? (Y or N): ";
        cin >> see;
        if(see == 'Y' || see == 'y'){

            for (i=0; i<26; i++){
                totalchars = totalchars + b.LetterFrequency[i];
            }

            cout << b.Title << " letter frequency:";

            for (i=0; i<26; i++){
                cout << char (i+'a') << " : " << (double(b.LetterFrequency[i])/totalchars)*100 << " %" << "\n";
            }
        }
        while (!fileContents.empty()){
            fileContents.pop_back();
        }
        // ask user if they want to add another book to get info on
        cout << "Add another book? (Y or N): ";
        cin >> add;

    } while(add == 'Y' || add == 'y');

    return 0;
}
