#pragma once
#include<deque>
#include"Pos.h"
using namespace std;
/*
�ߵĳ�ʼ����Ϊ 5��
�ߵĻ��������С�Ͳ��������������ⲿ�Ĳ���
Ҳ���ǵ�λ 1�������λ���ƶ������Ƶ�ʱ���ȡ�ⲿ����


*/
enum Dir
{
	S =0,X,Y,_X,_Y
};

class Snack
{

public:
	Dir headDir;//���ƶ��ķ���
	Pos head();
	int snackLen;//�ߵĽ���
	deque<Pos>SnackPoint;
	Snack();
	~Snack();
	bool move();
	int grow(Pos p);
private:


};
