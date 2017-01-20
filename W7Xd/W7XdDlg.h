// W7XdDlg.h : header file
//

#if !defined(AFX_W7XDDLG_H__649EA60F_47A7_4E13_B31C_74F785B46C3F__INCLUDED_)
#define AFX_W7XDDLG_H__649EA60F_47A7_4E13_B31C_74F785B46C3F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CW7XdDlg dialog

class CW7XdDlg : public CDialog
{
// Construction
public:
	CW7XdDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CW7XdDlg)
	enum { IDD = IDD_W7XD_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CW7XdDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CW7XdDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_W7XDDLG_H__649EA60F_47A7_4E13_B31C_74F785B46C3F__INCLUDED_)
