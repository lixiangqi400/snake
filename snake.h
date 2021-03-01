#include"unit.h"
#include<iostream>
#include<vector>
#include<conio.h>
#include"food.h"
typedef enum 
{
	KUP,
	KDOWN,
	KLEFT,
	KRIGHT
}Dir;

class snake
{
public:
	snake(int x = 40, int y = 15, char pic = '*', int len = 4,int speed=300,Dir dir=KUP);
	virtual~snake();
	void move(food *f);
	void showsnake();
	void erasesnake();
	int keyboard();
	bool eatfood(food *food);
	void growup();
	void die();
public:
	int m_headx;
	int m_heady;
	int m_len;
	int m_speed;
	int m_score;
	int m_level=1;
	int m_pic;
	int m_dir;
	vector<unit> m_body;
};