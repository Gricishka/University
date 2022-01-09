// ConsoleApplication2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
/* 
ВАРИАНТ 8
Преобразование: 2D → 1D. Двумерный массив 4х4 вещественных чисел необходимо выложить в один ряд по элементам слева направо и снизу вверх.
Инициализация: заполнить массив числами x[i][j] = √(i + j + 1).
Вывод на экран: каждый элемент одномерного массива вывести с точностью четыре знака после запятой; каждый элемент двумерного массива – с точностью два знака
*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double* makeArray1D(double** mass, int size_mass1)
{
    int size_mass2 = size_mass1 * size_mass1;
    double* mas2 = new double[size_mass2];
    int m = 0;


    for (int i = size_mass1 - 1; i >= 0; i--)
    {
        for (int j = 0; j < size_mass1; j++)
        {
            mas2[m] = *(*(mass + i) + j);
            m++;
        }

    }
    return mas2;


}

void initializeArray(double** arr, int n)
{
    for (int i = 0; i < n; i++)
        arr[i] = new double[n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            *(*(arr + i) + j) = sqrt(i + j + 1);

        }
        
    }
    
    
}


void printArray(double* mas)
{
    cout << "-----------------------Part 2-----------------------" << endl<<endl;

    for (int i = 0; i < 16; i++)
    {
        cout << setprecision(4) << fixed << mas[i] << " ";

    }
    cout << endl;
}

void deleteArray(double** arr, int n)
{
    for (int i = 0; i < n; i++)
        delete[] arr[i];
}

int main()
{
    int size1 = 4;
    double** arr = new double* [size1];
    initializeArray(arr, size1);
    double* arr2 = makeArray1D(arr, size1);
    printArray(arr2);
    deleteArray(arr, size1);
    delete[] arr;
    delete[] arr2;
    return  0;
}



