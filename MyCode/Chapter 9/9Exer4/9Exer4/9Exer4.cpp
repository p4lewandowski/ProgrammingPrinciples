// 9Exer4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

// dange rously ugly code
struct X {
	void f(int x) {
		struct Y {
			int f() {
				return 1; 
			} int m;
		};

		int m;
		m = x;
		Y m2;
		return f(m2.f());
	}

	int m;

	void g(int m) 
	{
		if (m) 
			f(m + 2);
		else {
			g(m + 2);
		}
	}

	X()
	{}

	void m3()
	{
	}
};

void main() {
	X a; a.f(2);
}