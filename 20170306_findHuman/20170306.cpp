// 20170306.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "findHuman.h"

int main()
{
	findHuman* human = new findHuman;	

	human->init();
	human->humanFind();
	human->print();

	delete human;

	return 0;
}