// GdiPlusDemoView.cpp : implementation of the CGdiPlusDemoView class
//

#include "stdafx.h"
#include "GdiPlusDemo.h"

#include "GdiPlusDemoDoc.h"
#include "GdiPlusDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGdiPlusDemoView

IMPLEMENT_DYNCREATE(CGdiPlusDemoView, CView)

BEGIN_MESSAGE_MAP(CGdiPlusDemoView, CView)
	//{{AFX_MSG_MAP(CGdiPlusDemoView)
	ON_COMMAND(ID_GDIPLUS_DEMO, OnGdiplusDemo)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGdiPlusDemoView construction/destruction

CGdiPlusDemoView::CGdiPlusDemoView()
{
	// TODO: add construction code here

}

CGdiPlusDemoView::~CGdiPlusDemoView()
{
}

BOOL CGdiPlusDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CGdiPlusDemoView drawing
typedef GdiPlusColor Color;
BOOL g_OnDraw=0;
void CGdiPlusDemoView::OnDraw(CDC* pDC)
{
	CGdiPlusDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	if (g_OnDraw)
		return;

	g_OnDraw=1;
 
	Graphics gc(pDC->m_hDC);
	Pen pen(Color::Red, 2);
	gc.DrawArc(&pen, 10, 10, 300, 200, 0, 360);
 

	g_OnDraw=0;
}

/////////////////////////////////////////////////////////////////////////////
// CGdiPlusDemoView printing

BOOL CGdiPlusDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CGdiPlusDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CGdiPlusDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CGdiPlusDemoView diagnostics

#ifdef _DEBUG
void CGdiPlusDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CGdiPlusDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGdiPlusDemoDoc* CGdiPlusDemoView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGdiPlusDemoDoc)));
	return (CGdiPlusDemoDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CGdiPlusDemoView message handlers
#include "DlgDemo.h"
void CGdiPlusDemoView::OnGdiplusDemo() 
{
	// TODO: Add your command handler code here
	
	CDlgDemo dlg;
	if (IDOK==dlg.DoModal())
	{
		Invalidate();
	}
	
}
