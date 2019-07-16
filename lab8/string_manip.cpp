//// Melanie Mai
////
//#include <iostream>
//#include <string>
//#include <cctype>

//using namespace std;

//// This prototype is complete
//class stringManip {
//    public:
//        stringManip(); // X
//        stringManip(string input); // X
//        string retrieve(); // X
//        void setString(string input); // X
//        void chop(); // X
//        void padString(int n); // X
//        void center(int length); // X
//        void truncate(int n); // X
//        void removeNonAlpha(); // X
//        void convertToUpperCase(); // X
//        void convertToLowerCase(); // X
//    private:
//        string tobeEdited;
//};

//// Not all functions are defined here

//// Default Constructor
//stringManip::stringManip(){
//    tobeEdited = "";
//}

//// Overloaded Constructor
//stringManip::stringManip(string in_string){
//    tobeEdited = in_string;
//}

//// retrieve function
//string stringManip::retrieve(){
//    return tobeEdited;
//}

//// setString function
//void stringManip::setString(string in_string){
//    tobeEdited = in_string;
//}

//// chop() function
//void stringManip::chop(){
//    for(unsigned i = 0; i < tobeEdited.length(); i++){
//        if(isspace(tobeEdited[i])){
//            tobeEdited.erase(i);
//        } else {
//            break;
//        }
//    }
//    for(unsigned long long j = tobeEdited.length() - 1; j > 0; j--){
//        if(isspace(tobeEdited[j])){
//            tobeEdited.erase(j);
//        } else{
//            break;
//        }
//    }
//}

//// padString() function
//void stringManip::padString(int length){
//    while(tobeEdited.size() < (static_cast<unsigned long long>(length))){
//        tobeEdited += " ";
//    }
//}

//// center() function
//void stringManip::center(int length){
//    chop();
//    // calculate center point
//    int centering = length - tobeEdited.length();
//    for(int i = 0; i < (centering/2); i++){
//        tobeEdited.insert(i, " ");
//    }
//    for(int j = 0; j < ((centering/2) + 1); j++){
//        tobeEdited += " ";
//    }

//}

//// truncate() function
//void stringManip::truncate(int n){
//    if(tobeEdited.length() > n){
//        while(tobeEdited.length() > n){
//            tobeEdited.pop_back();
//        }
//    }
//}

//// removeNonAlpha function
//void stringManip::removeNonAlpha(){
//    for(unsigned long long i = 0; i < tobeEdited.length(); i++){
//        if(isdigit(tobeEdited[i]) || isspace(tobeEdited[i])){
//            tobeEdited.erase(i);
//        }
//    }
//}


//// convertToUpperCase() function
//void stringManip::convertToUpperCase(){
//    for(unsigned long long i = 0; i < tobeEdited.length(); i++){
//        tobeEdited.at(i) = toupper(tobeEdited.at(i));
//    }
//}

//// convertToLowerCase() function
//void stringManip::convertToLowerCase(){
//    for(unsigned long long i = 0; i < tobeEdited.length(); i++){
//        tobeEdited.at(i) = tolower(tobeEdited.at(i));
//    }

//}

//// Add test cases to main()
//int main(){
//    stringManip S1;
//    stringManip S2("testing 123");
//    stringManip S3("HellO0 W0rlD!");

//    // Test case for chop()
//    cout << "S2 before chop(): <" << S2.retrieve() << ">" << endl;
//    S2.chop();
//    cout << "S2 after chop(): <" << S2.retrieve() << ">" << endl;
//    cout << "Should be: <testing 123>" << endl;

//    cout << endl;

//    // Test case for padString() You should correct some of your own.
//    cout << "S2 before padString(20): <" << S2.retrieve() << ">" << endl;
//    S2.padString(20);
//    cout << "S2 after padString(20): <" << S2.retrieve() << ">" << endl;
//    cout << "Should be: <testing 123       >" << endl;

//    cout << endl;

//    // Test case for center()
//    cout << "S2 before center(): <" << S2.retrieve() << ">" << endl;
//    S2.chop();
//    S2.center(20);
//    cout << "S2 after center(): <" << S2.retrieve() << ">" << endl;
//    cout << "Should be: <    testing 123    >" << endl;

//    cout << endl;

//    // Test case for truncate()
//    cout << "S2 before truncate(): <" << S2.retrieve() << ">" << endl;
//    S2.truncate(1);
//    cout << "S2 after truncate(): <" << S2.retrieve() << ">" << endl;
//    cout << "Should be: < >" << endl;

//    cout << endl;

//    // Test case for removeNonAlpha()
//    cout << "S3 before removeNonAlpha(): <" << S3.retrieve() << ">" << endl;
//    S3.removeNonAlpha();
//    cout << "S3 after removeNonAlpha(): <" << S3.retrieve() << ">" << endl;
//    cout << "Should be: <HellO>" << endl;

//    cout << endl;

//    // Test case for convertToUpperCase()
//    cout << "S3 before convertToUpperCase(): <" << S3.retrieve() << ">" << endl;
//    S3.convertToUpperCase();
//    cout << "S3 after convertToUpperCase(): <" << S3.retrieve() << ">" << endl;
//    cout << "Should be: <HELLO>" << endl;

//    cout << endl;

//    // Test case for convertToLowerCase()
//    cout << "S3 before convertToLowerCase(): <" << S3.retrieve() << ">" << endl;
//    S3.convertToLowerCase();
//    cout << "S3 after convertToLowerCase(): <" << S3.retrieve() << ">" << endl;
//    cout << "Should be: <hello>" << endl;


//    return 0;
//}
