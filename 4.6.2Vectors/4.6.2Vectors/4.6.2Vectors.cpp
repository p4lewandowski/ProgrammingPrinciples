#include "pch.h"
#include <iostream>
#include <string>
#include<vector>

using namespace std;



int main()
{
    cout << "Hello World!\n"; 
	vector<int>v(3); // only sets size (and 0s in ints place)
	v.push_back(2); // adds to the end
	v.push_back(3);

	for (int x : v)
		cout << x << ' ';

}

