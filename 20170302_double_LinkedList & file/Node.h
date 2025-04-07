#pragma once
class Node
{
public:
	Node();
	~Node();

	void insert(int a, Node*& tail);
	void insert(int data, int PrevData, Node*& tail);
	void remove(int num, Node*& head, Node*& tail);
	void print(void);
	void reversePrint(void);
	void reverse(Node*& head, Node*& tail);

	int& getData(void) { return data; }
	void setData(int temp) { data = temp; }
	void setNext(Node* temp) { next = temp; }
	void setPrev(Node* temp) { prev = temp; }

	Node*& getNext(void) { return next; }
	Node*& getPrev(void) { return prev; }

private:
	int data;
	Node* next;
	Node* prev;
};