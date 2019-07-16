/*
Name: Melanie Mai
Date: July 1, 2019
Assignment: <fill me in>
Description: <fill me in>
*me: <fill me in>
Date: <fill me in>
Assignment: <fill me in>
Description: <fill me in>
*/


#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

bool find(int array[], int length, int value){
    for(int i = 0; i < length; i++){
        if(array[i] == value){
            return true;
        }
    }
    return false;
}

bool isSorted(int array[], int length){
    for(int i = 0; i < length-1; i++){
        if(array[i+1] < array[i]){
            return false;
        }
    }
    return true;
}

void reverse(vector <int> &reverse_me) {
    int i=0;
    int j = reverse_me.size()-1;
    while(i < j)
    {
        //swap values
        int temp = reverse_me[i];
        reverse_me.at(i) = reverse_me[j];
        reverse_me[j] = temp;
        i++;
        j--;
    }
}

float mean(const vector <float> values) {
    float sum = 0.0;
    float mean = 0.0;
    if(values.empty()){
        return 0.0;
    } else{
        for(int i = 0; i < values.size(); i++){
            sum += values[i];
        }
        mean = sum / values.size();
    }
    return mean;
}

float stddev(const vector <float> values) {
    double deviation = 0.0;
    float sum = 0.0;
    float m = mean(values);
    if(values.empty()){
        return 0.0;
    } else {
        for(int i = 0; i < values.size(); i++){
            sum += pow((values[i] - m), 2);
        }
    }
    deviation = sqrt(sum/(values.size()));
    return deviation;
    // Should use mean above
}

vector<int> removeDups(vector<int> array){
    vector<int> *B = new vector<int>();
    vector<int> n = *B;
    for(int i = 0; i < array.size(); i++){
        int count = 0;
        for(int j = 0; j < n.size(); j++){
            if(array[i] == n[j]){
                count = 1;
                break;
            }
        }
        if(count == 0) // not duplicate
            n.push_back(array[i]); // add to new list
    }
    return n; // return vector with out duplicates

  // This is just to keep the compiler happy
  return vector<int>();
}

// Strings - You need to a add the rest listed in the google doc
unsigned int countUpperCaseChars(const string &countme){
    int uppercount = 0;
    for(int i = 0; i < countme.length(); i++){
        if(isupper(countme[i])){
            uppercount++;
        }
    }
    return uppercount;
}

string convertToUpper(const string &to_be_converted){
    string newstr = "";
    if(to_be_converted.empty()){
        return to_be_converted;
    } else{
        for(int i = 0; i < to_be_converted.length(); i++){
            newstr += toupper(to_be_converted[i]);
        }
    }
    return newstr;
}

string removeSpaces(const string &remove_from_me){
    string newstr = "";
    for(int i = 0; i < remove_from_me.length(); i++){
        if(remove_from_me[i] == ' '){
        } else{
            newstr += remove_from_me[i];
        }
    }
    return newstr;
}

vector <int> characterCounts(const string &countme){
    vector<int> freq;
    /* Initialize frequency of each character to 0 */
    for(int i=0; i<26; i++){
        freq.push_back(0);
    }
    /* Find total number of occurrences of each character */
    for(int i=0; i<countme.length(); i++){
        /* If the current character is lowercase alphabet */
        if(countme[i]>='a' && countme[i]<='z'){
            freq[countme[i] - 97]= freq[countme[i] - 97] +1;
        }
        /* If the current character is uppercase alphabet */
        else if(countme[i]>='A' && countme[i]<='Z'){
            freq[countme[i] - 65] = freq[countme[i] - 65]+1;
        }
    }
    /* Returns vector*/
    return freq;
}

template<typename T>
string print(vector<T> vec);

template<typename T>
string print(T array[], int length);


