#include	<iostream>
#include	"CMyString.h"
#include "CMyStringEx.h"
using	namespace	std;
int	main()
{
	CMyStringEx strTest;

	strTest.SetString("멍멍이아들");
	cout << strTest << endl;

	strTest.SetString("학번 : 1404, 이름 : 박나연");
	cout << strTest << endl;

	return 0;
}