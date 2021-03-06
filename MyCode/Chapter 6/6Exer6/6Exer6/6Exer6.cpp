#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int conj() {
	string s;
	cin >> s;
	if (s == "and" || s == "or" || s == "but")
		return 1;
	else
		return 0;
}
int noun(string s) {
	if (s == "birds" || s == "fish" || s == "C++")
	{
		return 1;
	}
	else
		return 0;
}
int verb(string s) {
	if (s == "rules" || s == "fly" || s == "swim")
		return 1;
	else
		return 0;
}
bool isempty() {
	char c;
	cin >> c;
	if (c != '.')
	{
		cin.putback(c);
		return false;
	}
	else 
		return true;
}

int sentence(string s1, string s2){
	if (noun(s1) && verb(s2) && isempty()) 
		return 1;
	else
	{
		if (noun(s1) && verb(s2)) {
			if (conj()) {
				if (isempty())
					throw invalid_argument("Lack of ingredients!");
				string ss1; string ss2;
				cin >> ss1 >> ss2;
				if (sentence(ss1, ss2))
					return 1;
			}
		}
		else
			throw invalid_argument("Not a word!");
	}
}


//------------------------------------------------------------------------------

int main()
{
	string s1; string s2;
	while (true) {
		try
		{
			cin >> s1 >> s2;
			if (sentence(s1, s2)) {
				cout << "Ok\n";
			}
			else {
				cout << "NOT OK\n";
			}
		}
		catch (const std::exception& e)
		{
			cout << e.what() << endl << "Error in main\n";
		}
	}
}

//------------------------------------------------------------------------------