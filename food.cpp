#include "food.h"
#include<iostream>
#include <cstdlib> // srand() �������������
#include<time.h>//time() �������������



food::food(int x, int y, char pic)
{
	m_iX = x;
	m_iY = y;
	m_cPic = pic;
}
food::~food()
{
}
void food::createpos()
{
	srand((int)time(0));
	m_iX = KLEFT + 3 + rand() % (KWIDTH - 3);//KWIDTH = 80
	m_iY = KUP + 3 + rand() % (KHEIGHT - 3);//KHEIGHT = 30
}
 
