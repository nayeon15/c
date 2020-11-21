#pragma once
class CMyString {
public:
	CMyString();
	// 복사 생성자
	CMyString(const CMyString& rhs);
	CMyString& operator=(const CMyString& rhs);
	~CMyString();
private:
	// 문자열을 저장하기 위해 동적 할당한 메모리를 가리키는 포인터
	char* m_pszData;
	// 저장된 문자열의 길이
	int m_nLength;
public:
	int SetString(const char* pszParam);
	const char* GetString() const;
	void Release();
	// 변환 생성자
	explicit CMyString(const char* pszParam);
	operator char* () const {
		return	m_pszData;
	}
	// 이동생성자
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