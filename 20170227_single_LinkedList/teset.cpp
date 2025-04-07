// teset.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "Node.h"

int main()
{
	Node* head;

	head = new Node;
	head->setData(1);

	head->insert(2);
	head->insert(3);
	head->insert(4);
	head->insert(5);

	head->print();

	head->remove(2, head);
	head->remove(3, head);

	head->print();
    
	head->insert(6, 4);

	head->print();

	head->remove(6, head);

	head->print();
	head->remove(1, head);
	head->print();
	return 0;
}

