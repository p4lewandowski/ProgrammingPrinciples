#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> scores;
	vector<string>names;
	int score;
	string name;
	int isUnique = 1;
	string command;
	int points;

	while (cin >> name >> score && !(name == "NoName" && score == 0)) {
		for (int i = 0; i < names.size(); i++) {
			if (name == names[i])
				isUnique = 0;
		}
		if (isUnique) {
			scores.push_back(score);
			names.push_back(name);
			isUnique = 1;
		}
		else
			cout << "Name entered again, write different name!\n";
	}

	for (int i = 0; i < scores.size(); i++) {
		cout << names[i] << " has " << scores[i] << " point(s)" << endl;
	}

	cout << "\nSearch for a player by name\n";
	while (cin >> command && command != "exit") {
		for (int i = 0; i < names.size(); i++) {
			if (command == names[i]){
				isUnique = 0;
				cout << "Player " << command << " has " << scores[i] << " point(s)" << endl;
			}
		}
		if (isUnique)
			cout << "Player not found!\n";
		isUnique = 1;
	}

	cout << "\nSearch for players with score:\n";
	while (cin >> points && points >= 0) {
		for (int i = 0; i < scores.size(); i++) {
			if (points == scores[i]) {
				isUnique = 0;
				cout << "Player " << names[i] << " has " << scores[i] << " point(s)" << endl;
			}
		}
		if (isUnique)
			cout << "No such players!\n";
		isUnique = 1;
	}

}

