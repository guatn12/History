#include "stdafx.h"
#include "Node.h"


Node::Node()
	:data(0), next(nullptr)
{
}


Node::~Node()
{
}

void Node::insert(int a)
{
	Node* sample = this;
	while (true)
	{
		if (sample->getNext() == nullptr)
		{
			Node* test = new Node;
			test->setData(a);
			sample->setNext(test);
			break;
		}
		else sample = sample->getNext();
	}
}

void Node::insert(int data, int PrevData)
{
	Node* sample = this;
	while (true)
	{
		if (sample->getData() == PrevData)
		{
			Node* test = new Node;
			test->setData(data);
			test->setNext(sample->getNext());
			sample->setNext(test);
			break;
		}
		else sample = sample->getNext();
	}
}

void Node::remove(int data, Node*& head)
{
	Node* First = this;
	Node* second = this;
	Node** hTemp = &head;

	if ((*hTemp)->getData() == data)
	{
		*hTemp = this->getNext();
		delete this;
		return;
	}

	while (true)
	{
		if (second->getData() == data)
		{
			First->setNext(second->getNext());
			delete second;
			break;
		}
		else
		{
			First = second;
			second = second->getNext();
		}
	}
}

void Node::print(void)
{
	Node* sample = this;

	while (true)
	{
		if (sample->getNext() != nullptr)
		{
			cout << " " << sample->getData();
			cout << " " << "->";
			sample = sample->getNext();
		}
		else
		{
			cout << " " << sample->getData() << endl;
			break;
		}
	}
	
}
