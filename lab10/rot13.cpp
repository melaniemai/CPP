//// The program will work if you enter in your file path in lines 39-40, and 78

//#include <iostream>
//#include <fstream>
//#include <cctype>
//#include <string>

//using namespace std;

//// Convert lowercase letters to upper
//// All encryptions and decryptions will be made in uppercase letters then fixed in main body
//char lowerToUpper(char ch){
//    return toupper(ch);
//}

//// Convert uppercase letters to lower
//char upperToLower(char ch){
//    return tolower(ch);
//}

//// Encryption using rot13 algorithm
//char encrypt(char ch){
//    char encryption = ((((ch - 'A') + 13) % 26) + 'A'); //keep the characters between A-Z
//    return encryption;
//}

//// Decryption using rot13 algorithm
//char decrypt(char ch){
//    char decryption = (((ch - 'A') + (26 - 13)) % 26 + 'A'); //keep the characters between A-Z
//    return decryption;
//}

//int main() {
//    ifstream infile;
//    string line;    // line = each line from the file
//    string input;

//    // encrypted.txt and decrypted.txt will be made if user doesn't originally have it
//    ofstream outfile_en("C:\\Users\\suong\\Downloads\\encrypted.txt");      // Replace with user path
//    ofstream outfile_de("C:\\Users\\suong\\Downloads\\decrypted.txt");      // Replace with user path

//    // Get file input from user
//    cout << "Enter the input file (Example.txt) or file path: ";
//    cin >> input;
//    infile.open(input.c_str()); // open file from user

//    // Check if file can be opened
//    while(!infile.is_open()){
//        cout<<"There was a problem opening the " << input << " file." << endl;
//        cout << "Enter the input file (Example.txt) or file path: ";
//        cin >> input;

//        infile.open(input.c_str());
//    }

//    // Read till the end of file
//    while(!infile.eof()){
//        getline(infile,line);

//        // loop to encrypt the line
//        for(unsigned int i = 0; i < line.length(); i++){
//            if(line.at(i) >= 'A' && line.at(i) <= 'Z'){             // Check if char is a letter (between uppercase A-Z)
//                outfile_en << static_cast<char>(encrypt(line.at(i)));      // Encrypt each letter
//            }
//            else if(line.at(i) >= 'a' && line.at(i) <='z'){         // Check if letter is lowercase
//                outfile_en << static_cast<char>(upperToLower(encrypt(lowerToUpper(line.at(i)))));  // Will convert uppercase letter to lowercase if letter was originally lowercase (since all letters converted to uppercase
//            }
//            else{
//                outfile_en << line.at(i);       // print out character if its a space or punctuation
//            }
//        }
//        outfile_en << endl;
//    }

//    outfile_en.close(); // Close the encrypted file
//    infile.close(); // Close the input file

//    infile.open("C:\\Users\\suong\\Downloads\\encrypted.txt"); // Open encrypted file in read mode

//    // Read till the end of file
//    while(!infile.eof()){
//        getline(infile,line);

//        // loop to decrypt a line
//        for(unsigned int i = 0; i < line.length(); i++){
//            if(line.at(i) >= 'A' && line.at(i) <= 'Z'){     // Check if char is a letter (between uppercase A-Z)
//                outfile_de << (static_cast<char>(decrypt(line.at(i))));
//            }
//            else if(line.at(i) >= 'a' && line.at(i) <= 'z'){             // Check if letter is lowercase
//                outfile_de << static_cast<char>(upperToLower(decrypt(lowerToUpper(line.at(i)))));
//            }
//            else{
//                outfile_de << line.at(i);       // print out character if its a space or punctuation
//            }
//        }
//        outfile_de << endl;
//    }

//    outfile_de.close();     // Close the decrypted file
//    infile.close();         // Close the encrypted file

//    cout << "Reading of file/path was successful." << endl;

//    return 0;
//}


