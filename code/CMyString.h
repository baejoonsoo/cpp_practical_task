#ifndef __HEAD__
#define __HEAD__

class CMyString 
{
public: // 생성자, 소멸자 / 연산자
	CMyString();   // default 생성자
	~CMyString();
	CMyString(const CMyString& rhs);      // 복사 생성자
	CMyString(CMyString&& rhs);           // 이동 생성자
	explicit CMyString(const char* str);  // 변환 생성자

	CMyString& operator=(const CMyString& rhs); // 대입 연산자
	CMyString& operator=(CMyString&& rhs);      // 이동 대입 연산자
	CMyString operator+(const CMyString& rhs);  // 문자열 덧셈 연산자
	CMyString& operator+=(const CMyString& rhs);// 문자열 복합 덧셈 연산자

	operator char*() const;
private:
	// 문자열을 저장하기 위해 동적 할당한 메모리를 가리키는 포인터
	char* m_pszData;
	// 저장된 문자열의 길이
	int m_nLength;
public:  // my method
	int SetString(const char* pszParam); // 포인터를 포함한 객체를 만든다
	const char* GetString() const;       // 포인터가 가르키는 데이터를 return한다
	void Release();                      // 동적할당된 메모리를 해제한다
	int GetLength() const;               // 데이터의 길이를 return한다
	int Append(const char* pszParam);
};

#endif
