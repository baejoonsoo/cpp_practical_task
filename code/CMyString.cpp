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