#include "Reading.h"

using namespace std;
const int min_temp = -100;
const int max_temp = 200;

void createReadings(int n) {
	string fname = "raw_temps.txt";
	ofstream os{ fname };
	if (!os)
		throw exception("Cannot create file!");

	srand(time(NULL));

	while (n--) {
		int h = rand() % 24 + 1;
		double t = float(rand()) / float(RAND_MAX) * 300 - 100;
		char c = rand() % 10 + 1 > 5 ? c = 'C' : c = 'F';
		Reading r{ h, t, c};
		os << r;
	}
}

