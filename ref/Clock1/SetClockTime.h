#if !defined(AFX_SETCLOCKTIME_H__25DEF315_9818_4916_B37A_16836F0BF5F8__INCLUDED_)
#define AFX_SETCLOCKTIME_H__25DEF315_9818_4916_B37A_16836F0BF5F8__INCLUDED_

#include "ClockDlg.h"	// Added by ClassView
#include "MyMedia.h"	// Added by ClassView
 
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SetClockTime.h : header file
//
 

/////////////////////////////////////////////////////////////////////////////
// CSetClockTime dialog

 class CSetClockTime : public CDialog
{
// Construction
public:
 	CObArray m_obarray;
	CMyMedia m_media;
	CString m_GetCurrentDirectory;
	void InitComboBox();
	CSetClockTime(CWnd* pParent = NULL);   // standard constructor
	
 // 	CMediaClass m_MediaClass;
//	CObArray m_obarray;
// Dialog Data
	//{{AFX_DATA(CSetClockTime)
	enum { IDD = IDD_DIALOG1 };
	int		m_i;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSetClockTime)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSetClockTime)
	afx_msg void OnButAddtime();
	afx_msg void OnButFind();
	afx_msg void OnButTrylisten();
	afx_msg void OnButStopmusic();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SETCLOCKTIME_H__25DEF315_9818_4916_B37A_16836F0BF5F8__INCLUDED_)
