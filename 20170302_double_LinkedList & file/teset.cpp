// teset.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "Node.h"

int main()
{
	Node* head = new Node;
	Node* tail = nullptr;
	ifstream fOpen("data.txt");

	char test[256];
	char* token;
	char* token2;
	char* del = ":";

	while (!fOpen.eof())
	{
		token = nullptr;
		fOpen.getline(test, sizeof(test));

		token = strtok_s(test, del, &token2);

		if (!strcmp(token, "i"))
		{
			//fOpen.getline(test, sizeof(test));
			int data = atoi(token2);

			if (head->getData() == 0)
			{
				head->setData(data);
				tail = head;
			}
			else
			{
				head->insert(data, tail);
			}

			continue;
		}
		else if (!strcmp(token, "r"))
		{
			if (tail == nullptr) continue;
			tail->reversePrint();
			//head->reverse(head, tail);
			continue;
		}
		else if (!strcmp(token, "p"))
		{
			head->print();
			continue;
		}
		else if (!strcmp(token, "d"))
		{
			//fOpen.getline(test, sizeof(test));
			int data = atoi(token2);

			head->remove(data, head, tail);
			continue;
		}
	}
	

//
//	head = new Node;
//	head->setData(1);
//	tail = head;
//
//	head->insert(2, tail);
//	head->insert(3, tail);
//	head->insert(4, tail);
//	head->insert(5, tail);
//
//	head->print();
//	cout << "reversePrint" << endl;
//	tail->reversePrint();
//
////	cout << head->getData() << endl;
////	cout << tail->getData() << endl;
//
//	head->remove(2, head, tail);
//	head->remove(3, head, tail);
//
////	cout << head->getData() << endl;
////	cout << tail->getData() << endl;
//
//	head->print();
//	cout << "reversePrint" << endl;
//	tail->reversePrint();
//    
//	head->insert(6, 4, tail);
//
////	cout << head->getData() << endl;
////	cout << tail->getData() << endl;
//
//	head->print();
//	cout << "reversePrint" << endl;
//	tail->reversePrint();
//
//	head->remove(6, head, tail);
//
//	head->print();
//	cout << "reversePrint" << endl;
//	tail->reversePrint();
//	head->remove(1, head, tail);
//	
//	head->print();
//	cout << "reversePrint" << endl;
//	tail->reversePrint();
//	
////	tail->reversePrint();
//	
	return 0;
}

