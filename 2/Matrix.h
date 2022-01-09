#include "Vector.h"
#pragma once

class Matrix
{
private:
	double** arr;
	double* mas1D;
	int size1; // height = width
	void initializeArray();
	//double *arr1D = make1D;
public:
	Matrix();
	Matrix(int size1);
	Matrix(double* array1D, int size1);
	void make1D();
	int at(int i, int j) const;
	void setAt(int i, int j, int value);
	void print();
	Matrix& operator++();
	Matrix& operator--();
	Matrix operator++(int);
	Matrix operator--(int);
	~Matrix();
};

