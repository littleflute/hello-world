#if !defined(AFX_DLGDEMO_H__51E8B3D8_ABE4_45BF_9A21_7FED7A9B967A__INCLUDED_)
#define AFX_DLGDEMO_H__51E8B3D8_ABE4_45BF_9A21_7FED7A9B967A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgDemo.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgDemo dialog

class CDlgDemo : public CDialog
{
// Construction
public:
	CDlgDemo(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgDemo)
	enum { IDD = IDD_DIALOG1 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgDemo)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgDemo)
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGDEMO_H__51E8B3D8_ABE4_45BF_9A21_7FED7A9B967A__INCLUDED_)
