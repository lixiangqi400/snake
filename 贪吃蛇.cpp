// 贪吃蛇坐标.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "unit.h"
#include"food.h"
#include"snake.h"
#include"control.h"
#include<mmsystem.h>
#include<windows.h>
#pragma comment(lib,"winmm.lib")



void HideCursor()			//隐藏光标
{
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
int main()
{	
	PlaySound(TEXT("G:\\c++\\贪吃蛇背景音乐.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	unit t;
	HideCursor();
	food f;
	control c;
	c.drawGameArea();
	c.drawGameInfo();
	f.createpos();
	f.show();
	snake s;
	while (true)
	{
		s.move(&f);
	}	
	/*s.move();*/
	t.gotoxy(2,34);
}

