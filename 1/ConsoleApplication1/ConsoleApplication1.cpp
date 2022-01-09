// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>

                                                                                  
int processArray(int A[], int znach, int shag)
{ 
	for (int i = 0; i < 15; i++)
	{
		A[i] = znach + shag;
		znach = znach + shag;

		if (i == 0) {
			
			
			printf("Vvdedite shag massiva");
			printf("\n");
			scanf("%d", &shag);
			
			printf("Shag massiva = ");
			printf("%d ", shag);
			printf("\n");
		}
		std::cout << A[i] << " ";
	}

	
	int cnt = 0;
	for (int i = 0; i < 15; i++)
	{
		if (A[i] > 9 && A[i] < 100) cnt++;
	}

	
	int B[10] = { 0 };
	int j = 0;
	for (int i = 0; i < 15; i++)
	{
		int sum = 0, a;
		a = A[i];
		while (a)
		{
			sum += a % 10;
			a /= 10;
		}
		sum == 10 ? sum : B[j++] = A[i];

	}
	printf("\n");

	
	for (int i = 0; i < 10; i++)
	{
		
		printf("%d ", B[i]);

	}
	printf("\n"); 
	return cnt;
}

                                                                               

char* strcat(char* dest, char* src, size_t maxlen)
{
	
	size_t i = 0;
	for (; dest[i]; i++);
	for (size_t j = 0; src[j] && j < maxlen; j++)
	dest[i++] = src[j];
	dest[i] = 0;
	return dest;
	
}

 void PrintArray(char* mass, size_t size)
{
	 std::cout << "New m1: ";
	for (int i = 0; i < size; i++)
	{
		std::cout << mass[i] << " ";

	}

}


int main()
{   
	/*
	Объявить массив из n = 15 целых чисел, проинициализируйте нулями.Функция processArray() должна заполнить массив членами арифметической прогрессии
	с начальным элементом a1 и шагом d(ввести с клавиатуры), подсчитать и вернуть cnt – количество всех двузначных элементов массива, 
	а также сформировать выходной массив, который содержит все элементы исходного, кроме тех, сумма цифр которых равна 10. Вывести на экран массивы
	*/
	int mas[15] = { 0 };
	int a1, d;
	a1 = 7;
	d = 0;
	
	int result = processArray(mas, a1, d);
	std::cout << "cnt = " << result << std::endl;

	size_t N = 10;
	char* m1 = new char[N]{ 65, 67, 87, 75, '\0'};
	char* m2 = new char[N]{ 87, 88, 89, 90, '\0' } ;
	
	m1 = strcat(m1, m2, N);
	PrintArray(m1, N);
	delete[] m1;
	delete[] m2;

	return 0;
}

