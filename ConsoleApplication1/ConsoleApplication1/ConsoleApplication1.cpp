// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	vector<string> words;
	vector<string> beep{ "kurwa", "mac" };
	int isbeep = 0;

	for (string temp; cin >> temp; )
		words.push_back(temp);
	cout << "Number of words: " << words.size() << endl;
	sort(words.begin(), words.end());
	cout << "Unique words:\n";
	for (int i = 0; i < words.size(); ++i)
		if (i == 0 || words[i - 1] != words[i]) // is this a new word?
			cout << words[i] << " ";

	cout << "\nFiltered words:\n";
	for (int i = 0; i < words.size(); ++i) {
		for (int j = 0; j < beep.size(); j++)
			if (words[i] == beep[j]) isbeep = 1;
		if (isbeep) isbeep = 0;
		else cout << words[i] << " ";
	}
}