#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<string> names{ "one", "two", "three", "four" };
	vector<double>values{ 1, 2, 3, 4 };
	string input;
	int number;

	while (cin >> input) {
		if (input == "break")
			break;
		try {
			number = stoi(input);
			switch (number) {
			case 1: {
				cout << "one\n";
				break;
			}
			case 2: {
				cout << "two\n";
				break;
			}
			case 3: {
				cout << "three\n";
				break;
			}
			case 4: {
				cout << "four\n";
				break;
			}
			default:
				cout << "Number out of range 1-4\n";
			}

		}
		catch (const std::invalid_argument& ia) {
			if (input == "one") cout << 1 << endl;
			else if (input == "two") cout << 2 << endl;
			else if (input == "three") cout << 3 << endl;
			else if (input == "four") cout << 4 << endl;
			else cout << "Word out of range one-four\n";
		}

	}
}

