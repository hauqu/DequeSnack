#pragma once
#include "Snack.h"
#include"Pos.h"
Pos Snack::head()
{
	return Pos(SnackPoint.front());
}
Snack::Snack()
{

	headDir = S;//静止
	
	for (int i = 0; i < 5; i++)
	{
		SnackPoint.push_front(Pos(0, i));
	}snackLen = 5;
	/*
	-------------------------------
						头43210尾
	-------------------------------
		头
		*
		*
		*
		*	
		*
		尾   默认方向为Y轴正方向
	*/

}

Snack::~Snack()
{
	SnackPoint.clear();
	snackLen = 0;
}

bool Snack::move()
{
	Pos p = SnackPoint.front();
	switch (headDir)//计算新头的位置
	{
	case X:
		p.x++; break;
	case Y:
		p.y++; break;
	case _X:
		p.x--; break;
	case _Y:
		p.y--; break;
	default:
		break;
	}
	for ( deque<Pos>::iterator i = SnackPoint.begin();i < SnackPoint.end();i++)
	{
		Pos p2 = *i;
		if (p2.x==p.x)
			if (p2.y ==p.y)
			return false;
		//新头的位置等于某个身体的位置，死了
	}
	SnackPoint.pop_back();
	SnackPoint.push_front(p);
	return true;
}

int Snack::grow(Pos p)
{
	SnackPoint.push_front(p);
	snackLen++;
	return snackLen;
}
