#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <time.h>
#include <sstream>

using namespace std;

int main()
{
	cout << "File name:\n";
	string fn;
	cin >> fn;
	ifstream is{ fn };
	if (!is) throw exception("Cannot open file!\n");


	string inpt;
	ostringstream out;
	while (is >> inpt && is) {
		if (inpt == "don't")
			out << "do not" << ' ';
		else if (inpt == "can't")
			out << "cannot" << ' ';
		else
			out << inpt << ' ';
	}
	string output = out.str();
	for (unsigned int i = 0; i < output.size(); i++) {
		if (output[i] == '"')
			while (true)
			{
				i++;
				if (output[i] == '"' || i == output.size())
					break;
			}
		else if (output[i] == '-' && isalpha(output[i + 1]) && isalpha(output[i - 1]))
			;
		else if (ispunct(output[i]))
			output[i] = ' ';
		else if (isupper(output[i]))
			output[i] = tolower(output[i]);
	}
	cout << output;
}