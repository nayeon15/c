// StringCtrlSample1404.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "CMyString.h"
using namespace std;

int main()
{
	CMyString	strData, strTest;
	strData.SetString("Hello");
	strTest.SetString("World");
	
	CMyString	strNewData(strData);
	cout << strNewData.GetString() << endl;
	
	strNewData = strTest;
	cout << strNewData.GetString() << endl;
	return	0;

}

