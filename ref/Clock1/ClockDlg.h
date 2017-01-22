// ClockDlg.h : header file
//


#if !defined(AFX_CLOCKDLG_H__86AF554B_0CCB_4AF4_959C_36829F755EA7__INCLUDED_)
#define AFX_CLOCKDLG_H__86AF554B_0CCB_4AF4_959C_36829F755EA7__INCLUDED_
#include "SetClockTime.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
 
/////////////////////////////////////////////////////////////////////////////
// CClockDlg dialog
 
class CClockDlg : public CDialog
{
// Construction
public:
	void ShutDown();
	void OffComTime();
	void TheClockIsCom();
	void GetListString();
	CString m_GetCurrentDirectory;
	void InitList();
	void WhickSongShouldHave();
	CString m_savecurrenttime;
	void CharToCString(char *a,int n,CString str);
	CClockDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CClockDlg)
	enum { IDD = IDD_CLOCK_DIALOG };
	CListCtrl	m_showoffcom;
	CListCtrl	m_showclock;
	CString	m_showtime;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClockDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	virtual LRESULT DefWindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CClockDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButSetClocktime();
	afx_msg void OnButOpenTelltime();
	afx_msg void OnButOffComputer();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnButDeleteitem();
	afx_msg void OnButUpdata();
	afx_msg void OnButUpdataCom();
	afx_msg void OnButDelItem();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLOCKDLG_H__86AF554B_0CCB_4AF4_959C_36829F755EA7__INCLUDED_)
