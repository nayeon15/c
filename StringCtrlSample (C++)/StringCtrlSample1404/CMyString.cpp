//�ű⼭ ���α׷� ������ ���۵ǰ� �����
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
	cout << "CMyString �̵������� ȣ��" << endl;

	// ���� ���縦 �����ص� �������. ������ ������ �� �Ҹ��
	m_pszData = rhs.m_pszData;
	m_nLength = rhs.m_nLength;

	// ���� �ӽ� ��ü�� ������� �ʱ�ȭ �Ѵ�. ����� �����ϸ� �ȵȴ�
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

int CMyString::Append(const char* pszParam) { //this��ü m_pszData�� pszParam ���ڿ��� ��ġ�� �Լ�
	//�Ű����� ��ȿ�� �˻�
	if (pszParam == NULL)
		return 0;

	int nLenParam = strlen(pszParam);
	if (nLenParam == 0)
		return 0;

	//��Ʈ�� ���ڿ��� ���ٸ� ���� ���ڿ��� �Ҵ��� �Ͱ� �����ϰ� ó����
	if (m_pszData == NULL) {
		SetString(pszParam);
		return m_nLength;
	}

	//���� ���ڿ��� ���� ���
	int nLenCur = m_nLength;

	//�� ���ڿ��� ���ļ� ������ �� �ִ� �޸𸮸� ���� �Ҵ���
	char* pszResult = new char[nLenCur + nLenParam + 1];

	//���ڿ� ����
	strcpy(pszResult, m_pszData);
	strcpy(pszResult + (sizeof(char) * nLenCur), pszParam);

	//���� ���ڿ� ���� �� ��� ���� ����
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
	// TODO: ���⿡ ���� �ڵ� �߰�.
}
