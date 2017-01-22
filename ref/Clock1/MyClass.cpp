// MyClass.cpp: implementation of the CMyClass class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Clock.h"
#include "MyClass.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

IMPLEMENT_SERIAL(CMyClass,CObject,1)//(5)

CMyClass::CMyClass()
{

}

CMyClass::CMyClass(CString m_hour,CString m_musicroute,CString m_tellword,int m_i,CString m_dataselect)
{
	this->m_hour=m_hour;
	this->m_musicroute=m_musicroute;
	this->m_tellword=m_tellword;
	this->m_i=m_i;
	this->m_dataselect=m_dataselect;
}

CMyClass::~CMyClass()
{

}

void CMyClass::Serialize(CArchive &ar) 
{
	CObject::Serialize(ar);
	if(ar.IsStoring())
		ar<<m_hour<<m_musicroute<<m_tellword<<m_i<<m_dataselect;
	else
		ar>>m_hour>>m_musicroute>>m_tellword>>m_i>>m_dataselect;
}
