// SetOffCmpTime.cpp : implementation file
//

#include "stdafx.h"
#include "Clock.h"
#include "SetOffCmpTime.h"
 

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSetOffCmpTime dialog


CSetOffCmpTime::CSetOffCmpTime(CWnd* pParent /*=NULL*/)
	: CDialog(CSetOffCmpTime::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSetOffCmpTime)
	m_state = -1;
	//}}AFX_DATA_INIT
}


void CSetOffCmpTime::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSetOffCmpTime)
	DDX_Radio(pDX, IDC_RADIO_ONE, m_state);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSetOffCmpTime, CDialog)
	//{{AFX_MSG_MAP(CSetOffCmpTime)
	ON_BN_CLICKED(IDC_BUT_ADD_OFFTIME, OnButAddOfftime)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSetOffCmpTime message handlers

void CSetOffCmpTime::OnButAddOfftime() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	CString m_hour,m_tellword,m_state,m_stringint,str;
	
//	m_media.OnMediaClose ();
	((CComboBox*)GetDlgItem(IDC_COM_SEL_HOUR))->GetWindowText (m_hour);
	((CComboBox*)GetDlgItem(IDC_COM_SEL_MINUTE))->GetWindowText (m_tellword);
	m_hour=m_hour+":"+m_tellword;
	((CComboBox*)GetDlgItem(IDC_COM_SEL_SECOND))->GetWindowText (m_tellword);
	m_hour=m_hour+":"+m_tellword;

	((CEdit*)GetDlgItem(IDC_EDIT_TELL_WORD))->GetWindowText (m_tellword);

	m_stringint.Format("%d",m_state);
	str="关机消息";
	::WritePrivateProfileString(str,"offcom",m_hour,".\\message3.ini"); 
	::WritePrivateProfileString(str,"tellword",m_tellword,".\\message3.ini");
	::WritePrivateProfileString(str,"offdata",m_stringint,".\\message3.ini");
	::WritePrivateProfileString(str,"state","Y",".\\message3.ini");

 	AfxGetMainWnd()->SendMessage(WM_COMMAND,MAKEWPARAM(IDC_BUT_UPDATA_COM,0),0); //像主对话框的一个按钮发送一个消息
 	SendMessage(WM_CLOSE);
}

void CSetOffCmpTime::InitDlg()
{
	CString str;
	for(int i=0;i<60;i++)
	{
		if(i<10)
			str.Format ("0%d",i);
		else
			str.Format ("%d",i);
		if(i<24)
			((CComboBox*)GetDlgItem(IDC_COM_SEL_HOUR))->AddString(str); 
		((CComboBox*)GetDlgItem(IDC_COM_SEL_MINUTE))->AddString (str);
		((CComboBox*)GetDlgItem(IDC_COM_SEL_SECOND))->AddString (str);
	}
}

BOOL CSetOffCmpTime::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	InitDlg();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

 
