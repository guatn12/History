#pragma once

struct typeHuman
{
	int index;
	int count;
	char str[1024];
	bool isCheck;
};

class findHuman
{
public:
	void init(void);
	void humanFind(void);
	void print(void);
	

	findHuman();
	~findHuman();
private:
	vector<typeHuman> test;		// ���� ����� ����Ǵ� ����
	vector<typeHuman> list;		// ó�� ������ ��� �о ���Ϳ� ����
	int total;					// �� ��� �ο��� �����ϴ� ����
	int inputCount;				// ?????
	typeHuman temp;				// �ӽ� ����ü ���� ??? ������ ��

	ifstream fin;				// ������ ���� ���� ����ϴ� ifstream - �ڼ��� ������ ���ۿ� c++ ���� ������� �˻��Ͽ� �ڼ��� ������ Ȯ�� �� ����
	char sample[256];			// ���ڿ��� �б� ���� ���Ǵ� ����
	char* deli;					// ��ū - ���ڿ����� ���ڸ� �ڸ��� ���� ���Ǵ� ����
	char *token1;				// �߶� ���� 
	char *next_token;			// �߶� ���� ���� ���� ����
	int start;					// ���� �ð�
	int end;					// ���� �ð�
	float time;					// �ɸ� �ð�

private:
	//������ ������ false / ������ true (��� ����)
	bool checkOverlap(int index);
};

