#include "stdafx.h"
#include "vec.h"


vec::vec()
	:top(nullptr), size(0)
{
}


vec::~vec()
{
}

bool vec::empty(void)
{
	if (size == 0) return true;
	else return false;
}

void vec::push(int a)
{
	top = new Node(a);

	if (nullptr == list)
	{
		list = top;
	}
	else list->push(top);
}

void vec::pop(void)
{
	Node* temp = top->getPrev();
	delete top;
	top = temp;
	top->setNext(nullptr);
}

void vec::print(void)
{
	list->print();
}
