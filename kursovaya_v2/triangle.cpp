#include "triangle.h"
#include <iostream>


using namespace std;

triangle::triangle(double* cord, int n)
{
	this->n = n;

	for (size_t i = 0; i < 6; i++)	this->cord[i] = cord[i];

}

triangle::triangle()
{}

template<typename T>
T triangle::check(T a)
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

int triangle::Create()
{
	system("cls");

	n++;
	cout << "Треугольник №" << n << endl;

	cout << "Напишите 1-ую координату x у треугольника: ";
	cord[0] = check(cord[0]);

	cout << "Напишите 1-ую координату y у треугольника: ";
	cord[1] = check(cord[1]);

	cout << "Напишите 2-ую координату x у треугольника: ";
	cord[2] = check(cord[2]);

	cout << "Напишите 2-ую координату y у треугольника : ";
	cord[3] = check(cord[3]);

	cout << "Напишите 3-ую координату x у треугольника: ";
	cord[4] = check(cord[4]);

	cout << "Напишите 3-ую координату y у треугольника : ";
	cord[5] = check(cord[5]);

	if (Verification() == 0)
	{
		return 0;
	}
	else
	{
		n--;
		return 1;
	}

}

int triangle::Show()
{
	cout << "Треугольник № " << n << endl << endl;

	cout << "(x;y) " << endl;
	for (int i = 1; i < 6; i++)
	{
		cout << cord[i - 1] << ";" << cord[i] << endl;
		i++;
	}

	return 0;
}

int triangle::Verification()
{
	double a, b, c;
	a = sqrt(pow(cord[2] - cord[0], 2) + pow(cord[3] - cord[1], 2));
	b = sqrt(pow(cord[4] - cord[2], 2) + pow(cord[5] - cord[3], 2));
	c = sqrt(pow(cord[0] - cord[4], 2) + pow(cord[1] - cord[5], 2));

	if ((a + b > c) && (a + c > b) && (b + c > a))
	{
		cout << "Треугольник существует." << endl; return 0;
	}
	else
	{
		cout << "Треугольник не существует." << endl; return 1;
	}
}

int triangle::MoveO(int n) //фикс 
{
	if (Verification() == 1) return -1;
	if (n != this->n) return -2;

	system("cls");

	int e = 0;
	cout << "1. Переместить треугольник." << endl;
	cout << "2. Повернуть треугольник вокруг главной точки." << endl;
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

		for (int i = 1; i < 6; i++)
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
		cout << "Напишите угол поворота треугольника: ";
		while (!(cin >> alpha) || (cin.peek() != '\n') || ((alpha <= 0) && (alpha >= 180)))
		{
			cout << endl;
			cin.clear();
			cin.ignore((numeric_limits<streamsize>::max)(), '\n');
			cout << "Некоректные данные, попробуйте снова" << endl;
		}

		alpha = alpha * 3.14159 / 180;

		for (int i = 1; i < 6; i++)
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

int triangle::Delete()
{
	for (int i = 0; i < 6; i++)  cord[i] = 0;
	return 0;
}

double triangle::Square(int n)
{
	if (Verification() == 1) return -1;
	if (n != this->n) return -2;
	system("cls");

	return 0.5 * ((cord[0] - cord[4]) * (cord[3] - cord[5]) - (cord[2] - cord[4]) * (cord[1] - cord[5]));
}

triangle::~triangle()
{

}