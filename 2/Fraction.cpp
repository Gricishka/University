#include "Fraction.h"
#include <cmath>
#include <sstream>
#include <iomanip>
#include <iostream>

Fraction::Fraction(double val) {
	cntr++;

	this->val = val;

    this->numberOfDecimalPlaces = getNumberOfDecimalPlaces();
	
	double whole;
	this->numerator = fractionalPartToInt(val, &whole);
	this->whole = (int)(whole);

	this->denominator = (int)(pow(10, numberOfDecimalPlaces));
}

void Fraction::setValue(double val) {
    this->val = val;
}

double Fraction::getValue() {
    return val;
}

int Fraction::fractionalPartToInt(double number, double* integer, int numberOfDecimalPlaces) {
	double frac = modf(number, &(*integer));
	return round(frac * pow(10, numberOfDecimalPlaces));
}

int Fraction::fractionalPartToInt(double number, double* integer) {
	double frac = modf(number, &(*integer));
	return round(frac * pow(10, numberOfDecimalPlaces));
}

int Fraction::getNumberOfDecimalPlaces() {
	int zeros = 0;
	std::stringstream ss;
	ss << std::setprecision(15) << val;
	std::string strNum = ss.str();
	size_t pos = strNum.find('.');
	if (pos != strNum.npos)
		zeros = strNum.size() - 1 - pos;
	return zeros;
}

int Fraction::getNumberOfDecimalPlaces(double val) {
	int zeros = 0;
	std::stringstream ss;
	ss << std::setprecision(15) << val;
	std::string strNum = ss.str();
	size_t pos = strNum.find('.');
	if (pos != strNum.npos)
		zeros = strNum.size() - 1 - pos;
	return zeros;
}

void Fraction::printAsFraction(double decimal_fraction) {
	Fraction a = Fraction::Fraction(decimal_fraction);
	a.reduce();
	a.printAsFraction();
}

void Fraction::printAsFraction(char* decimal_fraction) {
	std::string str(decimal_fraction);
	double decimalNumber = std::stod(str);

	Fraction a = Fraction::Fraction(decimalNumber);
	a.reduce();
	a.printAsFraction();
}

void Fraction::printAsFraction(Fraction fraction) {
	fraction.printAsFraction();
}

void Fraction::printAsFraction() {
	printf("\n%.0f %d/%d", whole, numerator, denominator);
}

void Fraction::reduce() {
	int gcdData = gcd(numerator, denominator);

	numerator /= gcdData;
	denominator /= gcdData;
}

int Fraction::gcd (int n, int m) {
    int tmp;
    while (m != 0) {
        tmp = n;
        n = m;
        m = tmp % m;
    }
    return n;
}


Fraction::Fraction(int n, int d) {
	if (d == 0) std::cout << "Invalid denominator";
	numerator = n;
	denominator = d;
}

Fraction Fraction::operator+(const Fraction& f) {
	int n = numerator * f.denominator + f.numerator * denominator;
	int d = denominator * f.denominator;
	reduce();
	Fraction result(n, d);
	return result;
}

Fraction Fraction::operator-(const Fraction& f) {
	int n = numerator * f.denominator - f.numerator * denominator;
	int d = denominator * f.denominator;
	reduce();
	Fraction result(n, d);
	return result;
}

Fraction Fraction::operator*(const Fraction& f) {
	int n = numerator * f.numerator;
	int d = denominator * f.denominator;
	reduce();
	Fraction result(n, d);
	return result;
}

Fraction Fraction::operator/(const Fraction& f) {
	int n = numerator * f.denominator;
	int d = denominator * f.numerator;
	reduce();
	Fraction result(n, d);
	return result;
}

Fraction::~Fraction() {
	cntr--;
}