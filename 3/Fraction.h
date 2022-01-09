#pragma once
class Fraction
{
private:
	double val;
	int numerator, denominator;
	int numberOfDecimalPlaces;
	int whole;
	int fractionalPartToInt(double number, double* integer, int decimalPlaces);
	int fractionalPartToInt(double number, double* integer);
	int getNumberOfDecimalPlaces(double value);
	int getNumberOfDecimalPlaces();
public:
	Fraction(int n, int d);
	static int cntr;
	void addFraction();
	static void printAsFraction(double decimal_fraction);
	void printAsFraction();
	static void printAsFraction(Fraction fraction);
	static void printAsFraction(char* decimal_fraction);
	static int gcd(int n, int m);
	void reduce();
	void setValue(double value);
	double getValue();
	Fraction(double value);
	~Fraction();
	Fraction operator+(const Fraction& f);
	Fraction operator-(const Fraction& f);
	Fraction operator*(const Fraction& f);
	Fraction operator/(const Fraction& f);
};

