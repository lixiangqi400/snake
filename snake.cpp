#include "snake.h"
#include<iostream>
#include<Windows.h>
#include<conio.h>
#include"food.h"


snake::snake(int x , int y , char pic , int len,int speed,Dir dir)
{
	m_headx= x;
	m_heady= y;
	m_pic = pic;
	m_len = len;
	m_speed = speed;
	m_dir = dir;
	for (int i = 0; i < len; i++)
	{
		unit myunit(0, 0, pic);
		m_body.push_back(myunit);
		switch (m_dir)
		{
		case KUP:
			m_body[i].m_iX = m_headx;
			m_body[i].m_iY = m_heady+i;
		case KDOWN:
			m_body[i].m_iX = m_headx;
			m_body[i].m_iY = m_heady-i;
		case KLEFT:
			m_body[i].m_iX = m_headx +i;
			m_body[i].m_iY = m_heady;
		case KRIGHT:
			m_body[i].m_iX = m_headx-i;
			m_body[i].m_iY = m_heady;
		}
	}
}
snake::~snake()
{

}
int snake::keyboard()     //按键控制
{
	//char ch = 'd';
	//int direction =KRIGHT;  //前面宏定义RIGHT,UP等是int类型
	//vector<unit>:: iterator new_head;
	if (_kbhit())         //如果有按键
	{
		int keyvalue = _getch();       //把getch获取到的按键赋值给ch
		switch (keyvalue)
		{
		case 72:
			//direction = KUP;     //比如前面定义UP是4，这里把4赋值给direction
			if (m_dir == KLEFT || m_dir == KRIGHT)
			{
				m_dir = KUP;
			}
			break;
		case 80:
			if (m_dir == KLEFT || m_dir == KRIGHT)
			{
				m_dir = KDOWN;
			}
			break;
		case 75:
			if (m_dir == KUP || m_dir == KDOWN)
			{
				m_dir = KLEFT;
			}
			break;
		case 77:
			if (m_dir == KUP || m_dir == KDOWN)
			{
				m_dir = KRIGHT;
			}
			break;
		default:
			break;
		}
	}
	return m_dir;
}
void snake::move(food *f)
{
	for (int i = m_len - 1; i > 0; i--)
	{
		m_body[i].m_iX = m_body[i - 1].m_iX;
		m_body[i].m_iY = m_body[i - 1].m_iY;
	}
	m_dir = keyboard();
	switch (m_dir)
	{
		case KUP:
			m_body[0].m_iY--;
			break;
		case KDOWN:
			m_body[0].m_iY++;
			break;
		case KLEFT:
			m_body[0].m_iX--;
			break;
		case KRIGHT:
			m_body[0].m_iX++;
			break;
		default:
			break;
	}
	eatfood(f);
	showsnake();
	Sleep(m_speed);
	erasesnake();
	die();
}
void snake::showsnake()
{
	for (int i = 0; i < m_len; i++)
	{
		m_body[i].show();
	}
}
void snake::erasesnake()
{
	for (int i = 0; i < m_len; i++)
	{
		m_body[i].erase();
	}
}
bool snake::eatfood(food *foo)
{
	if (m_body[0].m_iX == foo->m_iX && m_body[0].m_iY == foo->m_iY)
	{
		growup();
		m_speed = m_speed-20;
		m_score++;
		foo->gotoxy(52, 3);
		cout << m_score;
		if(m_score % 5==0)
		m_level++;
		foo->gotoxy(72, 3);
		cout << m_level << endl;
		foo->createpos();
		foo->show();
	}
	else
		return false;
}
void snake::growup()
{
	unit myunit(0, 0, '*');
	m_body.push_back(myunit);
	m_len++;
}
void snake::die()
{
	if (m_body[0].m_iX == 2 || m_body[0].m_iX == 82|| m_body[0].m_iY == 4 || m_body[0].m_iY == 34)//撞墙
	{
		int ret = MessageBox(NULL, L"游戏结束", L"是否要重新开始", MB_YESNO);
		if (ret == IDYES)
		{ 
			cout << "请×掉控制台重新开始！" << endl;
		}
		else
		{
			MessageBox(NULL, L"游戏结束", L"游戏结束！", MB_OK);
		} 
		cin.get();
		/*system("cls");
		cout << "死亡！" << endl;*/
		/*Sleep(2000);*/
	}
	for (int i = 1; i < m_len; i++)//自残死
	{
		if (m_body[0].m_iX == m_body[i].m_iX && m_body[0].m_iY == m_body[i].m_iY)
		{

			//弹出一个界面游戏结束
			int ret = MessageBox(NULL, L"游戏结束", L"是否要重新开始", MB_YESNO);
			//MessageBox(NULL, L"游戏结束", L"游戏结束！", MB_YESNO);
			if (ret == IDYES)
			{
				cout << "请×掉控制台重新开始！" << endl;
			}
			else
			{
				MessageBox(NULL, L"游戏结束", L"游戏结束！", MB_OK);
			}
			cin.get();
		}
	}
}
