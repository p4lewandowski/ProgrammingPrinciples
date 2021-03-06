#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <time.h>

using namespace std;

int main()
{
	cout << "File name:\n";
	string fn;
	cin >> fn;
	ifstream is{ fn };
	if (!is) throw exception("Cannot open file!\n");
		
	cout << "Word searched:\n";
	string word;
	cin >> word;
	string line;
	for (int i = 0; getline(is, line); i++)
		if (line.find(word) != std::string::npos)
			cout << i << ' ' << line << endl;

}
