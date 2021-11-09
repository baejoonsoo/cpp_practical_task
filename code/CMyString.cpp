#include "CMyString.h"
#include <cstring>
#include <iostream>

using namespace std;

CMyString::CMyString(): m_nLength(0), m_pszData(nullptr) {}

CMyString::~CMyString() {
  this->Release();
}

int CMyString::SetString(const char* pszParam) {
  this->m_nLength=strlen(pszParam);
  this->m_pszData=new char[this->m_nLength+1];
  strcpy(this->m_pszData,pszParam);

  return 0;
}

CMyString& CMyString::operator=(const CMyString& rhs){
  if(m_pszData){
    delete[] m_pszData;
  }
  SetString(rhs.m_pszData);
  
  return *this;
}

CMyString::CMyString(const CMyString& rhs){
  SetString(rhs.m_pszData);
}


const char* CMyString::GetString() const{
  if(m_nLength==0){
    return "CMyString is Empty\n";
  }

  return this->m_pszData;
}

void CMyString::Release(){
  this->m_nLength=0;
  delete[] m_pszData;
  m_pszData=nullptr;
}

CMyString::CMyString(const char* str){
  SetString(str);
}

CMyString::operator char *() const{
  return m_pszData;
}

CMyString::CMyString(CMyString&& rhs){
  cout<<"CMyString 이동생성자 호출"<<endl;

  // 얕은 복사 실행
  this->m_nLength=rhs.m_nLength;
  this->m_pszData=rhs.m_pszData;

  // 원본 임시 객체를 초기화 // 해제X
  rhs.m_pszData=nullptr;
  rhs.m_nLength=0;
}

int CMyString::GetLength() const{
  return m_nLength;
}

int CMyString::Append(const char* pszParam){
  // 매개변수 유효성 검사
  if (pszParam == nullptr)
    return 0;

  // 현재 문자열의 길이 백업
  int nLenCur = m_nLength;

  // 매개변수 문자열 길이
  int nLenParam = strlen(pszParam);

  if(nLenParam == 0)
    return 0;

  // m_pszData 에 문자열이 없다면 새로 문자열을 할당한 것과 동일하게 처리함
  if (m_pszData == nullptr){
    SetString(pszParam);
	return m_nLength;
  }

  // 두 문자열을 합쳐서 저장할 수 있는 메모리를 새로 할당함
  char* pszResult = new char[nLenCur + nLenParam + 1];

  // 문자열 조합
  strcpy(pszResult, m_pszData);
  strcpy(pszResult + nLenCur, pszParam);

  // 기존 문자열 삭제 및 멤버 정보 갱신
  Release();

  m_pszData = pszResult;
  m_nLength = nLenCur + nLenParam;

  return m_nLength;
}

CMyString& CMyString::operator=(CMyString&& rhs){
  // 얕은 복사를 수행해도 상관 없다. 어차피 곧 원본이 소멸되기 때문
  this->m_nLength = rhs.m_nLength;
  this->m_pszData = rhs.m_pszData;

  // 원본 임시 객체의 멤버들은 초기화 한다. 절대로 해제하면 안된다.
  rhs.m_nLength = 0;
  rhs.m_pszData = nullptr;

  return *this;
}


CMyString CMyString::operator+(const CMyString& rhs){
  CMyString temp;
  temp.m_nLength=m_nLength+rhs.m_nLength;
  temp.m_pszData=new char[temp.m_nLength+1];

  strcpy(temp,m_pszData);
  strcpy(temp+m_nLength,rhs.m_pszData);

  return temp;
}

CMyString& CMyString::operator+=(const CMyString& rhs){
  Append(rhs);
  return *this;
}