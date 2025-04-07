#pragma once
class Node
{
public:
	Node();
	~Node();

	void insert(int a);
	void insert(int data, int PrevData);
	void remove(int num, Node*& head);
	void print(void);
	int& getData(void) { return data; }
	void setData(int temp) { data = temp; }
	void setNext(Node* temp) { next = temp; }
	Node* getNext(void) { return next; }

private:
	int data;
	Node* next;
};

