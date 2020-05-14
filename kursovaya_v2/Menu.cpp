#include "Menu.h"
#include <iostream>
using namespace std;
Menu::Menu()
{}

int Menu::interaction(quadrate uwu, int n, int k)
{

	int kos = 1;
	auto owo = quadrates.begin();
	while (owo != quadrates.end())
	{

		if (n == 2)
		{
			cout << endl;
			owo->Show();
			owo++;
		}
		else if (n == 5)
		{
			owo->MoveO(k);
			owo++;

		}
		else if (n == 4)
		{
			cout << endl;
			owo->Verification();
			owo++;
		}
	}
	
	cout << endl;
	return 0;
}

int Menu::interaction(triangle uwu, int n, int k)
{
	int kos = 1;
	auto owo = triangles.begin();
	while (owo != triangles.end())
	{
		if (n == 2)
		{
			cout << endl;
			owo->Show();
			owo++;
		}
		else if (n == 5)
		{
			owo->MoveO(k);
			owo++;

		}
		else if (n == 4)
		{
			cout << endl;
			owo->Verification();
			owo++;
		}
	}

	cout << endl;
	return 0;
}

int Menu::menu()
{
	double* cordq = new double[8];
	for (int i = 0; i < 8; i++)  cordq[i] = 0;
	quadrate a(0, cordq, 0);
	triangle b(cordq, 0);
	delete[] cordq;
	int e;
	do {
		system("pause");
		system("cls");
		cout << "Введите номер выбора : " << endl;
		cout << "1)Создать фигуру.  " << endl;
		cout << "2)Вывести информацию о фигурах.  " << endl;
		cout << "3)Удалить последную фигуру.  " << endl;
		cout << "4)Переместить фигуру на плоскости.  " << endl;
		cout << "5)Посчитать площадь фигуры и сравнить их.  " << endl;
		cout << "6)Выйти из программы.  " << endl;
		while (!(cin >> e) || (cin.peek() != '\n'))
		{
			cin.clear();
			cin.ignore((numeric_limits<streamsize>::max)(), '\n');
			cout << "Введите цифру от 1 до 6: " << endl;
		}
		switch (e)
		{
		case 1:
		{
			int k = 0;
			cout << "1)Квадрат.  " << endl;
			cout << "2)Треугольник.  " << endl;
			cin >> k;
			if (k == 1)
			{
				if (a.Create() == 0)
				{
					quadrates.push_back(a);
				}
				else
				{
					cout << "Ошибка." << endl;
				}
			}
			else if (k == 2)
			{
				if (b.Create() == 0)
				{
					triangles.push_back(b);
				}
				else
				{
					cout << "Ошибка." << endl;
				}

			}
		};
		break;
		case 2:
		{

			if (quadrates.empty() == true)
			{
				cout << "Квадратов не существует." << endl;
			}
			else
			{
				interaction(a, 2, 0);
			}

			if (triangles.empty() == true)
			{
				cout << "Треугольников не существует." << endl;
			}
			else
			{
				interaction(b, 2, 0);
			}
		}; break;
		case 3:
		{

			int k = 0;
			cout << "1)Квадрат.  " << endl;
			cout << "2)Треугольник.  " << endl;
			cin >> k;
			if (k == 1)
			{
				if (quadrates.empty() == false)
				{
					quadrates.pop_back();
					a.Delete();
					if (quadrates.empty() == true)
					{
						a.Delete();
					}

				}
				else
				{
					cout << "Ошибка. Квадратов не существует." << endl;
				}
			}
			else if (k == 2)
			{
				if (triangles.empty() == false)
				{
					triangles.pop_back();
					b.Delete();

					if (triangles.empty() == true)
					{
						b.Delete();
					}
				}
				else
				{
					cout << "Ошибка. Треугольников не существует." << endl;
				}

			}
		}; break;
		case 4:
		{
			int k;
			cout << "1)Квадрат.  " << endl;
			cout << "2)Треугольник.  " << endl;
			cin >> k;
			if ((k == 1)&&(quadrates.empty() == false))
			{
				interaction(a, 2, 0);
				cout << "Введите номер фигуры.  " << endl;
				int owo; cin >> owo;
				interaction(a, 5, owo);

			}
			else if ((k == 2)&&(triangles.empty() == false))
			{
				interaction(b, 2, 0);
				cout << "Введите номер фигуры.  " << endl;
				int owo; cin >> owo;
				interaction(b, 5, owo);
			}
			else cout << "Ошибка." << endl;
		}; break;
		case 5:
		{
			if ((triangles.empty() == true) && (quadrates.empty() == true))
			{
				cout << "Ошибка." << endl;
			}
			else
			{
				
				system("cls");

				int k;
				double s1 = 0, s2 = 0;

				cout << "1)Квадрат.  " << endl;
				cout << "2)Треугольник.  " << endl;
				cin >> k;
				if ((k == 1) && (quadrates.empty() == false))
				{
					interaction(a, 2, 0);
					cout << "Введите номер фигуры.  " << endl;
					int owo; cin >> owo;
					s1 = quadrates[owo - 1].Square(owo);
				}
				else if ((k == 2) && (triangles.empty() == false))
				{
					interaction(b, 2, 0);
					cout << "Введите номер фигуры.  " << endl;
					int owo; cin >> owo;
					s1 = triangles[owo - 1].Square(owo);
				}

				system("cls");

				cout << "1)Квадрат.  " << endl;
				cout << "2)Треугольник.  " << endl;
				cin >> k;
				if ((k == 1) && (quadrates.empty() == false))
				{
					interaction(a, 2, 0);
					cout << "Введите номер фигуры.  " << endl;
					int owo; cin >> owo;
					s2 = quadrates[owo - 1].Square(owo);

				}
				else if ((k == 2) && (triangles.empty() == false))
				{
					interaction(b, 2, 0);
					cout << "Введите номер фигуры.  " << endl;
					int owo; cin >> owo;
					s2 = triangles[owo - 1].Square(owo);
				}
				if ((s1 == 0)||(s2 == 0))
				{
					cout << "Ошибка. Одна фигура не существует." << endl; break;
				}
				if (s1 > s2)
				{
					cout << s1 << " > " << s2 << endl;
					cout << "Площадь 1-ой фигуры больше площади 2-ой фигуры.  " << endl;
				}
				else if (s1 < s2)
				{
					cout << s1 << " < " << s2 << endl;
					cout << "Площадь 1-ой фигуры меньше площади 2-ой фигуры.  " << endl;
				}
				else
				{
					cout << s1 << " = " << s2 << endl;
					cout << "Площадь 1-ой фигуры равна площади 2-ой фигуры.  " << endl;
				}
			}
		} break;
		case 6:
		{	return 0;			}; break;
		default:cout << "Введите цифру от 1 до 6: " << endl;
			break;
		}


	} while (e != 6);
	return 0;


}

Menu::~Menu()
{


}