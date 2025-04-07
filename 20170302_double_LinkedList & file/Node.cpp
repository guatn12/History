#include "stdafx.h"
#include "Node.h"


Node::Node()
	:data(0), next(nullptr), prev(nullptr)
{
}


Node::~Node()
{
}

void Node::insert(int a, Node*& tail)
{
	Node* sample = this;
	Node* prevSample;
	//�� �������� �ִ� ���
	while (true)
	{
		if (sample->getNext() == nullptr)
		{
			Node* test = new Node;
			test->setData(a);
			test->setPrev(sample);

			sample->setNext(test);
			tail = test;
			break;
		}
		else sample = sample->getNext();
	}
}

void Node::insert(int data, int PrevData, Node*& tail)
{
	Node* sample = this;
	//prevData�� ���� ���ϴ� ���� ã�Ƽ� �� �ڿ� �����͸� �Է��ϴ� ���
	while (true)
	{
		if (sample->getData() == PrevData)
		{
			Node* test = new Node;
			test->setData(data);
			test->setNext(sample->getNext());
			test->setPrev(sample);
			sample->getNext()->setPrev(test);
			sample->setNext(test);

			if (test->getNext() == nullptr) tail = test;

			break;
		}
		else sample = sample->getNext();
	}
}

void Node::remove(int data, Node*& head, Node*& tail)
{
	Node* First = this;
	Node* second = this;
	Node** hTemp = &head;

	//����ó��
	if (tail == nullptr || head->getData() == 0) return;

	//�� ó���� ���� �� ���
	if ((*hTemp)->getData() == data)
	{
		if (this->getNext() == nullptr)
		{
			tail = nullptr;
			delete this;
			head = new Node;
			return;
		}

		*hTemp = this->getNext();
		(*hTemp)->setPrev(nullptr);
		delete this;
		return;
	}

	//�� �������� ���� �� ���
	if (tail->getData() == data)
	{
		Node* sample = tail;
		tail = sample->getPrev();
		tail->setNext(nullptr);
		delete sample;
		return;
	}

	//�Ϲ� ����
	while (second != tail)
	{
		if (second->getData() == data)
		{
			second->getNext()->setPrev(First);
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

	//����ó��
	if (sample->getData() == 0)
	{
		return;
	}

	while (true)
	{
		if (sample->getNext() != nullptr)
		{
			cout << sample->getData();
			cout << " " << "->" << " ";
			sample = sample->getNext();
		}
		else
		{
			cout << sample->getData() << endl;
			break;
		}
	}
}

void Node::reversePrint()
{
	Node* sampleNode = this;

	while (true)
	{
		if (sampleNode->getPrev() != nullptr)
		{
			cout << sampleNode->getData();
			cout << " " << "->" << " ";
			sampleNode = sampleNode->getPrev();
		}
		else
		{
			cout << sampleNode->getData() << endl;
			break;
		}
	}
}

void Node::reverse(Node *& head, Node *& tail)
{
	Node* First = head;
	Node* Last = tail;
	Node* temp;

	while (true)
	{
		temp = head;
		head = tail;
		tail = temp;

		head = head->getNext();
		tail = tail->getPrev();

		if (head->getData() == tail->getData() || head->getNext()->getData() == tail->getData()) break;
	}
}
