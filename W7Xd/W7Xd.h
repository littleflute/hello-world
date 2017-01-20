// W7Xd.h : main header file for the W7XD application
//

#if !defined(AFX_W7XD_H__ABC2929D_D136_4439_80E6_F8C2F1698EE2__INCLUDED_)
#define AFX_W7XD_H__ABC2929D_D136_4439_80E6_F8C2F1698EE2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CW7XdApp:
// See W7Xd.cpp for the implementation of this class
//

class CW7XdApp : public CWinApp
{
public:
	CW7XdApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CW7XdApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CW7XdApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_W7XD_H__ABC2929D_D136_4439_80E6_F8C2F1698EE2__INCLUDED_)
