#pragma once
#include "Figure.h"
class quadrate :
	public Figure
{
private:

	double cord[8]; int l = 0; int n = 0;

public:
	quadrate(int, double*, int);
	quadrate();
	template<typename T> T check(T);
	int Create() override;
	int Delete() override;
	int Show() override;
	int Verification() override;
	int MoveO(int) override;
	double Square(int) override;
	~quadrate();
};

