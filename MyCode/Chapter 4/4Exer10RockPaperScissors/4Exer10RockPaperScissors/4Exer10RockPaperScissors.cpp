#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int max = 2;
	int min = 0;
	vector<int> commands;
	char option = 'g';
	int aim = 3;
	int pc_score = 0;
	int user_score = 0;
	int count = 0;

	cout << "r - rock\ns - scissors\np - paper\n";

	for(int i = 0; i < 100 ; ++i)
		 commands.push_back(min + (rand() % static_cast<int>(max - min + 1)));
	
	while (pc_score < 3 && user_score < 3) {
		cin >> option;
		cout << endl;

		switch (option) {

		case 'r':
			switch (commands[count]) {
			case 0:
				cout << "You used rock and computer used rock: draw" << endl;
				break;
			case 1:
				cout << "You used rock and computer used scissors: + point for user" << endl;
				user_score++;
				break;
			case 2:
				cout << "You used rock and computer used paper + point for computer" << endl;
				pc_score++;
				break;
			}
			break;

		case 's':
			switch (commands[count]) {
			case 0:
				cout << "You used scissors and computer used rock: + point for computer" << endl;
				pc_score++;
				break;
			case 1:
				cout << "You used scissors and computer used scissors: draw" << endl;
				break;
			case 2:
				cout << "You used scissors and computer used paper: + point for user" << endl;
				user_score++;
				break;
			}
			break;

		case 'p':
			switch (commands[count]) {
			case 0:
				cout << "You paper rock and computer used rock: + point for user" << endl;
				user_score++;
				break;
			case 1:
				cout << "You paper rock and computer used scissors: + point for computer" << endl;
				pc_score++;
				break;
			case 2:
				cout << "You paper rock and computer used paper - draw" << endl;
				break;
			}
			break;
		default:
			cout << "wrong command!\n";
		}
		cout << "SCORE\nCOMPUTER: " << pc_score << "\nUSER: " << user_score << endl;
		count++;
	}
	if (pc_score > user_score)
		cout << "Computer wins!" << endl;
	else cout << "User wins!" << endl;
}

