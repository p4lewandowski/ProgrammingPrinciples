#include "pch.h"
#include "dec.h"

using namespace std;

int main()
{
	int x = 7;
	int y = 9;
	swap_r (x, y);
	cout << x << ' ' << y << endl;
	//swap_r (7, 9);
	//cout << x << ' ' << y << endl;
	//const int cx = 7;
	//const int cy = 9;
	//swap_r (cx, cy);
	//cout << x << ' ' << y << endl;
	//swap_r (7.7, 9.9);
	//cout << x << ' ' << y << endl;
	double dx = 7.7;
	double dy = 9.9;
	int dxx = int(dx);
	int dyy = int(dy);
	swap_r (dxx, dyy);
	cout << x << ' ' << y << endl;
	//swap_r (7.7, 9.9);
	//cout << x << ' ' << y << endl;


}
