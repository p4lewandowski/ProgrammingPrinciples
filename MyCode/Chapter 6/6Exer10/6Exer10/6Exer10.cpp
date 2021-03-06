#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int factorial(int a) {
	int number = a;
	for (int i = a-1; i > 0; i--)
		number *= i;
	return number;
}

int permutation(int a, int b) {
	if (a < 1 || b < 1) 
		throw invalid_argument("Number is lower than 1!\n");
	if(a< b)
		throw invalid_argument("First number is lower than the second!\n");
	if (a - b < 1)
		throw invalid_argument("First number minus second is lower than one!\n");


	return factorial(a) / (factorial(a - b));
}

int combination(int a, int b) {
	if (a < 1 || b < 1) 
		throw invalid_argument("Number is lower than 1!\n");
	if (a < b)
		throw invalid_argument("First number is lower than the second!\n");
	return permutation(a, b) / factorial(b);
}


int main()
{
	int a;
	int b;
	char c;

	while (true) {
		
		cout << "Enter two numbers or -1 to quit:";
		if (cin >> a)
		{
			if (a == -1)
				break;
			if (cin >> b)
			{
				while (cout << "Enter:\np - permutations\nc - combination:\nb - break\n" && cin >> c) {

					if (c == 'p')
					{
						try
						{
							cout << "Outcome of permutation is: " << permutation(a, b) << endl;
						}
						catch (const std::exception& e)
						{
							cout << e.what() << "Error when calculating permutation!\n";
							break;
						}
					}
					else if (c == 'c') {
						try
						{
							cout << "Outcome of combination is: " << combination(a, b) << endl;
						}
						catch (const std::exception& e)
						{
							cout << e.what() << "Error when calculating permutation!\n";
							break;
						}
					}
					else if (c == 'b')
						break;
					else {
						cout << "Wrong command entered! Try again.\n";
					}
				}
			}
			else if (!cin.eof()) {
				cin.clear();
				cout << "invalid character ('" << char(cin.get()) << "') ignored - try again\n";
			}
		}
		else if (!cin.eof()) {
			cin.clear();
			cout << "invalid character ('" << char(cin.get()) << "') ignored - try again\n";
		}
	}
	cout << "Program will be closed.\n";
	return 0;
}
