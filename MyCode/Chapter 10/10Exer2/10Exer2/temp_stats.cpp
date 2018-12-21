#include "Reading.h"

using namespace std;

vector<Reading> readReadings() {
	string fname = "raw_temps.txt";
	ifstream cin{ fname };
	vector<Reading> data;
	Reading r;

	ifstream fin{ fname };
	if (!fin) throw exception("Cannot open or find file!");

	while (fin >> r && !fin.eof())
		data.push_back(r);
	if (fin.eof())
		cout << "Entire file loaded\n";
	else if (!fin)
		throw exception("Unexpected error!");

	for (auto& r : data) {
		if (r.type == 'C') {
			r.temperature = r.temperature *9.0 / 5.0 + 32;
			r.type = 'F';
		}
	}


	double mean = 0;
	double median = 0;

	sort(data.begin(), data.end(), 
		[](const Reading& r1, const Reading& r2)
		{
			return r1.temperature > r2.temperature;
		}
	);

	for (auto& r : data) {
		mean += r.temperature;
		if (data.size() % 2) {
			median = data[data.size() / 2].temperature + data[data.size() / 2 + 1].temperature;
		}
		else {
			median = data[static_cast<unsigned int>(round(data.size() / 2))].temperature;
		}
	}mean /= data.size();
	cout << "Mean: " << mean << " Median: " << median;
	return data;
}
