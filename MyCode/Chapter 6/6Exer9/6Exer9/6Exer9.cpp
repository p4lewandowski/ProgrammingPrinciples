#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void display_number(vector<char> cnum, vector<string> names) {
	if (cnum.size() <= 0) throw invalid_argument("Number entered is invalid, length equal to 0!\n");
	else if (cnum.size() > 4)  throw invalid_argument("Number entered is invalid, larger than 4 digits!\n");
	else {
		cout << "The number is:\n";
		for (int i = 0; i < cnum.size(); i++) {
			cout << cnum[i] << names[4 - cnum.size() + i] ;
			if (cnum[i] - '0' > 1) cout << 's';
			cout << ' ';
		}
		cout << endl;
	}
}

int main()
{
	vector<char> number;
	vector<string> names{ " thousand", " hundred" , " ten" , " one" };
	char c;
	cout << "Enter the number up to 4 digits, terminating with semicolon, q to quit: ";

	while (true)
	{
		number.clear();
		while (true) {
			cin >> c;
			if (c == ';')
				break;
			else if (c == 'q')
			{
				cout << "Quiting the app";
				return 0;
			}
			else
				number.push_back(c);
		}
		try {
			display_number(number, names);
		}
		catch (const std::exception& e)
		{
			cerr << "Error in display_number: " << e.what();
		}
	}
}
