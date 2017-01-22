// ClockDlg.cpp : implementation file
//


#include "stdafx.h"
#include "Clock.h"
#include "ClockDlg.h"
#include "SetOffCmpTime.h"
 
#include "SetClockTime.h" 
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About
 
class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CClockDlg dialog

CClockDlg::CClockDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CClockDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CClockDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);
	m_savecurrenttime="";
}

void CClockDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CClockDlg)
	DDX_Control(pDX, IDC_LIST_SHOWOFFCOM, m_showoffcom);
	DDX_Control(pDX, IDC_LIST_SHOWCLOCK, m_showclock);
	DDX_Text(pDX, IDC_SHOW_TIME, m_showtime);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CClockDlg, CDialog)
	//{{AFX_MSG_MAP(CClockDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUT_SET_CLOCKTIME, OnButSetClocktime)
	ON_BN_CLICKED(IDC_BUT_OPEN_TELLTIME, OnButOpenTelltime)
	ON_BN_CLICKED(IDC_BUT_OFF_COMPUTER, OnButOffComputer)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUT_DELETEITEM, OnButDeleteitem)
	ON_BN_CLICKED(IDC_BUT_UPDATA, OnButUpdata)
	ON_BN_CLICKED(IDC_BUT_UPDATA_COM, OnButUpdataCom)
	ON_BN_CLICKED(IDC_BUT_DEL_ITEM, OnButDelItem)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CClockDlg message handlers

BOOL CClockDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	SetTimer(1,1000,NULL);

	InitList();
// 	DeleteFile("message2.ini");
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CClockDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CClockDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CClockDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CClockDlg::OnButSetClocktime() //��������ʱ��
{
	// TODO: Add your control notification handler code here
	CSetClockTime dlg;
	dlg.DoModal ();
}

void CClockDlg::OnButOpenTelltime() //�������㱨ʱ
{
	// TODO: Add your control notification handler code here
	CString str;
	GetDlgItemText(IDC_BUT_OPEN_TELLTIME,str);

	if(str=="�������㱨ʱ")
	{
		SetTimer(2,1000,NULL);
		SetDlgItemText(IDC_BUT_OPEN_TELLTIME,"�ر����㱨ʱ");
	}
	else
	{
		KillTimer(2);
		SetDlgItemText(IDC_BUT_OPEN_TELLTIME,"�������㱨ʱ");
	}
}

void CClockDlg::OnButOffComputer() //���ùػ�ʱ��
{
	// TODO: Add your control notification handler code here
	CSetOffCmpTime dlg;
	dlg.DoModal ();
}

void CClockDlg::OnTimer(UINT nIDEvent) //��ʱ��
{
	// TODO: Add your message handler code here and/or call default
	if(nIDEvent==1)//��ϵͳʱ�䱣��ͬ��
	{
		UpdateData(true);
		CTime time=CTime::GetCurrentTime ();
		m_savecurrenttime=time.Format("%H%M%S");
		m_showtime=time.Format("%y��%m��%d��  %H:%M:%S  ��%U��  ����%w");
		TheClockIsCom();
		OffComTime();
		UpdateData(false);
	}
	else if(nIDEvent==2)//�������㱨ʱ
		WhickSongShouldHave();
	CDialog::OnTimer(nIDEvent);
}

void CClockDlg::CharToCString(char *a,int n,CString str)
{
	strncpy(a,(LPCTSTR)str,n);
}

void CClockDlg::WhickSongShouldHave()//ѡ�����㱨ʱ
{
	CSetClockTime m_SetClock;
	BOOL m_bool=false;

	CString str=m_GetCurrentDirectory+"\\sound"+"\\"+"01.MP3";
 	CString str2=m_savecurrenttime.Right (4);
	if(str2=="1800")
	{
		str.MakeReverse ();
		str.SetAt(5,m_savecurrenttime.GetAt(0));
		str.SetAt(4,m_savecurrenttime.GetAt(1));
		str.MakeReverse (); 
 	  	m_SetClock.m_media.OnMediaPlay (str);
		m_bool=true;
	}
  	if(m_bool)
		m_SetClock.m_media.UpdatePlayTime(true);
}

