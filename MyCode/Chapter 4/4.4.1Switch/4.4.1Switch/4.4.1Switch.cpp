// 4.4.1Switch.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;

int main() // e xample of bad code (a bre ak is missing)
{
	constexpr double cm_per_inch = 2.54; // numbe r of ce ntime te rs in
	// an inch
	double length = 1; // le ngth in inche s or
	// ce ntime te rs
	char unit = 'a ';
	cout << "Please enter a length followed by a unit (c or i):\n";
	cin >> length >> unit;
	switch (unit) {
		case 'i':
			cout << length << "in == " << cm_per_inch * length << "cm\n";
			break; // when there is no break it will go down from this point
		case 'c': case 'v':
			cout << length << "cm == " << length / cm_per_inch << "in\n";
			// break;
		case 'd':
			cout << "you see?\n";
			break;
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
