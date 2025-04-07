#include "stdafx.h"
#include "findHuman.h"


void findHuman::init(void)
{
	//start에 시작 시간을 넣는다.
	start = GetTickCount();
	//파일 열기
	fin.open("마을2.txt");
	//잘 열렸는지 확인
	if (fin.is_open()) cout << "열림" << endl;
	else
	{
		cout << "파일 열기 오류" << endl;
		exit(0);
	}

	//인구수 읽기
	fin.getline(sample, sizeof(sample));
	//총 갯수 저장
	total = atoi(sample);
	//파일을 처음부터 끝까지 저장. -> 벡터에
	while (!fin.eof())
	{
		//sample에 한 줄을 읽어온다.
		fin.getline(sample, sizeof(sample));
		//strtok_s를 통해 deli단위로 자른다. 그럼 인덱스값이 나옴
		token1 = strtok_s(sample, deli, &next_token);
		//인덱스값을 임시 구조체 인덱스에 넣는다.
		temp.index = atoi(token1);
		//다음 값을 잘라서 가져온다 -> 자신이 알고 있는 사람 숫자
		token1 = strtok_s(nullptr, deli, &next_token);
		temp.count = atoi(token1);
		//남은 문자열은 문자열 복사를 통해 복사한다.
		strcpy_s(temp.str, next_token);
		//list에 넣기
		list.push_back(temp);
	}

	//첫번째 놈은 확인을 했기에 true를 입력
	list[0].isCheck = true;

	//test벡터에 첫번째 놈을 입력
	test.push_back(list[0]);
}

void findHuman::humanFind(void)
{
	int tempIndex;																	// 임시 변수 인덱스를 저장하는 역할
	char tempStr[1024];																// 구조체의 문자열을 임시로 저장하는 역할 여기에 넣지 않고 돌리게 되면 터짐 이유는 잘 모름 ㅋ
	for (int i = 0; i < test.size(); i++)											//벡터의 사이즈 만큼 돌아라
	{
		// i번째 벡터의 문자열을 복사 - 시작은 0번
		strcpy_s(tempStr, test[i].str);
		//문자열은 이미 사람이다. 왜냐하면 처음에 벡터에 들어간 놈은 무조건 사람이고 이놈이 가리키고 있는 놈들은 무조건 사람이기 때문 - 조건1
		token1 = strtok_s(tempStr, deli, &next_token);
		//간단한 예외 처리
		if (token1 == nullptr) continue;
		//잘라낸 토큰을 int형으로 변경
		tempIndex = atoi(token1);
		//이 인덱스를 통해 전체를 담은 벡터에서 찾아서 isCheck를 검사 - 이놈이 추가 되었는가를 확인한다.
		if (!list[tempIndex - 1].isCheck)
		{
			//추가 안되어 있어서 추가 한다면 아래의 과정을 실행
			list[tempIndex - 1].isCheck = true;
			test.push_back(list[tempIndex - 1]);
		}

		//이하 동일한 작업 실행 ii가 1부터 시작하는 이유는 위에서 1번 실행을 했기 때문이다.
		for (int ii = 1; ii < test[i].count; ii++)
		{
			//strtok때문에 위에서 실행 후 for문을 통해 다시 실행하는 것이다.첫번째에 null을 줌 - 이미 위에서 문자열을 저장했기 때문에 다시 넣을 필요 없다. 
			token1 = strtok_s(nullptr, deli, &next_token);
			//예외 처리
			if (token1 == nullptr) break;
			//상동
			tempIndex = atoi(token1);
			if (!list[tempIndex - 1].isCheck)
			{
				list[tempIndex - 1].isCheck = true;
				test.push_back(list[tempIndex - 1]);
			}
		}
	}

	//열었던 파일 닫기 - 시간을 많이 잡아먹는다. 약 0.01초 정도
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
//사용 안함
bool findHuman::checkOverlap(int index)
{
	for (int i = 0; i < test.size(); i++)
	{
		if (index == test[i].index) return false;
	}

	return true;
}

//생성과 동시에 이니셜라이저를 통해 멤버 변수를 초기화한다. nullptr을 c++11에서 표준화 된 것으로 NULL과 같은 역할을 한다고 보면 된다.
findHuman::findHuman()
	:total(0), inputCount(0), deli(" "), token1(nullptr), next_token(nullptr)
{
}


findHuman::~findHuman()
{
}
