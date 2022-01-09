#include "Matrix.h"
#include "Vector.h"
#include <stdio.h>
#include <cmath>
#include <iostream>
#include <iomanip>


Matrix::Matrix(int size1) {
	this->size1 = size1;
	arr = new double* [size1];
	for (int i = 0; i < size1; i++)
		arr[i] = new double[size1];
	initializeArray();
}

void Matrix::initializeArray() {
	
	for (int i = 0; i < size1; i++)
	{
		for (int j = 0; j < size1; j++)
		{
			*(*(arr + i) + j) = sqrt(i + j + 1);

		}

	}
}
void Matrix::make1D() {
	int size1D = size1 * size1;
	mas1D = new double[size1D];
	int m = 0;


	for (int i = size1 - 1; i >= 0; i--)
	{
		for (int j = 0; j < size1; j++)
		{
			mas1D[m] = *(*(arr + i) + j);
			m++;
		}

	}
	printf("Resulting 1D\n");
	for (int i = 0; i < size1 * size1; i++) {
		printf("%f", *(mas1D + i));
		printf(" ");
	}
	printf("\n\n");
}

void Matrix::print() {
	printf("Matrix\n");
	for (int i = 0; i < size1; i++) {
		printf(i == 0 ? "" : "\n");
		for (int j = 0; j < size1; j++) {
			printf("%f", *(*(arr + i) + j));
			printf(" ");
		}
	}
	printf("\n");
	printf("\n");
}


int Matrix::at(int i, int j) const {
	return *(*(arr + i) + j);
}

void Matrix::setAt(int i, int j, int value) {
	*(*(arr + i) + j) = value;
}

//prefix
Matrix& Matrix::operator++() {
	for (int i = 0, count = 0; i < size1; i++) {
		for (int j = 0; j < size1; j++, count++) {
			++(*(*(arr + i) + j));
		}
	}
	return *this;
}

Matrix& Matrix::operator--() {
	for (int i = 0, count = 0; i < size1; i++) {
		for (int j = 0; j < size1; j++, count++) {
			--(*(*(arr + i) + j));
		}
	}
	return *this;

}

//postfix
Matrix Matrix::operator++(int) {
	for (int i = 0, count = 0; i < size1; i++) {
		for (int j = 0; j < size1; j++, count++) {
			(*(*(arr + i) + j))++;
		}
	}
	return Matrix(1);
}

Matrix Matrix::operator--(int) {
	for (int i = 0, count = 0; i < size1; i++) {
		for (int j = 0; j < size1; j++, count++) {
			(*(*(arr + i) + j))--;
		}
	}
	return Matrix(1);
}

Matrix::~Matrix() {
	for (int i = 0; i < size1; i++) {
		delete[] * (arr + i);
	}
	delete[] arr;
}