void CClockDlg::InitList()//��ʼ�������б��
{
 	CSetClockTime m_SetClock;
  	m_showclock.SetExtendedStyle(LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT|LVS_EX_CHECKBOXES);
 //	m_showclock.SetBkColor(RGB(22,255,100));     //���ñ���
 //	m_showclock.SetTextBkColor(RGB(100,2,33));
//	CString SexName[5]={"���Ӷ�ʱ","ʣ��ʱ��","����","��������","��������"};
	CString SexName[5]={"���Ӷ�ʱ","����","��ʾ��","�������","��������"};

	for(int i=0;i<5;i++)
	{
		m_showclock.InsertColumn(i,SexName[i],LVCFMT_LEFT,80);
	}

	m_showoffcom.SetExtendedStyle(LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT|LVS_EX_CHECKBOXES);
 	m_showoffcom.SetBkColor(RGB(22,255,100));     //���ñ���
 	m_showoffcom.SetTextBkColor(RGB(100,2,33));
//	CString str2[4]={"�ػ���ʱ","ʣ��ʱ��","��������","����"};
	CString str2[3]={"�ػ���ʱ","��ʾ��","��������"};
	for(i=0;i<3;i++)
	{
		m_showoffcom.InsertColumn(i,str2[i],LVCFMT_LEFT,80);
	}

	int cout=::GetPrivateProfileInt("FileCount","Count",0,".\\message2.ini");
	CString str;
	CString m_hour,m_musicroute,m_tellword,m_dataselect,m_musicnum,m_state;
	for( i=0;i<cout;i++)
	{
		str.Format("���ǵ�%d�����ӵ���Ϣ",i);
		::GetPrivateProfileString (str,"clockhour",NULL,m_hour.GetBuffer(6),6,".\\message2.ini");
		::GetPrivateProfileString (str,"tellword",NULL,m_tellword.GetBuffer(50),50,".\\message2.ini");
		::GetPrivateProfileString (str,"musicroute",NULL,m_musicroute.GetBuffer(50),50,".\\message2.ini");
		::GetPrivateProfileString (str,"musicnum",NULL,m_musicnum.GetBuffer(2),2,".\\message2.ini");
		::GetPrivateProfileString (str,"dataselect",NULL,m_dataselect.GetBuffer(6),6,".\\message2.ini");
		::GetPrivateProfileString (str,"state",NULL,m_state.GetBuffer(2),2,".\\message2.ini");	

		m_showclock.InsertItem(i,m_hour);
		m_showclock.SetItemText (i,1,m_musicroute);
		m_showclock.SetItemText (i,2,m_tellword);
	 	m_showclock.SetItemText (i,3,m_musicnum);
		m_showclock.SetItemText (i,4,m_dataselect);
		
		if(m_state=="Y")
			m_showclock.SetCheck (i,true);
		else
			m_showclock.SetCheck (i,false);

	}

	cout=::GetPrivateProfileInt("FileCount","Count",0,".\\message4.ini");
	for( i=0;i<cout;i++)
	{
		str.Format("�ػ���Ϣ%d",i);
		::GetPrivateProfileString (str,"offcom",NULL,m_hour.GetBuffer(9),9,".\\message4.ini");
		::GetPrivateProfileString (str,"tellword",NULL,m_tellword.GetBuffer(50),50,".\\message4.ini");
		::GetPrivateProfileString (str,"offdata",NULL,m_state.GetBuffer(2),2,".\\message4.ini");
		::GetPrivateProfileString (str,"state",NULL,m_dataselect.GetBuffer(2),2,".\\message4.ini");	

		m_showoffcom.InsertItem(i,m_hour);
		m_showoffcom.SetItemText (i,1,m_tellword);
	 	m_showoffcom.SetItemText (i,2,m_state);
		
		if(m_dataselect=="Y")
			m_showoffcom.SetCheck (i,true);
		else
			m_showoffcom.SetCheck (i,false);
	}

 	m_showclock.SetBkColor (RGB(193,210,240));
  	m_showclock.SetTextColor (RGB(32,11,225)); //���ÿؼ�������ɫ
  	m_showclock.SetTextBkColor (RGB(193,210,240));	//�������ֱ�����ɫ
 
	DeleteFile(".\\message2.ini");
	DeleteFile(".\\message4.ini");

	TCHAR szPath[50]; //�õ�����ĵ�ǰĿ¼
	GetCurrentDirectory(50,szPath);
	m_GetCurrentDirectory=szPath;
}

