#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <time.h>
#include <sstream>

using namespace std;

bool contains(char c, const string& sep) {
	for (const char&s : sep)
		if (c == s)
			return true;
	return false;
}

vector<string> split(const string& s, const string& w) {
	
	vector<string> out;
	string ss = s;

	for (char& c : ss)
	{
		if (contains(c, w))
			c = ' ';
	}

	istringstream iss{ ss };
	while (iss >> ss)
		out.push_back(ss);

	return out;
}


int main()
{
	vector<string> separeted_text = split("moja mama lubi mak, po co mak mojej mamie jak ona maku nie odda.", "ke");
	for (string& s : separeted_text)
		cout << s << endl;
}

