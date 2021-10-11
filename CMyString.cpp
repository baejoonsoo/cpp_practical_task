#pragma warning(disable:4996) // visual studio 에서 필요

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