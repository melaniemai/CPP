// Lab6 = array_stats.cpp
// Melanie Mai, June 30, 2019
// Generate a series of random numbers that will all fall within
// a user specified upper limit and zero. Program will count the
// number of times each number occurs in the randomized input data.

#include <iostream>
#include <time.h>
#include <cstdlib>
#include <iomanip>
#include <cmath>

using namespace std;

// Generate random integer numbers for any range up to RAND_MAX.
int rand_Num_Generator(int x){
    return (rand() % x);
}

// Calculates the sum of the array (pass by pointer)
int sum(int* freqArray, int range){
    int sum = 0;
    for(int i = 0; i <= range; i++){
        sum = sum + freqArray[i];
    }
    return sum;
}

// Determines the average in the array
double mean(int* freqArray, int range){
    double mean = 0;
    double sum = 0;
    for(int i = 0; i <= range; i++){
        sum = sum + freqArray[i];
    }
    mean = sum / (range + 1);
    return mean;
}

// Finds the number with the smallest frequency in the array
int minFreq(int* freqArray, int range){
    int min = freqArray[0]; // min is equal to lower limit of freqArray
    for(int i = 0; i <= range; i++){
        if(freqArray[i] < min){
            min = freqArray[i];
        }
    }
    return min;
}

// Finds the number with the biggest frequency in the array
int maxFreq(int* freqArray, int range){
    int max = freqArray[0];
    for(int i = 0; i <= range; i++){
        if(freqArray[i] > max){
            max = freqArray[i];
        }
    }
    return max;
}

// Creates bar graph based on the frequency of each number in the array
void barGraph(int* freqArray, int range, int bar){
    cout << "Index \tValue Bar" << endl;
    for(int i = 0; i <= range; i++){
        cout << " " << i << "\t" << freqArray[i] << " ";
        for(int j = 0; j < freqArray[i]; j += bar){
            cout << "*";
        }
        cout << endl;
    }
}

int main()
{
    srand(time(NULL));

    int initial = 0;

    // User enters in upper limit
    cout << "Enter End Range (up to 100): ";
    int range = 0;
    cin >> range;
    cout << endl;

    // Check value of range to see if valid
    while (range > 100 || range < 0){
        cout << "Error. Please enter a valid number less than 100 and greater than 0: ";
        cin >> range;
        cout << endl;
    }

    // User enters in number of samples they would like to generate
    cout << "Enter number of Samples: ";
    int sampleSize = 0;
    cin >> sampleSize;
    cout << endl;

    // Check whether number of samples is not negative
    while(sampleSize < 0){
        cout << "Error. Please enter a positive number: ";
        cin >> sampleSize;
    }

    int* freqArray = new int[range]; // Create freqArray and have it point to an array of [range] ints / dynamic memory allocation
    freqArray[range] = {0}; // Set each element in freqArray is 0

    // Generates and stores a random number in each index of the array
    for(int i = 0; i < sampleSize; i++){
        int num = rand_Num_Generator(range + 1);
        freqArray[num] += 1;
    }

    // Scaling bar graph so chart doesn't exceed terminal - determines how much each asterisk is worth
    // Max bar size is 60
    int bar = ceil((maxFreq(freqArray, range)) / 60);

    // Calls to print barGraph function
    barGraph(freqArray, range, bar);

    cout << "Scale: " << bar << " per *" << endl;
    cout << endl;
    cout << "Range: " << initial << " to " << range << endl;
    cout << "Sample Count: " << sampleSize << endl;
    cout << "Min Value: " << minFreq(freqArray, range) << endl;
    cout << "Max Value: " << maxFreq(freqArray, range) << endl;
    cout << "Sum Value: " << sum(freqArray, range) << endl;
    cout << "Mean Value: " << mean(freqArray, range) << endl;

    return 0;
}