void CClockDlg::OnButDeleteitem() //ɾ��ѡ�е���
{
 	CSetClockTime m_SetClock;
	if(m_showclock.GetItemCount()==0)
	{
		MessageBox("û�пɹ�ɾ������,���м�¼�Ѿ�Ϊ��!");
		return;
	}
	for(int i=0;i<m_showclock.GetItemCount ();i++)
		if(m_showclock.GetItemState (i,LVIS_SELECTED)==LVIS_SELECTED)
			if(IDOK==MessageBox("�������ɾ������?","ɾ������ʱ��!",MB_OKCANCEL))
			{
				m_showclock.DeleteItem(i);	
				return;
			}
	MessageBox("��ѡ������Ҫɾ����Ԫ��!"); 
}

LRESULT CClockDlg::DefWindowProc(UINT message, WPARAM wParam, LPARAM lParam) //���ش��ں������ػ�رհ�ť��Ϣ
		//�ڹر�֮ǰ��¼��Ϣ
{
	// TODO: Add your specialized code here and/or call the base class
	if(message==WM_SYSCOMMAND)   
	{	   
		if(wParam==SC_CLOSE)   
		{   
	 		GetListString();
			SendMessage(WM_CLOSE);
 			return true;   
		}   
	}   
	return CDialog::DefWindowProc(message, wParam, lParam);
}

void CClockDlg::GetListString() //�������ʱ������Ϣд�������ļ�
{
 	CString str;
	int i=0;
	CString m_GetDirectory=m_GetCurrentDirectory+"\\"+"message2.ini";
	for(i=0;i<m_showclock.GetItemCount();i++)
	{
 		str.Format("���ǵ�%d�����ӵ���Ϣ",i);
		::WritePrivateProfileString(str,"clockhour",m_showclock.GetItemText(i,0),m_GetDirectory); 
	 	::WritePrivateProfileString(str,"musicroute",m_showclock.GetItemText(i,1),m_GetDirectory);
		::WritePrivateProfileString(str,"tellword",m_showclock.GetItemText(i,2),m_GetDirectory);
		::WritePrivateProfileString(str,"musicnum",m_showclock.GetItemText(i,3),m_GetDirectory);
		::WritePrivateProfileString(str,"dataselect",m_showclock.GetItemText(i,4),m_GetDirectory);
		if(m_showclock.GetCheck(i))
			::WritePrivateProfileString(str,"state","Y",m_GetDirectory);
		else
			::WritePrivateProfileString(str,"state","N",m_GetDirectory); 
	}
	str.Format("%d",i);	 
	::WritePrivateProfileString("FileCount","Count",str,m_GetDirectory);

	m_GetDirectory=m_GetCurrentDirectory+"\\"+"message4.ini";
	for(i=0;i<m_showoffcom.GetItemCount();i++)
	{
 		str.Format("�ػ���Ϣ%d",i);
		::WritePrivateProfileString(str,"offcom",m_showoffcom.GetItemText(i,0),m_GetDirectory); 
		::WritePrivateProfileString(str,"tellword",m_showoffcom.GetItemText(i,1),m_GetDirectory);
		::WritePrivateProfileString(str,"offdata",m_showoffcom.GetItemText(i,2),m_GetDirectory);
		if(m_showclock.GetCheck(i))
			::WritePrivateProfileString(str,"state","Y",m_GetDirectory);
		else
			::WritePrivateProfileString(str,"state","N",m_GetDirectory); 
	}
	str.Format("%d",i);	 
	::WritePrivateProfileString("FileCount","Count",str,m_GetDirectory);
}

void CClockDlg::OnButUpdata() //ˢ��������ʱ��
{
	CString str;
	int i=m_showclock.GetItemCount();
	CString m_hour,m_musicroute,m_tellword,m_musicnum,m_dataselect;
	str="���ǵ�0�����ӵ���Ϣ";
	::GetPrivateProfileString (str,"clockhour",NULL,m_hour.GetBuffer(6),6,".\\message.ini");
	::GetPrivateProfileString (str,"musicroute",NULL,m_musicroute.GetBuffer(50),50,".\\message.ini");
	::GetPrivateProfileString (str,"tellword",NULL,m_tellword.GetBuffer(50),50,".\\message.ini");
	::GetPrivateProfileString (str,"musicnum",NULL,m_musicnum.GetBuffer(2),2,".\\message.ini");
	::GetPrivateProfileString (str,"dataselect",NULL,m_dataselect.GetBuffer(6),6,".\\message.ini");
			
	m_showclock.InsertItem(i,m_hour);
	m_showclock.SetItemText (i,1,m_musicroute);
	m_showclock.SetItemText (i,2,m_tellword);
	m_showclock.SetItemText (i,3,m_musicnum);
	m_showclock.SetItemText (i,4,m_dataselect);
  
	m_showclock.SetCheck(i,true);
  	DeleteFile("message.ini");//ɾ��message�е����ݣ��Ա������±����ŵ�����	
}

