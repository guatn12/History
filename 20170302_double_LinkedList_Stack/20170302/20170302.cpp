// 20170302.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "vec.h"


int main()
{
	vec vector;

	vector.push(5);
	vector.push(4);
	vector.push(3);
	vector.push(2);
	vector.print();
	vector.pop();

	vector.print();

    return 0;
}

