// 4.4.2.1Alphabet.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
    cout << "My Alphabet!\n"; 
	int iter = 'A';
	while (iter < 123) {
		if (iter >= 91 && iter <= 96)
			cout << "\n";
		else
			cout << (char)iter << "\t" << iter << "\n";
		iter++;
	}

	cout << "\n\nMy digits and letters!\n";
	for (int i = 48; i < 58; i++) {
		cout << i << "\t" << (char)i <<"\n";
	} cout << "\n";	
	for (int i = 65; i < 91; i++) {
		cout << i << "\t" << (char)i << "\n";
	} cout << "\n";
	for (int i = 97; i < 123; i++) {
		cout << i << "\t" << (char)i << "\n";
	} cout << "\n";
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
