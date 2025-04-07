#pragma once
class Node
{
public:
	Node();
	Node(int data, Node* next = nullptr, Node* prev = nullptr);
	~Node();

	void push(Node* temp);
	void print(void);

	int& getData(void) { return data; }
	void setData(const int& temp) { data = temp; }

	Node* getNext(void) { return next; }
	void setNext(Node* next) { this->next = next; }

	Node* getPrev(void) { return prev; }
	void setPrev(Node* prev) { this->prev = prev; }

private:
	int data;
	Node* next;
	Node* prev;
};

