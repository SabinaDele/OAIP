#include<conio.h>
#include<cmath>
#include<iostream>
using namespace std;

typedef  double (*Function) (double,int);

double InputNum();
double functionY(double,int);        			//  Y(x)
double summaS(double,int);        			// S(x)
double raznost(double,int);       			// |s-y|
void  Print(Function, double, double, double,int);


void  main()
{
	setlocale(0, "russian");
	int  n;
	double a, b, h;
	cout << "Введите значения a: ";
	a = InputNum();
	cout << "Введите значения  b: ";
	b = InputNum();
	cout << "Введите значения h: ";
	h = InputNum();
	cout << "Введите значения n: ";
	n = InputNum();
	cout << endl << endl;
	int choice;
	cout << "Выберите нужную вам функцию.\nВведите 1, если хотите увидеть Y(x).\nВведите 2, если хотите увидеть S(x). \nВведите любой другой символ, если хотите увидеть|Y(x)-S(x)|" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1: cout << " Вывод результатов для функции Y(x) " << endl;
		Print(functionY, a, b, h,n);
		break;
	case 2: cout << " Вывод результатов для суммы S(x)" << endl;
		Print(summaS,a, b, h,n);
		break;
	default: cout << " Вывод результатов для разности |Y(x)-S(x)| " << endl;
		Print(raznost, a, b, h,n);
		break;
	}
	
}

double  functionY(double x, int n)
{
	return  (((x * x) / 4) + (x / 2) + 1) * exp(x / 2);
}

double  raznost(double x,int n)
{
	int z = functionY(x,n);
	int y = summaS(x,n);
	return fabs(z-y);
}


double  summaS(double x, int n)
{
	double sum,powx;
	int fac;
	fac = powx = 1;
	sum = 0;
	for (int k = 0; k <= n; k++)
	{
		fac *= k == 0 ? 1 : k;
		sum += ((pow(k, 2) + 1.0) / fac) * powx;
		powx *= (x / 2);
	}

	return sum;
}



void  Print(Function  f ,double a, double b, double h, int n)
{
	for (double x = a; x <= b; x += h)
		cout << "x = " << x << "\t res = " << f(x,n) << endl;

	
}

double InputNum() {
	double number;

	while (!(cin >> number) || (cin.get() != '\n')) {
		cout << "Ошибка! " << endl;
		cin.clear();
		while (cin.get() != '\n');
	}
	return number;

}
