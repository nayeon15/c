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
	// TODO: ���⿡ ���� �ڵ� �߰�.
}


int CMyStringEx::SetString(const char* pszParam)
{
	// TODO: ���⿡ ���� �ڵ� �߰�.
	const char* str = "�۸��� �Ƶ�";
	if (!strncmp(pszParam, str, 6)) {
		CMyString::SetString("���� ���");
	}
	else {
		CMyString::SetString(pszParam);
	}
	return 0;
}


void CMyStringEx::OnSetString(char* pszData, int nLength)
{
	if (strcmp(pszData, "�۸��̾Ƶ�") == 0)
	{
		strcpy(pszData, "*���ѾƵ�*");
	}
	// TODO: ���⿡ ���� �ڵ� �߰�.
}
