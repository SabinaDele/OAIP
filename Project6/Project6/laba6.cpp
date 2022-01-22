#include<conio.h>
#include<stdlib.h>
#include<cmath>
#include<iostream>
#include<ctime>
#include<iomanip>;

void generateElements(int n, int m, int** arr);
void NumberofElements(int n, int m, int** arr);
void vvodElements(int n, int m, int** arr);
void deleteArray(int n, int** arr);
using namespace std;

int main()
{
	setlocale(0, "russian");
	srand(time(0));

	int n, m;
	cout << "������� ������ �������" << endl;

	
	while (true)
	{
		cout << "������� ���������� ����� ������� ������ 1" << endl;
		cin >> n;
		if (cin.get() == '\n')
		{
			break;
		}
		else
		{
			cin.clear();
			cin.ignore(256, '\n');
			cout << "������������ ����!" << endl;
		}
	}

	

	
	while (n < 1)
	{
		cout << "����� ������������! ������� ���������� ����� ������� ��� ���" << endl;
		cin >> n;
	}

	
	
	while (true)
	{
		cout << "������� ���������� �������� ������� ������ 2" << endl;
		cin >> m;
		if (cin.get() == '\n')
		{
			break;
		}
		else
		{
			cin.clear();
			cin.ignore(256, '\n');
			cout << "������������ ����!" << endl;
		}
	}

	while (m < 3)
	{
		cout << "�������� ������������! ������� ���������� �������� ������� ��� ���" << endl;
		cin >> m;
	}

	int** arr = new int* [n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[m];
	}
	cout << "�������� ����� ���������� �������" << endl;

	int choice;

	cout << "������� 1, ���� ������ ��������� ������ �������" << endl;
	cout << "������� 2, ���� ������ ��������� ������ ��������" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:vvodElements(n, m, arr);
		break;
	case 2:generateElements(n, m, arr);
		break;

	}

	for (int i = 0; i < n; ++i, cout << "\n") {
		for (int j = 0; j < m; ++j) {
			cout.precision(10); cout << fixed;
			cout << setw(15) << arr[i][j] << " ";
		}
	}
	cout << "\n";
	NumberofElements(n, m, arr);

	deleteArray(n, arr);


}

void NumberofElements(int n, int m, int** arr)
{
	int number = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j < m - 1; j++)
		{

			if ((arr[i][j] > arr[i][j - 1]) && (arr[i][j] < arr[i][j + 1]))
			{
				number += 1;
			}


		}
	}
	cout << " ���������� ���������, � ������� ������� ����� ������ ����, � ������ ������ = " << number;
}

void generateElements(int n, int m, int** arr)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			arr[i][j] = rand();


		}

}

void vvodElements(int n, int m, int** arr)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cout << "������� arr[" << i << "][" << j << "]=";
			cin >> arr[i][j];
		}
}

void deleteArray(int n, int** arr)
{
	for (int i = 0; i < n; i++)
		delete[] arr[i];

	delete[]arr;

}


int InputNum() {
	int number;

	while (!(cin >> number) || (cin.get() != '\n')) {
		cout << "������! " << endl;
		cin.clear();
		while (cin.get() != '\n');
	}
	return number;

}
