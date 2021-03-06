#include "pch.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;



int main()
{
	vector<double> v(2);
	string str_input;
	int b = '|';

	while (1) {
		cin.clear();
		cin >> str_input;

		if (str_input == "|")
			break;
		try {
			stoi(str_input);
		}
		catch (const std::invalid_argument& ia) {
			std::cerr << "Invalid argument: " << ia.what() << '\n';
			break;
		}

		// Passed errors
		v[0] = stoi(str_input);
		cin >> v[1];

		cout << "Numbers added:\n";
		for (double x : v)
			cout << x << ' ';
		cout << endl;

		v[0] > v[1] ? cout << "Larger is: " << v[0] << endl : cout << "Larger is: " << v[1] << endl;
		v[0] < v[1] ? cout << "Smaller is: " << v[0] << endl : cout << "Smaller is: " << v[1] << endl;
		abs(v[0] - v[1]) < 0.1 * v[0] ? cout << "Numbers are almost equal!\n" : cout << "numbers are far apart!\n";

		

	}


}

