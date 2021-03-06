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

	ifstream is{ "in.txt" };
	if (!is) throw exception("Cannot open file!\n");
	
	string s;
	vector<string> vs;

	while (is >> s)
		vs.push_back(s);

	ofstream os{ "out.txt" };
	if (!os) throw exception("Cannot open file!\n");
	for (auto i = vs.rbegin(); i != vs.rend(); ++i)
		os << *i << ' ';
}

