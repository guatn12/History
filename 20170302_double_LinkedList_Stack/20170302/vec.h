#pragma once
#include "Node.h"
class vec
{
public:
	vec();
	~vec();

	bool empty(void);
	const int32_t& Size(void) { return size; }

	void push(int a);
	void pop(void);
	void print(void);
private:
	Node* list;
	Node* top;
	int32_t size;
};

