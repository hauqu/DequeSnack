/*
应用学到的数据结构知识来重新构建贪吃蛇游戏
*/
/*
1.常用操作，在头节点前插入一个节点，删去尾节点
根据onenoete的笔记演算，使用队列来完成操作

*/

#include"Snack.h"
#include<ctime>
#include<graphics.h>
#include<Windows.h>
#include"Food.h"
#include"Pos.h"
#include<conio.h>
const int WIN_L = 640;
const int WIN_H = 640;

void drawSnack(Snack &s,int size);
void drawFood(Pos p,int size);
Dir keyPro();

int main()
{
	initgraph(WIN_L, WIN_H);
	setorigin(WIN_L / 2, WIN_H / 2);
	setaspectratio(1, -1);
	Snack s;
	s.headDir = X;
	int foodNumber = 0;
	Food foodMake(-WIN_L/40,-WIN_H/40, WIN_L / 40, WIN_H / 40);
	Pos food(100, 100);
	while (true)
	{
		while (!_kbhit())
		{
			s.move();
			if (s.head().x==food.x)
			{
				if (s.head().y == food.y)
				{
					s.grow(food);
					foodNumber = 0;
				}
			}
			if (foodNumber==0)
			{
				food = foodMake.out();
				foodNumber = 1;
			}
			drawSnack(s, 10);
			drawFood(food, 10);
			Sleep(100);
			cleardevice();
		}
		s.headDir = keyPro();
	}
		
	
	_getch();
	closegraph();
	return 0;
}
void drawSnack(Snack& s,int size)
{

	line(0, WIN_H / 2, 0, -WIN_H / 2);
	line( WIN_L / 2,0,  -WIN_L / 2,0);
	for (deque<Pos>::iterator i = s.SnackPoint.begin(); i < s.SnackPoint.end(); i++)
	{
		Pos p = *i;
		fillcircle(p.x*size, p.y*size, size);
	}
	
}
void drawFood(Pos p, int size)
{
	setfillcolor(RED);
	fillcircle(p.x * size, p.y * size, size);
	setfillcolor(RGB(255, 255, 255));
}
Dir keyPro()
{
	switch (_getch())
	{
	case 72:
		return Y; break;
	case 77:
		return X; break;
	case 75:
		return _X; break;
	case 80:
		return _Y; break;
	default:
		break;
	}
	
}