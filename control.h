#pragma once
#include <Windows.h>
#include"unit.h"
using namespace std;
class control:public unit
{
public:
	COORD m_coor;//��������
public:
	control();
	~control();
	void drawGameArea();
	void drawGameInfo();
};

