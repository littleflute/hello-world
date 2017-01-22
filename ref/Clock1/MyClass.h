// MyClass.h: interface for the CMyClass class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYCLASS_H__D2D76248_1634_4B7E_B367_95A6C87D6423__INCLUDED_)
#define AFX_MYCLASS_H__D2D76248_1634_4B7E_B367_95A6C87D6423__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMyClass:public CObject //(1)  
{
 	DECLARE_SERIAL(CMyClass)//(2)
public:
	CMyClass();
 	CMyClass(CString m_hour,CString m_musicroute,CString m_tellword,int m_i,CString m_dataselect); //(4)
	virtual ~CMyClass();
	void Serialize(CArchive &archive);//(3)
	
	CString m_hour;
	CString m_musicroute;
	CString m_tellword;
	int m_i;
	CString m_dataselect;
};

#endif // !defined(AFX_MYCLASS_H__D2D76248_1634_4B7E_B367_95A6C87D6423__INCLUDED_)
