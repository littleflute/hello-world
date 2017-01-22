// DlgDemo.cpp : implementation file
//

#include "stdafx.h"
#include "GdiPlusDemo.h"
#include "DlgDemo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgDemo dialog


CDlgDemo::CDlgDemo(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgDemo::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgDemo)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDlgDemo::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgDemo)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgDemo, CDialog)
	//{{AFX_MSG_MAP(CDlgDemo)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgDemo message handlers

void CDlgDemo::OnButton1() 
{
	// TODO: Add your control notification handler code here
	
}
