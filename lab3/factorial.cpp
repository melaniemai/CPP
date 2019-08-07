#include <iostream>
#include <iomanip>

using namespace std;
double factorial(int n) {
    int fact = 1;
    for(int i = 1; i <= n; i++){
        fact *= i;
    }
   return fact;
}

int main() {
   int N = 0;
   cin >> N;
   cout << fixed << "Factorial of " << N  << " Equals " << factorial(N) << endl;
   /* Type your code here. */

   return 0;
}
