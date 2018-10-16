#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void error(string s1, string s2)
{
	throw runtime_error(s1 + s2);
}

int main()
{
	vector<int> v;

	v.push_back(1);
	try
	{
		try
		{
			throw runtime_error("hehe\n");
		}
		catch (runtime_error e)
		{
			cout << e.what() << endl;
		}

		try
		{
			cout << v.at(1);
		}
		catch (const exception& e)
		{
			cout << e.what() <<endl;
			error(e.what(), "Error in main fuction!\n");
		}
	}
	catch (const exception& e)
	{
		cout << e.what() << " Such error appeared in the application!\n";
	}
	


}


