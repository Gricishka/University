// Вариант 8
// Павликов Д.О. | ИВТ-4 (ускор.) | Lab2 
#include "Matrix.h"
#include "CameraMan.h"
#include "Fraction.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdio.h>


using namespace std;
void printInfo(CameraMan a, CameraMan b, CameraMan c) {

	int const N = 3;
	CameraMan mas[N] = { a,b,c };
	CameraMan temp;


	for (int i = 0; i < N; i++) {
		for (int j = i; j < N - 1; j++) {
			if (mas[j].rating < mas[j + 1].rating) {
				temp = mas[i];
				mas[i] = mas[j];
				mas[j] = temp;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		cout << i + 1 << ") " << mas[i].name << " " << mas[i].surname << "\n" << setprecision(3) << mas[i].rating << endl; // setprecision(4) - округление (для красоты)
	}
}


void Part1() {
	cout << "------------------Part 1------------------\n";
	Matrix* mat = new Matrix(4);
	(*mat).print();
	(*mat).make1D();
	++(*mat); 
	(*mat).print();
	(*mat)++;
	(*mat).print();
	--(*mat);
	(*mat).print();
	(*mat)--;
	(*mat).print();
	
	
}


int	Fraction::cntr = 0;
void Part2() {

	cout << "\n------------------Part 2------------------\n";


	Fraction n(0.05);
	Fraction m(.1);
	Fraction a(.05);
	Fraction b(1.4);
				

	m.printAsFraction(0.43);	//  43/100
	m.printAsFraction();		// 1/10	
	char t[] = "0.22";			// 11/50
	m.printAsFraction(t);
	
	Fraction f1(1, 6);
	Fraction f2(1, 5);
	
	cout << "\n\n+";
	Fraction add = (f1 + f2);		
	add.printAsFraction();		
			
	cout << "\n\n-";
	Fraction sub = (f1 - f2); 
	sub.printAsFraction();		
			
	cout << "\n\n*";
	Fraction imul = (f1 * f2);
	imul.printAsFraction();		
	
	cout << "\n\n/";
	Fraction idiv = (f2 / f1);
	idiv.printAsFraction();			

	printf("\n\nCounter: %d", Fraction::cntr);
	printf("\n");
}


void Part3() {
	cout << "\n------------------Part 3------------------\n";
	CameraMan* cameraman_1 = new CameraMan("Nikita", "Gricishin", 1, "2002", "2020", 12.1);
	CameraMan* cameraman_2 = new CameraMan("Dmitry", "Davidenko", 1, "2002", "2020", 11.1);
	CameraMan cameraman_3;
	cameraman_3.setName("Alexandr");
	cameraman_3.setSurname("Browa");
	cameraman_3.setSex(1);
	cameraman_3.setBornYear("2002");
	cameraman_3.setStartYear("2020");
	cameraman_3.setRating(10.1);
	cameraman_1->upRating(10);
	CameraMan stats = (cameraman_1, cameraman_2, cameraman_3);
	
	printInfo(*cameraman_1, *cameraman_2, cameraman_3);
	
	cameraman_1->serialize();
	cameraman_1->deserialize();
	cameraman_1->serialize("test.txt");
	cameraman_1->deserialize("test.txt");
	
	delete cameraman_1;
	delete cameraman_2;
}


int main()
{
	Part1();
	Part2();
	Part3();

}

