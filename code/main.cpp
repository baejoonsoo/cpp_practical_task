#include <iostream>
#include "CMyString.h"  // CMyString 클래스 사용을 위해 헤더파일 추가
using namespace std;

void TestFunc(const CMyString& param)
{
    cout << param.GetString() << endl;
}

int main()
{
    CMyString strData, strTest;
	strData.SetString("Hello");
	strTest.SetString("World");

	// 복사 생성
	CMyString strNewData(strData);
	cout << strNewData.GetString() << endl;

	// 단순 대입 연산자 호출
	strNewData = strTest;
	cout << strNewData.GetString() << endl;
	return 0;
}