#pragma once
#include"Pos.h"
#include<ctime>

class Food
{
public:
	Food(int xmin,int xmax,int ymin,int ymax);
	Pos out(void);
private:
	int Xmax;
	int Xmin;
	int Ymax;
	int Ymin;
};