int main(){
  srand(time(0));

  cout << "find:" << endl;
  int x1[10] = {1,2,3,5,5,6,7,8,9,0};

  cout << "false/0 = " << find(x1, 10, 4) << endl;
  cout << "false/0 = " << find(x1, 10, 99) << endl;
  cout << "true/1 = " << find(x1, 10, 5) << endl;
  cout << "true/1 = " << find(x1, 10, 0) << endl;
  cout << "true/1 = " << find(x1, 10, 1) << endl;
  cout << "true/1 = " << find(x1, 10, 6) << endl;
  cout << endl;
  cout << endl;
  cout << "reverse:" << endl;
  vector <int> v1 = {1,2,3,4,5};
  reverse(v1);
  cout << "[5,4,3,2,1] = " << print(v1) << endl;
  reverse(v1);
  cout << "[1,2,3,4,5] = " << print(v1) << endl;
  vector <int> v2 = {5};
  cout << "[5] = " << print(v2) << endl;
  vector <int> v3 = {1,2,4,5};
  reverse(v3);
  cout << "[5,4,2,1] = " << print(v3) << endl;
  vector <int> v4(100);
  v4[0]  = 4;
  v4[1]  = 2;
  reverse(v4);
  cout << "0 = " << v4[0] << endl;
  cout << "2 = " << v4[98] << endl;
  cout << "4 = " << v4[99] << endl;

  cout << endl << "mean:" << endl;
  vector <float> f1 = {1.2, 2.4, 3.4};
  vector <float> f2 = {5.6, 5.6, 5.6, 5.6, 5.6, 5.6};
  cout << "2.33 = " << mean(f1) << endl;
  cout << "5.6 = " << mean(f2) << endl;

  cout << endl << "stddev:" << endl;
  cout << "0.899 = " << stddev(f1) << endl;
  cout << "0 = " << stddev(f2) << endl;

  cout << endl << "removedups:" << endl;
  vector<int> v5;
  v5.push_back(1);
  v5.push_back(2);
  v5.push_back(3);
  v5.push_back(3);
  v5.push_back(4);
  v5.push_back(5);
  v5.push_back(1);
  vector<int> v12 = removeDups(v5);
  cout << "[1,2,3,4,5] = " << print(v12) << endl;
  cout << "5 = " << v12.size() << endl;
  vector<int> v6;
  for(int i = 0; i < 100; i++){
    v6.push_back(i%17 + i %7);
  }
  vector<int> v22 = removeDups(v6);
  cout << "22 = " << v22.size() << endl;

  cout << "\nString Functions: " << endl;
  string upper_test = "aaABCdeFG";
  cout << "countUpperCase" << endl;
  cout << "5 = " << countUpperCaseChars(upper_test) << endl;
  cout << "5 = " << countUpperCaseChars("AAAAA") << endl;
  cout << "0 = " << countUpperCaseChars("aaaaa") << endl;
  string no_upper_case = "aaaa";
  cout << "0 = " << countUpperCaseChars(no_upper_case) << endl;

  cout << "RemoveSpaces:" << endl;
  string test1 = "aa AB Cd e FG";
  string test2 = "aaAB Cd e FG ";
  string test3 = " rrAB Cd e FG";
  string test4 = " rrAB Cd e FG ";

  cout << "aaABCdeFG = " << removeSpaces(test1) << endl;
  cout << "aaABCdeFG = " << removeSpaces(test2) << endl;
  cout << "rrABCdeFG = " << removeSpaces(test3) << endl;
  cout << "rrABCdeFG = " << removeSpaces(test4) << endl;

  return 0;
}

// A sneaky way to allow 1 function to print any typed array, as long as
// the passed array element can be sent to <<.
// The stringstream allows us to 'print' information to a fake output
// stream, and then get the result as a string.  It's a simple way of
// getting a non-string/character into a string.
// Contense of this function will not be tested in this course!

template<typename T>
string print(vector<T> vect) {
  stringstream out;
  out << '[';
  for(int i = 0; i < vect.size(); i++){
    out << vect[i];
    if(i != vect.size()-1)out << ',';
  }
  out << ']';
  return out.str();
}


template<typename T>
string print(T array[], int length){
  stringstream out;
  out << '[';
  for(int i = 0; i < length; i++){
    out << array[i];
    if(i != length-1)out << ',';
  }
  out << ']';
  return out.str();
}
