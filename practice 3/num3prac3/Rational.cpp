#include "Rational.h"
#include <iostream>
using namespace std;


int Rational::fgcd(int a, int b) { // 
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
Rational Rational::operator+(Rational other) {
	int new_a = a * other.b + b * other.a;
	int new_b = b * other.b;
	return Rational(new_a, new_b);
}
void Rational::operator++() {
	a++;
}
bool Rational::operator==(Rational other) {
	return a == other.a && b == other.b;
}
bool Rational::operator>(Rational other) {
	return a * other.b > other.a * b;
}
Rational& Rational::operator=(Rational other) {
	a = other.a;
	b = other.b;
	return *this;
}