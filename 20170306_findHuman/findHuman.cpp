#include "stdafx.h"
#include "findHuman.h"


void findHuman::init(void)
{
	//start�� ���� �ð��� �ִ´�.
	start = GetTickCount();
	//���� ����
	fin.open("����2.txt");
	//�� ���ȴ��� Ȯ��
	if (fin.is_open()) cout << "����" << endl;
	else
	{
		cout << "���� ���� ����" << endl;
		exit(0);
	}

	//�α��� �б�
	fin.getline(sample, sizeof(sample));
	//�� ���� ����
	total = atoi(sample);
	//������ ó������ ������ ����. -> ���Ϳ�
	while (!fin.eof())
	{
		//sample�� �� ���� �о�´�.
		fin.getline(sample, sizeof(sample));
		//strtok_s�� ���� deli������ �ڸ���. �׷� �ε������� ����
		token1 = strtok_s(sample, deli, &next_token);
		//�ε������� �ӽ� ����ü �ε����� �ִ´�.
		temp.index = atoi(token1);
		//���� ���� �߶� �����´� -> �ڽ��� �˰� �ִ� ��� ����
		token1 = strtok_s(nullptr, deli, &next_token);
		temp.count = atoi(token1);
		//���� ���ڿ��� ���ڿ� ���縦 ���� �����Ѵ�.
		strcpy_s(temp.str, next_token);
		//list�� �ֱ�
		list.push_back(temp);
	}

	//ù��° ���� Ȯ���� �߱⿡ true�� �Է�
	list[0].isCheck = true;

	//test���Ϳ� ù��° ���� �Է�
	test.push_back(list[0]);
}

void findHuman::humanFind(void)
{
	int tempIndex;																	// �ӽ� ���� �ε����� �����ϴ� ����
	char tempStr[1024];																// ����ü�� ���ڿ��� �ӽ÷� �����ϴ� ���� ���⿡ ���� �ʰ� ������ �Ǹ� ���� ������ �� �� ��
	for (int i = 0; i < test.size(); i++)											//������ ������ ��ŭ ���ƶ�
	{
		// i��° ������ ���ڿ��� ���� - ������ 0��
		strcpy_s(tempStr, test[i].str);
		//���ڿ��� �̹� ����̴�. �ֳ��ϸ� ó���� ���Ϳ� �� ���� ������ ����̰� �̳��� ����Ű�� �ִ� ����� ������ ����̱� ���� - ����1
		token1 = strtok_s(tempStr, deli, &next_token);
		//������ ���� ó��
		if (token1 == nullptr) continue;
		//�߶� ��ū�� int������ ����
		tempIndex = atoi(token1);
		//�� �ε����� ���� ��ü�� ���� ���Ϳ��� ã�Ƽ� isCheck�� �˻� - �̳��� �߰� �Ǿ��°��� Ȯ���Ѵ�.
		if (!list[tempIndex - 1].isCheck)
		{
			//�߰� �ȵǾ� �־ �߰� �Ѵٸ� �Ʒ��� ������ ����
			list[tempIndex - 1].isCheck = true;
			test.push_back(list[tempIndex - 1]);
		}

		//���� ������ �۾� ���� ii�� 1���� �����ϴ� ������ ������ 1�� ������ �߱� �����̴�.
		for (int ii = 1; ii < test[i].count; ii++)
		{
			//strtok������ ������ ���� �� for���� ���� �ٽ� �����ϴ� ���̴�.ù��°�� null�� �� - �̹� ������ ���ڿ��� �����߱� ������ �ٽ� ���� �ʿ� ����. 
			token1 = strtok_s(nullptr, deli, &next_token);
			//���� ó��
			if (token1 == nullptr) break;
			//��
			tempIndex = atoi(token1);
			if (!list[tempIndex - 1].isCheck)
			{
				list[tempIndex - 1].isCheck = true;
				test.push_back(list[tempIndex - 1]);
			}
		}
	}

	//������ ���� �ݱ� - �ð��� ���� ��ƸԴ´�. �� 0.01�� ����
	fin.close();
}

void findHuman::print(void)
{
	end = GetTickCount();

	time = (float)(end - start) / 1000;

	cout << test.size() << endl;

	cout << time << endl;

	cout << endl;
}
//��� ����
bool findHuman::checkOverlap(int index)
{
	for (int i = 0; i < test.size(); i++)
	{
		if (index == test[i].index) return false;
	}

	return true;
}

//������ ���ÿ� �̴ϼȶ������� ���� ��� ������ �ʱ�ȭ�Ѵ�. nullptr�� c++11���� ǥ��ȭ �� ������ NULL�� ���� ������ �Ѵٰ� ���� �ȴ�.
findHuman::findHuman()
	:total(0), inputCount(0), deli(" "), token1(nullptr), next_token(nullptr)
{
}


findHuman::~findHuman()
{
}
