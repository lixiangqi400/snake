#include "control.h"
#include<iostream>
using namespace std;


control::control()
{
	HANDLE hOut;
	CONSOLE_SCREEN_BUFFER_INFO scr;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE); /* ��ȡ��׼������ */
	GetConsoleScreenBufferInfo(hOut, &scr);
	m_coor.X = scr.srWindow.Right;
	m_coor.Y = scr.srWindow.Bottom;
}


control::~control()
{
}

void control::drawGameArea()//��Ĵ�С��(2,2)-(80,33)
{
	unit::gotoxy(unit::KLEFT, unit::KUP);//(2,2)
	for (int j = 0; j <= unit::KWIDTH; j++)//2-82=80������
	{
		cout << "-";
	}

	for (int i = 0; i < unit::KHEIGHT; i++)//����
	{
		unit::gotoxy(unit::KLEFT, unit::KUP + 1 + i);//2-32=30�������䣩
		cout << "|";
		unit::gotoxy(unit::KLEFT + unit::KWIDTH - 1, unit::KUP + 1 + i);//2-32=30�������䣩��������̶�Ϊ81
		cout << "|";
	}

	unit::gotoxy(unit::KLEFT, unit::KUP + unit::KHEIGHT + 1);//��2��33����������һ��
	for (int k = 0; k < unit::KWIDTH; k++)
	{
		cout << "-";
	}

	unit::gotoxy(unit::KLEFT + 1, unit::KUP + 2);//��3.5��
	for (int i = 0; i < unit::KWIDTH - 2; i++)
	{
		cout << "-";
	}
}

void control::drawGameInfo()
{
	unit::gotoxy(unit::KLEFT + 1, unit::KUP + 1);//(3,3)

	cout << "��Ϸ���ƣ�̰����";

	unit::gotoxy(unit::KLEFT + 20, unit::KUP + 1);//(22,3)

	cout << "��д�ߣ�������";

	unit::gotoxy(unit::KLEFT + 40, unit::KUP + 1);//(42,3)

	cout << "��ǰ�÷�: 0";

	//unit::gotoxy(unit::KLEFT + unit::KSCORE_OFFSET, unit::KUP + 1);

	//cout << m_iScore;

	unit::gotoxy(unit::KLEFT + 60, unit::KUP + 1);//(62,3)

	cout << "��ǰ�ؿ�: 1";

	//unit::gotoxy(unit::KLEFT + unit::KLEVEL_OFFSET, KUP + 1);

	//cout << m_iLevel;

}


