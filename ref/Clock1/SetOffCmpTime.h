#if !defined(AFX_SETOFFCMPTIME_H__61D311C8_D2B6_4850_AC21_012B94D1A6AD__INCLUDED_)
#define AFX_SETOFFCMPTIME_H__61D311C8_D2B6_4850_AC21_012B94D1A6AD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SetOffCmpTime.h : header file
//

 

/////////////////////////////////////////////////////////////////////////////
// CSetOffCmpTime dialog

class CSetOffCmpTime : public CDialog
{
// Construction
public:
	void InitDlg();
	CSetOffCmpTime(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSetOffCmpTime)
	enum { IDD = IDD_DIALOG2 };
	int		m_state;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSetOffCmpTime)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSetOffCmpTime)
	afx_msg void OnButAddOfftime();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SETOFFCMPTIME_H__61D311C8_D2B6_4850_AC21_012B94D1A6AD__INCLUDED_)
