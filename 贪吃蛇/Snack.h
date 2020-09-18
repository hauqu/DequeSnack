#pragma once
#include<deque>
#include"Pos.h"
using namespace std;
/*
蛇的初始长度为 5；
蛇的绘制例如大小和步长尽量不依赖外部的参数
也即是单位 1进行相对位置移动，绘制的时候获取外部参数


*/
enum Dir
{
	S =0,X,Y,_X,_Y
};

class Snack
{

public:
	Dir headDir;//蛇移动的方向
	Pos head();
	int snackLen;//蛇的节数
	deque<Pos>SnackPoint;
	Snack();
	~Snack();
	bool move();
	int grow(Pos p);
private:


};
