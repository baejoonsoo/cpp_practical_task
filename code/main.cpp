#include <iostream>
#include "CMyString.h"
using namespace std;

void TestFunc(const CMyString& strParam)
{
	cout<< strParam<< endl;
}

int main()
{
	CMyString strData("홍길동");
	::TestFunc(strData);
	::TestFunc(CMyString("김철수"));
	return 0;
}