// The program will work if you insert your file path on lines 35-36 and 87

#include <iostream>
#include <fstream>
#include <cctype>
#include <string>

using namespace std;

// Convert lowercase letters to upper
// All encryptions and decryptions will be made in uppercase letters then fixed in main body
char lowerToUpper(char ch){
    return toupper(ch);
}

// Convert uppercase letters to lower
char upperToLower(char ch){
    return tolower(ch);
}

// Function prototypes for encryption and decryption since they won't work unless they are after main function
char encrypt(char ch);
char decrypt(char ch);

static int shiftLetterValue = 0;       // Value of how many shifts the letters are moving based on current position and value

int main() {
    ifstream infile;
    string line;    // line = each line from the file
    string input;
    string keyinput;
    int sum = 0;        // ASCII value

    // encryptedkey.txt and decryptedkey.txt will be made if user doesn't originally have it
    ofstream outfile_en("C:\\Users\\suong\\Downloads\\encryptedkey.txt");      // Replace with user path
    ofstream outfile_de("C:\\Users\\suong\\Downloads\\decryptedkey.txt");      // Replace with user path

    // Get key input
    string key;
    cout << "Enter key: ";
    cin >> key;

    // Loop through each character and get ASCII value and add to sum
    for(char ch : key){
        sum += static_cast<int>(ch);
    }

    // Calculate how much each letter is going to shift
    shiftLetterValue = (sum % 23) + 3;

    // Get file input from user
    cout << "Enter the input file (Example.txt) or file path: ";
    cin >> input;
    infile.open(input.c_str()); // open file from user

    // Check if file can be opened
    while(!infile.is_open()){
        cout<<"There was a problem opening the " << input << " file." << endl;
        cout << "Enter the input file (Example.txt) or file path: ";
        cin >> input;

        infile.open(input.c_str());
    }

    // Read till the end of file
    while(!infile.eof()){
        getline(infile,line);

        // loop to encrypt the line
        for(unsigned int i = 0; i < line.length(); i++){
            if(line.at(i) >= 'A' && line.at(i) <= 'Z'){             // Check if char is a letter (between uppercase A-Z)
                outfile_en << static_cast<char>(encrypt(line.at(i)));      // Encrypt each letter
            }
            else if(line.at(i) >= 'a' && line.at(i) <='z'){         // Check if letter is lowercase
                outfile_en << static_cast<char>(upperToLower(encrypt(lowerToUpper(line.at(i)))));  // Will convert uppercase letter to lowercase if letter was originally lowercase (since all letters converted to uppercase
            }
            else{
                outfile_en << line.at(i);       // print out character if its a space or punctuation
            }
        }
        outfile_en << endl;
    }

    outfile_en.close(); // Close the encrypted file
    infile.close(); // Close the input file

    infile.open("C:\\Users\\suong\\Downloads\\encryptedkey.txt"); // Open encrypted file in read mode

    // Read till the end of file
    while(!infile.eof()){
        getline(infile,line);

        // loop to decrypt a line
        for(unsigned int i = 0; i < line.length(); i++){
            if(line.at(i) >= 'A' && line.at(i) <= 'Z'){     // Check if char is a letter (between uppercase A-Z)
                outfile_de << (static_cast<char>(decrypt(line.at(i))));
            }
            else if(line.at(i) >= 'a' && line.at(i) <= 'z'){             // Check if letter is lowercase
                outfile_de << static_cast<char>(upperToLower(decrypt(lowerToUpper(line.at(i)))));
            }
            else{
                outfile_de << line.at(i);       // print out character if its a space or punctuation
            }
        }
        outfile_de << endl;
    }

    outfile_de.close();     // Close the decrypted file
    infile.close();         // Close the encrypted file

    cout << "Reading of file/path was successful." << endl;

    return 0;
}


// Encryption using rot13 algorithm
char encrypt(char ch){
    char encryption = ((((ch - 'A') + shiftLetterValue) % 26) + 'A'); //keep the characters between A-Z
    return encryption;
}

// Decryption using rot13 algorithm
char decrypt(char ch){
    char decryption = (((ch - 'A') + (26 - shiftLetterValue)) % 26 + 'A'); //keep the characters between A-Z
    return decryption;
}
