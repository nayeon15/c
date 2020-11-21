#pragma once
class CMyString {
public:
	CMyString();
	// ���� ������
	CMyString(const CMyString& rhs);
	CMyString& operator=(const CMyString& rhs);
	~CMyString();
private:
	// ���ڿ��� �����ϱ� ���� ���� �Ҵ��� �޸𸮸� ����Ű�� ������
	char* m_pszData;
	// ����� ���ڿ��� ����
	int m_nLength;
public:
	int SetString(const char* pszParam);
	const char* GetString() const;
	void Release();
	// ��ȯ ������
	explicit CMyString(const char* pszParam);
	operator char* () const {
		return	m_pszData;
	}
	// �̵�������
	CMyString(CMyString&& rhs);

	int GetLength() const;
	int Append(const char* pszParam);

	CMyString operator+(const CMyString& rhs);
	CMyString& operator+=(const CMyString& rhs);



	virtual void OnSetString(char* pszData, int nLength);
};

class CMyDataArr {
private:
	int* m_pnArr;
public:
	CMyDataArr(int num) {
		m_pnArr = new int(num);
	}
	~CMyDataArr() {
		delete[]m_pnArr;
	}

};