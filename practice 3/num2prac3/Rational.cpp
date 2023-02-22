#include "Rational.h"
#include <iostream>
using namespace std;


int Rational::fgcd(int a, int b) { // вычисление НОД
	while (b != 0) {
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}


Rational::Rational() {
}
Rational::Rational(int a1, int b1) {
	if (b1 != 0) {
		if (a1 > b1) {
			a1 -= (a1 / b1) * b1;
		}
		int gcd = fgcd(a1, b1);
		a = a1 / gcd;
		b = b1 / gcd;
	}
	else {
		exit(1);
	}
}
void Rational::set(int a1, int b1) {
	if (b1 != 0) {
		if (a1 > b1) {
			a1 -= (a1 / b1) * b1;
		}
		int gcd = fgcd(a1, b1);
		a = a1 / gcd;
		b = b1 / gcd;
	}
	else {
		exit(1);
	}
}
void Rational::show() {
	cout << a << "/" << b;
}