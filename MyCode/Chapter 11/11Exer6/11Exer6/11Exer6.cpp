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
	string inpt;
	while (getline(cin, inpt) && cin) {
		for (unsigned int i = 0; i < inpt.size(); i++) {
			if (inpt[i] == '"')
				while (true)
				{
					i++;
					if (inpt[i] == '"' || i==inpt.size())
						break;
				}
			else if (ispunct(inpt[i]))
				inpt[i] = ' ';
		}
		cout << inpt << endl;
	}
}

