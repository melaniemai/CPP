/*
    Melanie Mai
*/

//#include <iostream>
//#include <vector>

//#include "LList.h"

//using namespace std;

//int main(){

//    LList a;

//    cout << "a.size() = " << a.size() << endl;
//    cout << "a.empty() = " << a.empty() << endl;

//    cout << "pushing to front 1 to 5 " << endl;
//    for(int i = 1; i <= 5; i++)
//    a.push_front(i);

//    cout << "list a: " << a << endl;

//    cout << "pushing to back 6 to 10 " << endl;
//    for(int i = 6; i <= 10; i++)
//    a.push_back(i);

//    cout << "list a: " << a << endl;
//    cout << "a.size() = " << a.size() << endl;
//    cout << "a.empty() = " << a.empty() << endl;

//    LList b = a;
//    cout << "list b: " << b << endl;

//    if(a == b)
//    cout << "list a and b are equal" << endl;
//    else
//    cout << "list a and b are NOT equal" << endl;

//    LList c = a.reverse();
//    cout << "list c = reverse of a: " << c << endl;

//    if(a != c)
//    cout << "list a and c are NOT equal" << endl;
//    else
//    cout << "list a and c are equal" << endl;

//    cout << "adding 2 to each element of list c, using [] operator" << endl;
//    for(int i = 0 ; i< c.size(); i++)
//    c[i] = c[i] + 2;

//    cout << "list c: " << c << endl;

//    cout << "popping back all elements in list c" << endl;
//    while(!c.empty())
//    c.pop_back();

//    cout << "list c: " << c << endl;


//    LList a;
//    cout << "Size: " << a.size() << endl;
//    cout << "Pushing to front 1 to 20 " << endl;
//    for(int i = 1; i <= 20; i++)
//    a.push_front(i);

//    cout << "list a: " << a << endl;
//    LList b = a;
//    cout << "list b: " << b << endl;

//    if(a == b)
//    cout << "list a and b are equal" << endl;
//    else
//    cout << "list a and b are NOT equal" << endl;

//    cout<<"Adding list a and b and store the resultant list in c"<<endl;
//    LList c = a+b;
//    cout<<"list c: "<<c<<endl;

//    cout << "Pushing to back 50 to 60 in list a" << endl;
//    for(int i = 50; i <= 60; i++)
//    a.push_back(i);

//    cout << "list a: " << a << endl;
//    cout << "size : " << a.size() << endl;

//    LList r = a.reverse();
//    cout << "list r is reverse of a: " << r << endl;

//    if(a == r)
//    cout << "list a and r are equal" << endl;
//    else
//    cout << "list a and r are NOT equal" << endl;

//    cout << "Popping back all elements in list r" << endl;
//    while(!r.empty())
//    r.pop_back();
//    cout << "list r: " << r << endl;


////    for(int i = 0; i < 50; i++){
////        a.push_front(45);
//////        cout << *a << endl;
////    }


//    return 0;
//}

