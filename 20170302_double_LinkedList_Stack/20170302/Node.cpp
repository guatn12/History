#include "stdafx.h"
#include "Node.h"


Node::Node()
	:data(0), next(nullptr), prev(nullptr)
{
}

Node::Node(int data, Node * next, Node * prev)
	:data(data), next(next), prev(prev)
{
}


Node::~Node()
{
}

void Node::push(Node* temp)
{
	if (nullptr == next)
	{
		temp->setPrev(this);
		next = temp;
	}
	else
	{
		next->push(temp);
	}
}
//
//
//Node* Node::pop(void)
//{
//	Node* sample = this->getPrev();
//	delete this;
//	return sample;
//}
//
void Node::print(void)
{
	if (nullptr == this->next)
	{
		cout << data << endl;
	}
	else
	{
		cout << data << " ";
		next->print();
	}
}
