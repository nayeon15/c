//거기서 프로그램 실행이 시작되고 종료됨
#include "CMyString.h"
#include <iostream>
#include <string.h>
using namespace std;
#pragma warning(disable:4996)

CMyString::CMyString()
	:m_pszData(nullptr)
	, m_nLength(0) {
}

CMyString::CMyString(const	char* pszParam)
	: m_pszData(nullptr)
	, m_nLength(0) {
	SetString(pszParam);
}

CMyString::CMyString(CMyString&& rhs)
	: m_pszData(nullptr)
	, m_nLength(0) {
	cout << "CMyString 이동생성자 호출" << endl;

	// 얕은 복사를 수행해도 상관없다. 어차피 원본이 곧 소멸됨
	m_pszData = rhs.m_pszData;
	m_nLength = rhs.m_nLength;

	// 원본 임시 객체의 멤버들은 초기화 한다. 절대로 해제하면 안된다
	rhs.m_pszData = nullptr;
	rhs.m_nLength = 0;
}

CMyString::CMyString(const CMyString& rhs) {
	m_nLength = rhs.m_nLength;
	m_pszData = new char[m_nLength + 1];
	strcpy(m_pszData, rhs.m_pszData);
}

CMyString& CMyString::operator=(const CMyString& rhs) {
	m_nLength = rhs.m_nLength;
	if (m_pszData != NULL) {
		delete[] m_pszData;
	}
	m_pszData = new char[m_nLength + 1];
	strcpy(m_pszData, rhs.m_pszData);
	return *this;
}

CMyString::~CMyString() {
	Release();
}


int CMyString::SetString(const char* pszParam) {
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

	OnSetString(m_pszData, m_nLength);

	return 0;
}

const char* CMyString::GetString() const {
	if (m_nLength == 0)
		return "";
	return m_pszData;
}

void CMyString::Release() {
	if (m_pszData != nullptr)
		delete[] m_pszData;
	m_pszData = nullptr;
}

int CMyString::GetLength() const {
	return m_nLength;
}

int CMyString::Append(const char* pszParam) { //this객체 m_pszData에 pszParam 문자열을 합치는 함수
	//매개변수 유효성 검사
	if (pszParam == NULL)
		return 0;

	int nLenParam = strlen(pszParam);
	if (nLenParam == 0)
		return 0;

	//세트된 문자열이 없다면 새로 문자열을 할당한 것과 동일하게 처리함
	if (m_pszData == NULL) {
		SetString(pszParam);
		return m_nLength;
	}

	//현재 문자열의 길이 백업
	int nLenCur = m_nLength;

	//두 문자열을 합쳐서 저장할 수 있는 메모리를 새로 할당함
	char* pszResult = new char[nLenCur + nLenParam + 1];

	//문자열 조합
	strcpy(pszResult, m_pszData);
	strcpy(pszResult + (sizeof(char) * nLenCur), pszParam);

	//기존 문자열 삭제 및 멤버 정보 갱신
	Release();

	m_pszData = pszResult;
	m_nLength = nLenCur + nLenParam;

	return m_nLength;
}

CMyString CMyString::operator+(const CMyString& rhs) {
	CMyString temp;
	temp.SetString(m_pszData);
	temp.Append(rhs);
	return temp;
}
CMyString& CMyString::operator+=(const CMyString& rhs) {
	Append(rhs);
	return *this;
}

void CMyString::OnSetString(char* pszData, int nLength)
{
	// TODO: 여기에 구현 코드 추가.
}
