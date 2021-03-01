#include "control.h"
#include<iostream>
using namespace std;


control::control()
{
	HANDLE hOut;
	CONSOLE_SCREEN_BUFFER_INFO scr;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE); /* 获取标准输出句柄 */
	GetConsoleScreenBufferInfo(hOut, &scr);
	m_coor.X = scr.srWindow.Right;
	m_coor.Y = scr.srWindow.Bottom;
}


control::~control()
{
}

void control::drawGameArea()//框的大小是(2,2)-(80,33)
{
	unit::gotoxy(unit::KLEFT, unit::KUP);//(2,2)
	for (int j = 0; j <= unit::KWIDTH; j++)//2-82=80闭区间
	{
		cout << "-";
	}

	for (int i = 0; i < unit::KHEIGHT; i++)//两列
	{
		unit::gotoxy(unit::KLEFT, unit::KUP + 1 + i);//2-32=30（开区间）
		cout << "|";
		unit::gotoxy(unit::KLEFT + unit::KWIDTH - 1, unit::KUP + 1 + i);//2-32=30（开区间），横坐标固定为81
		cout << "|";
	}

	unit::gotoxy(unit::KLEFT, unit::KUP + unit::KHEIGHT + 1);//（2，33）最下面那一根
	for (int k = 0; k < unit::KWIDTH; k++)
	{
		cout << "-";
	}

	unit::gotoxy(unit::KLEFT + 1, unit::KUP + 2);//（3.5）
	for (int i = 0; i < unit::KWIDTH - 2; i++)
	{
		cout << "-";
	}
}

void control::drawGameInfo()
{
	unit::gotoxy(unit::KLEFT + 1, unit::KUP + 1);//(3,3)

	cout << "游戏名称：贪吃蛇";

	unit::gotoxy(unit::KLEFT + 20, unit::KUP + 1);//(22,3)

	cout << "编写者：黎湘琪";

	unit::gotoxy(unit::KLEFT + 40, unit::KUP + 1);//(42,3)

	cout << "当前得分: 0";

	//unit::gotoxy(unit::KLEFT + unit::KSCORE_OFFSET, unit::KUP + 1);

	//cout << m_iScore;

	unit::gotoxy(unit::KLEFT + 60, unit::KUP + 1);//(62,3)

	cout << "当前关卡: 1";

	//unit::gotoxy(unit::KLEFT + unit::KLEVEL_OFFSET, KUP + 1);

	//cout << m_iLevel;

}


