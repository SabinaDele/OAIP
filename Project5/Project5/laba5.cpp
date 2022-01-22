#include<conio.h>
#include<stdlib.h>
#include<cmath>
#include<iostream>
#include<ctime>
#include<iomanip>;
#include "laba5.h"


using namespace std;

void Summa(int i_min, int n, int* arr);
void printArray(int n, int* arr);
void generateArray(int n, int* arr, int b, int a);


int main()

{
	setlocale(0, "russian");
	int a, b;
	srand(time(NULL));

	while (true)
	{
		cout << "Введите нижний предел массива" << endl;
		cin >> a;
		if (cin.get() == '\n')
		{
			break;
		}
		else
		{
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Некорректный ввод!" << endl;
		}
	}

	
	while (true)
	{
		cout << "Введите верхий предел массива" << endl;
		cin >> b;
		if ((cin.get() == '\n'))
		{
			break;
		}
		else
		{
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Некорректный ввод!" << endl;
		}
	}

	int n;

	do {
		cout << "Введите размер массива" << endl;
		cin >> n;
	} while (n < 1);

	int* arr = new int[n];
	generateArray(n, arr, b, a);

	printArray(n, arr);
	cout << endl;

	int i_min = 0;
	for (int i = 1; i < n; ++i)
	{
		if (arr[i] <= arr[i_min])
		{
			i_min = i;
		}

	}
	cout << " Минимальный элемент = " << arr[i_min] << endl;
	cout << " Индекс минимального элемента = " << i_min << endl;


	if (i_min == (n - 1))
	{
		cout << "Суммы нет,т.к минимальный элемент массива-последний" << endl;
		return 0;
	}

	Summa(i_min, n, arr);



	delete[]arr;
	system("pause");
	return 0;

}

void generateArray(int n, int* arr, int b, int a)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % (b - a + 1) + a;
	}
}

void Summa(int i_min, int n, int* arr)
{
	int sum = 0;
	for (int i = i_min + 1; i < n; ++i)
	{
		sum += arr[i];

	}
	cout << "Сумма элементов массива, после минимального =" << sum << endl;
}

void printArray(int n, int* arr)
{
	cout << "Result array: ";

	for (int i = 0; i < n; i++)

	{
		cout << arr[i] << " ";


	}
}
