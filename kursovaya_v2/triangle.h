#pragma once
#include "Figure.h"
class triangle :
	public Figure
{
private:

	double cord[6]; int n = 0;

public:
	triangle(double*, int);
	triangle();
	int Create() override;
	template<typename T> T check(T);
	int Delete() override;
	int Show() override;
	int Verification() override;
	int MoveO(int) override;
	double Square(int) override;
	~triangle();

};

