#pragma once
#include<windows.h>
#include<iostream>
using namespace std;
class unit
{
public:
	unit(int x = 10, int y = 5, char pic = '*');
	~unit();
	void show();
	void erase();
	static void gotoxy(int x, int y);
public:
	const static int KLEFT = 2;
	const static int KUP = 2;
	const static int KWIDTH = 80;//界面的宽度
	const static int KHEIGHT = 30;//界面的长度
	int m_iX;
	int m_iY;
	char m_cPic;
};

