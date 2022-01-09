#define _CRT_SECURE_NO_WARNINGS
#include "Vector.h"
#include <iostream>
#include <cmath>
#include <stdio.h>

Vector::Vector(int size)
{
	this->size = size;
	mas = new int[size];
	initializeArray();
}

void Vector::initializeArray() {
	znach = 0;
	shag = 7;
	for (int i = 0; i < size; i++)
	{
		mas[i] = znach + shag;
		znach = znach + shag;

		if (i == 0) {

			printf("Vvdedite shag massiva");
			printf("\n");
			scanf("%d", &shag);
			printf("Shag massiva = ");
			printf("%d ", shag);
			printf("\n");

		}
		
	}

}



void Vector::print() {
	printf("Vector\n");
	for (int i = 0; i < size; i++) {
		printf("%d", *(mas + i));
		printf(" ");
	}
	printf("\n");
}



//prefix
Vector& Vector::operator++() {
	for (int i = 0; i < size; i++) {
		++(*(mas + i));
	}
	return *this;
}

Vector& Vector::operator--() {
	for (int i = 0; i < size; i++) {
		--(*(mas + i));
	}
	return *this;

}

//postfix
Vector Vector::operator++(int) {
	for (int i = 0; i < size; i++) {
		(*(mas + i))++;
	}
	return 0;
}

Vector Vector::operator--(int) {
	for (int i = 0; i < size; i++) {
		(*(mas + i))--;
	}
	return 0;
}

int& Vector::operator[] (const int index)
{
	return mas[index];
}

Vector::~Vector() {
	delete[] mas;
}