void CClockDlg::TheClockIsCom() //���ӱ�ʱ
{
	CSetClockTime m_SetClock;
	BOOL m_bool=false;

	for(int i=0;i<m_showclock.GetItemCount();i++)
	{
		if(m_showclock.GetCheck(i))
		{
			CString str=m_showclock.GetItemText(i,0);
			if(str.Left(2)==m_savecurrenttime.Left(2) && 
				str.Right (2)==m_savecurrenttime.Mid(2,2) &&
 				m_savecurrenttime.Right (2)=="00")
			{
				m_SetClock.m_media.OnMediaPlay (m_showclock.GetItemText(i,1));
				m_bool=true;
			}
		}
	}
	if(m_bool)
		m_SetClock.m_media.UpdatePlayTime(true);
	
}

void CClockDlg::OnButUpdataCom() //ˢ�¹ػ�ʱ��
{
	CString str;
	int i=m_showoffcom.GetItemCount();
	CString m_hour,m_tellword,m_state,state;
	str="�ػ���Ϣ";
	::GetPrivateProfileString (str,"offcom",NULL,m_hour.GetBuffer(9),9,".\\message3.ini");
	::GetPrivateProfileString (str,"tellword",NULL,m_tellword.GetBuffer(50),50,".\\message3.ini");
	::GetPrivateProfileString (str,"offdata",NULL,m_state.GetBuffer(2),2,".\\message3.ini");
	::GetPrivateProfileString (str,"state",NULL,state.GetBuffer(2),2,".\\message3.ini");
			
	m_showoffcom.InsertItem(i,m_hour);
	m_showoffcom.SetItemText (i,1,m_tellword);
	m_showoffcom.SetItemText (i,2,m_state);
  
	m_showoffcom.SetCheck(i,true);
  	DeleteFile("message3.ini");//ɾ��message�е����ݣ��Ա������±����ŵ�����		
}

void CClockDlg::OffComTime()
{
	CSetClockTime m_SetClock;

	for(int i=0;i<m_showoffcom.GetItemCount();i++)
	{
		if(m_showoffcom.GetCheck(i))
		{
			CString str=m_showoffcom.GetItemText(i,0);
			if(str.Left(2)==m_savecurrenttime.Left(2) && 
				str.Mid (3,2)==m_savecurrenttime.Mid(2,2) &&
				str.Right (2)==m_savecurrenttime.Right(2))
			{
				ShutDown();
				return;
			}
		}
	}
}

void CClockDlg::ShutDown()
{
	if(MessageBox("ȷ���رռ����?","��Ϣѯ��",MB_YESNO)==IDYES)
	{	
		HANDLE hToken;
		TOKEN_PRIVILEGES tkp;
		OpenProcessToken (GetCurrentProcess (),//��ȡ��ǰ���̾��������
			TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY,
			&hToken);
		LookupPrivilegeValue (NULL,SE_SHUTDOWN_NAME,&tkp.Privileges[0].Luid );
		tkp.PrivilegeCount =1;//���ý������ȼ�
		tkp.Privileges[0].Attributes =SE_PRIVILEGE_ENABLED;
		AdjustTokenPrivileges(hToken,false,&tkp,0,(PTOKEN_PRIVILEGES)NULL,0);
		CloseHandle(hToken);  
		::ExitWindowsEx(EWX_POWEROFF,0);//�رռ����
	}
}

void CClockDlg::OnButDelItem() 
{
	CSetClockTime m_SetClock;
	if(m_showoffcom.GetItemCount()==0)
	{
		MessageBox("û�пɹ�ɾ������,���м�¼�Ѿ�Ϊ��!");
		return;
	}
	for(int i=0;i<m_showoffcom.GetItemCount ();i++)
		if(m_showoffcom.GetItemState (i,LVIS_SELECTED)==LVIS_SELECTED)
			if(IDOK==MessageBox("�������ɾ������?","ɾ������ʱ��!",MB_OKCANCEL))
			{
				m_showoffcom.DeleteItem(i);	
				return;
			}
	MessageBox("��ѡ������Ҫɾ����Ԫ��!"); 	
}
