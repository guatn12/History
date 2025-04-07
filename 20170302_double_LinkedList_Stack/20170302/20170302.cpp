// 20170302.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
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

