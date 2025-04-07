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
	vector<typeHuman> test;		// 실제 사람이 저장되는 벡터
	vector<typeHuman> list;		// 처음 파일을 모두 읽어서 벡터에 저장
	int total;					// 총 사람 인원을 저장하는 변수
	int inputCount;				// ?????
	typeHuman temp;				// 임시 구조체 파일 ??? 사용안함 ㅋ

	ifstream fin;				// 파일을 열기 위해 사용하는 ifstream - 자세한 내용은 구글에 c++ 파일 입출력을 검색하여 자세한 내용을 확인 해 보자
	char sample[256];			// 문자열을 읽기 위해 사용되는 변수
	char* deli;					// 토큰 - 문자열에서 문자를 자르기 위해 사용되는 변수
	char *token1;				// 잘라낸 문자 
	char *next_token;			// 잘라낸 문자 빼고 남은 문자
	int start;					// 시작 시간
	int end;					// 끝난 시간
	float time;					// 걸린 시간

private:
	//같은게 있으면 false / 없으면 true (사용 안함)
	bool checkOverlap(int index);
};

