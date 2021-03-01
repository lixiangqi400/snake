#pragma once
#include"unit.h"
#include<vector>
using namespace std;
class food:public unit
{	
public:
		food(int x=2,int y=2,char pic = '$');
		virtual ~food();
		void createpos();
};

