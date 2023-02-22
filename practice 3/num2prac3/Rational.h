#pragma once
class Rational
{
private:
	int a, b;
public:
	Rational();
	Rational(int a1, int b1);
	void set(int a1, int b1);
	void show();
private:
	int fgcd(int a1, int b1);
};