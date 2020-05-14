#pragma once
#include "quadrate.h"
#include "triangle.h"
#include <vector>

using namespace std;

class Menu
{
private:
	vector<quadrate> quadrates;
	vector<triangle> triangles;
public:

	Menu();
	int menu();
	int interaction(quadrate, int, int);
	int interaction(triangle, int, int);
	~Menu();
};

