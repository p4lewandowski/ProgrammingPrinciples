// 3.9.2 Conversions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	double d = 0;
	while (cin >> d) { // re pe at the stateme nts be low
	// as long as we type in numbe rs
		int i = d; // try to sque e ze a double into an int
		char c = i; // try to sque e ze an int into a char
		int i2 = c; // ge t the inte ge r value of the characte r
		cout << "d==" << d // the original double
			<< " i==" << i // conve rte d to int
			<< " i2==" << i2 // int value of char
			<< " char(" << c << ")\n"; // the char
	}
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
