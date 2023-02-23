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
    Rational operator+(Rational other);
    void operator++();
    bool operator==(Rational other);
    bool operator>(Rational other);
	Rational& operator=(Rational other);
    friend Rational operator-(Rational first, Rational second);
private:
	int fgcd(int a1, int b1);
};