// GdiPlusDemoDoc.cpp : implementation of the CGdiPlusDemoDoc class
//

#include "stdafx.h"
#include "GdiPlusDemo.h"

#include "GdiPlusDemoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGdiPlusDemoDoc

IMPLEMENT_DYNCREATE(CGdiPlusDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CGdiPlusDemoDoc, CDocument)
	//{{AFX_MSG_MAP(CGdiPlusDemoDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGdiPlusDemoDoc construction/destruction

CGdiPlusDemoDoc::CGdiPlusDemoDoc()
{
	// TODO: add one-time construction code here

}

CGdiPlusDemoDoc::~CGdiPlusDemoDoc()
{
}

BOOL CGdiPlusDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CGdiPlusDemoDoc serialization

void CGdiPlusDemoDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CGdiPlusDemoDoc diagnostics

#ifdef _DEBUG
void CGdiPlusDemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CGdiPlusDemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CGdiPlusDemoDoc commands
