#pragma once

class Vector
{
private:
	int* mas;
	int* sort_mas;
    int size;
	int znach;
	int shag;
	void initializeArray();
public:
	Vector(int size);
	void print();
	int& operator[] (const int index);
	Vector& operator++();
	Vector& operator--();
	Vector operator++(int);
	Vector operator--(int);
	~Vector();
};

