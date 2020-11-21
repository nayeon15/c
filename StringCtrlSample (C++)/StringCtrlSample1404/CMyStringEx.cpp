#define _CRT_SECURE_NO_WARNINGS
#include "CMyStringEx.h"
#include <string.h>


CMyStringEx::CMyStringEx(const char* pszParam)
{
	CMyString::SetString(pszParam);
}

int CMyStringEx::Find(const char* pszParam)
{
	const char* ptr = CMyString::GetString();

	if (strstr(ptr, pszParam) - ptr > 0) {
		return strstr(ptr, pszParam) - ptr;
	}
	else return -1;
	// TODO: 여기에 구현 코드 추가.
}


int CMyStringEx::SetString(const char* pszParam)
{
	// TODO: 여기에 구현 코드 추가.
	const char* str = "멍멍이 아들";
	if (!strncmp(pszParam, str, 6)) {
		CMyString::SetString("좋은 사람");
	}
	else {
		CMyString::SetString(pszParam);
	}
	return 0;
}


void CMyStringEx::OnSetString(char* pszData, int nLength)
{
	if (strcmp(pszData, "멍멍이아들") == 0)
	{
		strcpy(pszData, "*착한아들*");
	}
	// TODO: 여기에 구현 코드 추가.
}
