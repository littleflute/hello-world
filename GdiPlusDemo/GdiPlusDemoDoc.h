// GdiPlusDemoDoc.h : interface of the CGdiPlusDemoDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_GDIPLUSDEMODOC_H__F129C59E_914C_42D3_AA28_CCDD1F3E9066__INCLUDED_)
#define AFX_GDIPLUSDEMODOC_H__F129C59E_914C_42D3_AA28_CCDD1F3E9066__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CGdiPlusDemoDoc : public CDocument
{
protected: // create from serialization only
	CGdiPlusDemoDoc();
	DECLARE_DYNCREATE(CGdiPlusDemoDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGdiPlusDemoDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CGdiPlusDemoDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CGdiPlusDemoDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GDIPLUSDEMODOC_H__F129C59E_914C_42D3_AA28_CCDD1F3E9066__INCLUDED_)
