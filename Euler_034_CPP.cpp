// Euler_034_CPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Find the sum of all numbers which are equal to the sum of the factorial of their digits.
//Code modified from Euler_CPP_024

#include <iostream>
#include <vector>
#include "math.h"

using namespace std;

int factorial(int n) //return factorial
{
    if (n > 1)
        return n * factorial(n - 1);
    else
        return 1;
}

int main()
{
    int n = 2540160; //upperbound (9! * 7 < 10e8)
    int grandTotal = 0; //final answer var
    for (int i = 3; i < n; i++) //checks all numbers after 1, before limit
    {
        int temp = i;
        vector<int> vect;
        while (temp != 0) //separates ints into digits
        {
            vect.push_back(temp % 10);
            temp /= 10;

        }
        //reverse(vect.begin(),vect.end()); //puts digits in right order, but unncessary here
        int total = 0; //total of powers of digits of singular number
        for (int j = 0; j < vect.size(); j++) //add each digit factorial
        {
            total = total + factorial(vect[j]);
            //cout << total << endl;

        }
        if (total == i) //for adding all viable numbers
        {
            cout << i << endl;
            grandTotal += i;
        }
    }
    cout << "The answer is " << grandTotal << endl;
}