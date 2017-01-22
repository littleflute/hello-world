// GdiPlusDemo.h : main header file for the GDIPLUSDEMO application
//

#if !defined(AFX_GDIPLUSDEMO_H__C6F33EBC_D447_4E50_B998_CEB404FA6BA1__INCLUDED_)
#define AFX_GDIPLUSDEMO_H__C6F33EBC_D447_4E50_B998_CEB404FA6BA1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols


#ifndef ULONG_PTR
#define ULONG_PTR unsigned long*
#endif

#include  "include/gdiplus.h"
using namespace Gdiplus;

#pragma comment(lib, "Lib//gdiplus.lib")

/////////////////////////////////////////////////////////////////////////////
// CGdiPlusDemoApp:
// See GdiPlusDemo.cpp for the implementation of this class
//

class CGdiPlusDemoApp : public CWinApp
{
public:
	CGdiPlusDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGdiPlusDemoApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CGdiPlusDemoApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GDIPLUSDEMO_H__C6F33EBC_D447_4E50_B998_CEB404FA6BA1__INCLUDED_)
