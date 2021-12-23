// Euler_034_CPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Find the sum of all numbers which are equal to the sum of the factorial of their digits.

#include <iostream>
#include <vector>
#include "math.h"

using namespace std;

int factorial(int n)
{
    if (n > 1)
        return n * factorial(n - 1);
    else
        return 1;
}


int main()
{
    //vector<int> vect;
    int n = 2540160;
    int grandTotal = 0;
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

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
