// SetClockTime.cpp : implementation file
//

#include "stdafx.h"
#include "Clock.h"
#include "SetClockTime.h"
 
#include "MyMedia.h"  
 
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSetClockTime dialog
 

CSetClockTime::CSetClockTime(CWnd* pParent /*=NULL*/)
	: CDialog(CSetClockTime::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSetClockTime)
	m_i = -1;
	//}}AFX_DATA_INIT
	m_GetCurrentDirectory="";
}


void CSetClockTime::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSetClockTime)
	DDX_Radio(pDX, IDC_RADIO_ONE, m_i);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSetClockTime, CDialog)
	//{{AFX_MSG_MAP(CSetClockTime)
	ON_BN_CLICKED(IDC_BUT_ADDTIME, OnButAddtime)
	ON_BN_CLICKED(IDC_BUT_FIND, OnButFind)
	ON_BN_CLICKED(IDC_BUT_TRYLISTEN, OnButTrylisten)
	ON_BN_CLICKED(IDC_BUT_STOPMUSIC, OnButStopmusic)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSetClockTime message handlers

void CSetClockTime::OnButAddtime() 
{
	UpdateData(true);
	CString m_hour,m_musicroute,m_tellword,m_dataselect,m_stringint,str,m_state;
	
	m_media.OnMediaClose ();
	((CComboBox*)GetDlgItem(IDC_COM_SEL_HOUR))->GetWindowText (m_hour);
	((CComboBox*)GetDlgItem(IDC_COM_SEL_MINUTE))->GetWindowText (m_tellword);
	m_hour=m_hour+":"+m_tellword;
 	((CComboBox*)GetDlgItem(IDC_COM_SEL_MUSIC))->GetWindowText (m_musicroute);
	((CEdit*)GetDlgItem(IDC_EDIT_TELLWORD))->GetWindowText (m_tellword);
	((CEdit*)GetDlgItem(IDC_COM_SEL_DATA))->GetWindowText (m_dataselect);

	m_stringint.Format("%d",m_i);
	str="这是第0个闹钟的信息";
	::WritePrivateProfileString(str,"clockhour",m_hour,".\\message.ini"); 
 	::WritePrivateProfileString(str,"musicroute",m_musicroute,".\\message.ini");
	::WritePrivateProfileString(str,"tellword",m_tellword,".\\message.ini");
	::WritePrivateProfileString(str,"musicnum",m_stringint,".\\message.ini");
	::WritePrivateProfileString(str,"dataselect",m_dataselect,".\\message.ini");
	::WritePrivateProfileString(str,"state","Y",".\\message.ini");

 	AfxGetMainWnd()->SendMessage(WM_COMMAND,MAKEWPARAM(IDC_BUT_UPDATA,0),0); //像主对话框的一个按钮发送一个消息
 	SendMessage(WM_CLOSE);
}

void CSetClockTime::OnButFind() 
{
 	CString str;
  
  	CFileDialog dlg(true,NULL,NULL,OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
  					"WAV(*.wav)|*.wav| MP3(*.mp3)|*.mp3||");//Open wave file
 	if(dlg.DoModal ()==IDOK)
	{
  		str=dlg.GetPathName ();//得到选择的WAV文件
  		UpdateData (false);//更新空间显示
	}
	
	((CComboBox*)GetDlgItem(IDC_COM_SEL_MUSIC))->AddString(str);
	((CComboBox*)GetDlgItem(IDC_COM_SEL_MUSIC))->SetCurSel(((CComboBox*)GetDlgItem(IDC_COM_SEL_MUSIC))->FindStringExact(-1,str));	
}

void CSetClockTime::OnButTrylisten() 
{
	CString m_musicname;
  
  	((CComboBox*)GetDlgItem(IDC_COM_SEL_MUSIC))->GetWindowText (m_musicname);
  	if(m_musicname.IsEmpty ())
	{
  		MessageBox("请选择需要播放的音频文件");
  		return;
	}
	m_media.OnMediaPlay (m_musicname);
}

void CSetClockTime::OnButStopmusic() 
{
	m_media.OnMediaClose ();
}

void CSetClockTime::InitComboBox()
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
	}
	((CComboBox*)GetDlgItem(IDC_COM_SEL_DATA))->AddString ("周");
	((CComboBox*)GetDlgItem(IDC_COM_SEL_DATA))->AddString ("月");
	((CComboBox*)GetDlgItem(IDC_COM_SEL_DATA))->AddString ("日");
}

BOOL CSetClockTime::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	InitComboBox();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
