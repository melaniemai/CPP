//#include<iostream>
//#include<string>
//#include<fstream>

//using namespace::std;



//struct book
//{
//    string title, author;
//    int word_count, line_count;
//    int letter_frequency[26];
//};

//void wordCount(string);
//void lineCount(string);
//void letterFrequency(string);
//void write_to_file();

//book b1;

//int main()
//{
//    //book b1;
//    int count_main = 0;
//    string line;
//    string bookname;
//    bool str = true;
//    while (str) {
//        cout << "Enter the name of the book\n";
//        cin >> bookname;
//        fstream book;
//        book.open(bookname);
//        //cout << book.rdbuf();
//        if (book.is_open()) {
//            while (book) {

//                getline(book, line);
//                //cout << line;

//                count_main = count_main + 1;
//                //cout<<count_main;
//                if (count_main == 1) {
//                    b1.title = line;
//                }
//                else if (count_main == 2) {
//                    b1.author = line;
//                }
//                else if (count_main == 3) {
//                        //cout<<"reached  count 3";
//                    cout << "Title of the book is: "<< b1.title<< "\n"
//                        "Name of the author is: "<< b1.author << "\n";
//                    wordCount(bookname);
//                //cout<<"called count";
//                    lineCount(bookname);
//                    //cout<<"called line count";
//                    letterFrequency(bookname);
//                }
//            }
//            count_main = 0;
//            book.close();
//        }
//        else {
//            cout << "Entered file name is wrong\n";
//                continue;
//        }
//        write_to_file();
//        char j;
//        cout << "Do you want to enter again?(y or n)"<<"\n";
//        cin >> j;
//        if (j == 'n') {
//            str = false;
//        }
//    }
//    return 0;
//}

//void wordCount(string bookname) {
//    //cout<<"reached word count";
//    int count = 0;
//    string word;
//    fstream inFile;
//    inFile.open(bookname);
//    for (int i = 0; i < 5; i++) {
//        inFile >> word;
//    }
//    while (inFile >> word) { ++count; }
//    b1.word_count = count;
//    cout << "The word count of contents in the book is: "<< b1.word_count << "\n";
//}

//void lineCount(string bookname) {
//    //cout<<"reached word line_count";
//    int number_of_lines = 0, i;
//    string line;
//    ifstream myfile(bookname);
//    for (i = 0; i < 3; i++) {
//        getline(myfile, line);
//    }
//    while (getline(myfile, line))
//        ++number_of_lines;
//    b1.line_count = number_of_lines;
//    cout << "Number of lines in text file: " << b1.line_count<< "\n";
//}

//void letterFrequency(string bookname) {
//    //cout<<"reached word leter freq count";
//    int freq[128];     // frequencies of letters
//    ifstream inFile;   // input file
//    char ch;

//    inFile.open(bookname);

//    // initialize frequency counts to zero for each possible letter
//    for (int k = 0; k < 128; k++)
//    {
//        freq[k] = 0;
//    }

//    // Read the file, keeping track of frequency with which each letter occurs
//    ch = inFile.get();
//    int i, j;
//    float percentage, count;
//    for (i = 0; i < 36; i++) {
//        ch = inFile.get();
//    }
//    count = 0;
//    while (ch != EOF)
//    {
//        count++;
//        //cout << ch;
//        ch = toupper(ch);
//        freq[ch]++;
//        ch = inFile.get();
//    }
//    j = 0;
//    // Print the output table
//    cout << endl << "Letter frequencies in this file are as follows." << endl;
//    for (char ch = 'A'; ch <= 'Z'; ch++)
//    {
//        b1.letter_frequency[j] = freq[ch];
//        j++;
//    }
//    char y;
//    cout << "Do you want to see the letter frequency(Y or N)" << "\n";
//    cin >> y;
//    if (y == 'y') {
//        for (char ch = 'A'; ch <= 'Z'; ch++)
//        {
//            percentage = (freq[ch] / count) * 100;
//            cout << ch << " : ";
//            printf("%.2f", percentage);
//            cout << " %" << endl;
//        }
//    }
//    else if (y == 'n') {  }
//    else {  }
//}

//void write_to_file() {
//    int j = 0;
//    fstream new_file;
//    new_file.open("CardCatalog.txt", ios::app | ios::out);
//    new_file << "Title:" << b1.title << "\n" << "Author: " << b1.author << "\n" << "Number of words:" << b1.word_count << "\n" << "Number of lines:" << b1.line_count << "\n";
//    new_file << "Letter frequencies in this file are as follows." << endl;
//    for (char ch = 'A'; ch <= 'Z'; ch++)
//    {
//        new_file << ch << " : " << b1.letter_frequency[j] << "\n";
//        j++;
//    }
//    new_file << "\n" << "\n";
//}
