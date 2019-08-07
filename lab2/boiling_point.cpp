// This is a partial solution to the given problem. We have solved for Water and Mercury.

#include <iostream>

using namespace std;

const double WATER_BP = 100;
const double MERC_BP = 357;
const double COPPER_BP = 1187;
const double SILVER_BP = 2193;
const double GOLD_BP = 2660;

int main()
{
   double bp;

   cout << "Enter Boiling Point: " << endl;
   cin >> bp;

    if(bp >= (WATER_BP*.95) && bp <= (WATER_BP*1.05))
        cout << "Your substance is Water" << endl;
    else if(bp >= (MERC_BP*.95) && bp <= (MERC_BP*1.05))
        cout << "Your substance is Mercury" << endl;
    else if(bp >= (COPPER_BP*.95) && bp <= (COPPER_BP*1.05))
        cout << "Your substance is Copper" << endl;
    else if(bp >= (SILVER_BP*.95) && bp <= (SILVER_BP*1.05))
        cout << "Your substance is Silver" << endl;
    else if(bp >= (GOLD_BP*.95) && bp <= (GOLD_BP*1.05))
        cout << "Your substance is Gold" << endl;
    else {
       cout << "Your substance is Unknown" << endl;
    }

   return 0;
}
