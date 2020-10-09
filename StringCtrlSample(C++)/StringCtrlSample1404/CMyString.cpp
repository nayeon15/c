#include "CMyString.h"
#include <string.h>
#pragma warning(disable:4996)

CMyString::CMyString()
	:m_pszData(nullptr)
	, m_nLength(0)
{
}

CMyString::CMyString(const CMyString& rhs)
{
	m_nLength = rhs.m_nLength;
	m_pszData = new char[rhs.m_nLength + 1];
	strcpy(m_pszData, rhs.m_pszData);
}

CMyString& CMyString::operator=(const CMyString& rhs)
{
	m_nLength = rhs.m_nLength;
	strcpy(m_pszData, rhs.m_pszData);

	return *this;
}

CMyString::~CMyString()
{
	Release();
}



int CMyString::SetString(const char* pszParam)
{
	// TODO: 여기에 구현 코드 추가.
	m_nLength = strlen(pszParam);
	if (pszParam == nullptr || m_nLength <= 0)
	{
		return 0;
	}
	if (m_pszData != nullptr)
	{
		Release();
	}
	m_pszData = new char[m_nLength + 1];
	strcpy(m_pszData, pszParam);

	return 0;
}


const char* CMyString::GetString() const
{
	// TODO: 여기에 구현 코드 추가.
	if (m_nLength == 0)
		return "";
	return m_pszData;
}



void CMyString::Release()
{
	if (m_pszData != NULL)
		delete[] m_pszData;
	m_pszData = nullptr;
	// TODO: 여기에 구현 코드 추가.
}
