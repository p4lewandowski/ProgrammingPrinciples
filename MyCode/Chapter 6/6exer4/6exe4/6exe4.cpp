#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class ValName {
public:
	string Name;
	int value;

	ValName(string name, int val)
		:Name(name), value(val) {}
};

int main()
{
	vector<ValName> data;
	int score;
	string name;
	int isUnique = 1;
	string command;
	int points;

	while (cin >> name >> score && !(name == "NoName" && score == 0)) {
		for (int i = 0; i < data.size(); i++) {
			if (name == data[i].Name)
				isUnique = 0;
		}
		if (isUnique) {
			data.push_back(ValName(name,score));
			isUnique = 1;
		}
		else
			cout << "Name entered again, write different name!\n";
	}

	for (int i = 0; i < data.size(); i++) {
		cout << data[i].Name << " has " << data[i].value << " point(s)" << endl;
	}

	cout << "\nSearch for a player by name\n";
	while (cin >> command && command != "exit") {
		for (int i = 0; i < data.size(); i++) {
			if (command == data[i].Name) {
				isUnique = 0;
				cout << "Player " << command << " has " << data[i].value << " point(s)" << endl;
			}
		}
		if (isUnique)
			cout << "Player not found!\n";
		isUnique = 1;
	}

	cout << "\nSearch for players with score:\n";
	while (cin >> points && points >= 0) {
		for (int i = 0; i < data.size(); i++) {
			if (points == data[i].value) {
				isUnique = 0;
				cout << "Player " << data[i].Name << " has " << data[i].value << " point(s)" << endl;
			}
		}
		if (isUnique)
			cout << "No such players!\n";
		isUnique = 1;
	}

}

