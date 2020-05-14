#include "quadrate.h"
//#include "Menu.h"
#include <iostream>
#include <cmath>

using namespace std;

quadrate::quadrate(int n, double* cordd, int l)
{
	this->n = n;
	this->l = l;
	for (int i = 0; i < 8; i++) { cord[i] = cordd[i]; }
}

quadrate::quadrate()
{
}


template<typename T>
T quadrate::check(T a)
{

	while (!(cin >> a) || (cin.peek() != '\n'))
	{
		cout << endl;
		cin.clear();
		cin.ignore((numeric_limits<streamsize>::max)(), '\n');
		cout << "Некоректные данные, попробуйте снова" << endl;
	}

	return a;
}

int quadrate::Create()
{
	system("cls");

	n++;
	cout << "Квадрат №" << n << endl;

	cout << "Напишите координату x левого нижнего угла квадрата: ";
	cord[0] = check(cord[0]);

	cout << "Напишите координату y левого нижнего угла квадрата: ";
	cord[1] = check(cord[1]);

	cout << "Напишите длину стороны квадрата: ";
	while (!(cin >> l) || (cin.peek() != '\n') || (l <= 0))
	{
		cout << endl;
		cin.clear();
		cin.ignore((numeric_limits<streamsize>::max)(), '\n');
		cout << "Некоректные данные, попробуйте снова" << endl;
	}

	cord[3] = cord[1] + l; cord[2] = cord[0];
	cord[4] = cord[0] + l; cord[5] = cord[3];
	cord[6] = cord[0] + l; cord[7] = cord[1];

	return 0;
}

int quadrate::Show()
{
	cout << "Квадрат № " << n << endl << endl;

	cout << "(x;y) " << endl;

	for (int i = 1; i < 8; i++)
	{
		cout << cord[i - 1] << ";" << cord[i] << endl;
		i++;
	}


	cout << "Длина стороны = " << l << endl;

	return 0;
}

int quadrate::Verification()
{

	if (((cord[0] + cord[1]) != (cord[2] + cord[3])) || ((cord[2] + cord[3]) != (cord[4] + cord[5])) || ((cord[4] + cord[5]) != (cord[6] + cord[7])) || ((cord[6] + cord[7]) != (cord[0] + cord[1])))
	{
		cout << "Квадрат существует. ";
		return 0;
	}
	else
	{
		cout << "Квадрат не существует. " << endl;
		return 1;
	}
}

int quadrate::MoveO(int n)
{
	if (Verification() == 1) return -1;
	if (n != this->n) return -2;

	system("cls");

	int e = 0;
	cout << "1. Переместить квадрат." << endl;
	cout << "2. Повернуть квадрат вокруг главной точки." << endl;
	cin >> e;
	switch (e)
	{
	case 1:
	{
		double x = 0, y = 0;
		cout << "Напишите на сколько x переместить фигуру:";
		x = check(x);
		cout << "Напишите на сколько y переместить фигуру:";
		y = check(y);

		for (int i = 1; i < 8; i++)
		{
			cord[i - 1] += x;
			cord[i] += y;
			i++;
		}

	}; break;
	case 2:
	{
		double alpha;
		double x, y;
		cout << "Напишите угол поворота квадрата: ";
		while (!(cin >> alpha) || (cin.peek() != '\n') || ((alpha <= 0) && (alpha >= 180)))
		{
			cout << endl;
			cin.clear();
			cin.ignore((numeric_limits<streamsize>::max)(), '\n');
			cout << "Некоректные данные, попробуйте снова" << endl;
		}

		alpha = alpha * 3.14159 / 180;

		for (int i = 1; i < 8; i++)
		{
			x = cord[i - 1] * cos(alpha) - cord[i] * sin(alpha);
			y = cord[i - 1] * sin(alpha) + cord[i] * cos(alpha);
			cord[i - 1] = x; cord[i] = y; i++;
		}
	}; break;
	default:
		break;
	}

	return 0;
}

double quadrate::Square(int n)
{
	if (Verification() == 1) return -1;
	//if (n != this->n) return -2;
	system("cls");

	return pow(l, 2);
}

int quadrate::Delete()
{
	n = 0;
	for (int i = 0; i < 8; i++)  cord[i] = 0;
	return 0;
}
quadrate::~quadrate()
{
}