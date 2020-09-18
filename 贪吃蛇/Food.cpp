#pragma once
#include "Food.h"
#include<stdlib.h>

Food::Food(int xmin, int xmax, int ymin, int ymax)
{
	srand(time(NULL));
	Xmax = xmax;
	Xmin = xmin;
	Ymax = ymax;
	Ymin = ymin;
}

Pos Food::out(void)
{
	
	Pos p(0,0);
	p.x = Xmin + rand() % Xmax;
	p.y = Ymin + rand() % Ymax;
	return p;
}
