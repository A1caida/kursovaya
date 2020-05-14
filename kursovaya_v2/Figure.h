#pragma once
class Figure
{
public:
	virtual int Create() = 0;
	virtual int Delete() = 0;
	virtual int Show() = 0;
	virtual int Verification() = 0;
	virtual int MoveO(int) = 0;
	virtual double Square(int) = 0;

};

