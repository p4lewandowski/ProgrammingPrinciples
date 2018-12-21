#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <time.h>
#include <sstream>

using namespace std;

class B1 {
public:
	virtual void vf(){ cout << "B1::vf\n"; }
	void f() { cout << "B1::f\n"; }
	virtual void pvf() = 0;
};

class B2 {
public:
	virtual void pvf() = 0;
};

class D1 : public B1 {
public:
	void vf() { cout << "D1::vf\n"; }
	void f() { cout << "D1::f\n"; }
};

class D2 : public D1{
public:
	void pvf (){ cout << "D2::pvf\n"; }
};

class D21 : public B2 {
public:
	void pvf() { cout << a; }
private:
	string a{ "D21D21\n" };
};

class D22 : public B2 {
public:
	void pvf() { cout << a << endl; }
private:
	int a{ 5 };
};

void f(B2& b) {
	b.pvf();
}


int main()
{
	//B1 b1;
	//b1.vf();
	//b1.f();

	//D1 d1;
	//d1.vf();
	//d1.f();
	//d1.pvf();

	//B1& b1r = d1;
	//d1.vf();
	//d1.f();
	//d1.pvf();

	D2 d2;
	d2.vf();
	d2.f();
	d2.pvf();

	D21 d21;
	D22 d22;
	f(d21);
	f(d22);


}
