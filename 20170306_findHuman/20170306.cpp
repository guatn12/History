// 20170306.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
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