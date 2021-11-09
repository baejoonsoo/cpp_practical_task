#ifndef __HEAD__
#define __HEAD__

class CMyString 
{
public:  // 생성자, 소멸자 / 연산자
	CMyString();
	~CMyString();
	CMyString(const CMyString& rhs);			// 복사 생성자
	CMyString(CMyString&& rhs); // 이동 생성자
	explicit CMyString(const char* str);	// 변환 생성자

	CMyString& operator=(const CMyString& rhs);	// 대입 연산자
	CMyString& operator=(CMyString&& rhs);
	CMyString operator+(const CMyString& rhs);
	CMyString& operator+=(const CMyString& rhs);

	
	operator char*() const;
private:
	// 문자열을 저장하기 위해 동적 할당한 메모리를 가리키는 포인터
	char* m_pszData;
	// 저장된 문자열의 길이
	int m_nLength;
public:  // my method
	int SetString(const char* pszParam);
	const char* GetString() const;
	void Release();
	int GetLength() const;
	int Append(const char* pszParam);
};

#endif
