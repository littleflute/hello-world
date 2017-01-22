// MyMedia.cpp: implementation of the CMyMedia class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MyMedia.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMyMedia::CMyMedia()
{

}

CMyMedia::~CMyMedia()
{

}

void CMyMedia::OnMediaClose()//关闭媒体播放器
{
	mciSendString ("close MYPLAYER",0,0,0);//关闭播放
}

void CMyMedia::OnMediaPlay(CString m_musicroute)//开始播放音乐
{
	OnMediaClose();
	OnOpenMedia(m_musicroute);
	mciSendString("play MYPLAYER",NULL,0,NULL);//播放音频文件
}

BOOL CMyMedia::OnOpenMedia(LPCTSTR lpszName)
{
	MCI_OPEN_PARMS mciOpen;//声明打开结构体
	CString strMusic = lpszName;
	CString strExtent = strMusic.Right(3);//得到文件的后缀名
	strExtent.MakeLower ();//使后缀变成小写字母

	if(strExtent=="wav")
		mciOpen.lpstrDeviceType ="waveaudio";//设置设备类型为waveaudio
	else
		mciOpen.lpstrDeviceType ="mpegvideo";//设置设备类型为mpegvideo

	mciOpen.lpstrElementName =strMusic;//得到文件的全名
	mciOpen.lpstrAlias ="MyPlayer";//设置可选设备的别名

	int nError;
	nError=mciSendCommand (NULL,MCI_OPEN,
							MCI_OPEN_ELEMENT | MCI_OPEN_ALIAS | MCI_OPEN_TYPE,
							(DWORD)&mciOpen);//向设备发送打开音频文件的命令

	if(nError!=0)
	{
		char szError[100];
		mciGetErrorString(nError,szError,100);
		AfxMessageBox("找不到该歌曲!");
		return false;
	}
	return true;
}

void CMyMedia::OnMediaStop()
{
	mciSendString("stop MYPLAYER",NULL,0,NULL);//暂停音频文件
}

void CMyMedia::UpdatePlayTime(BOOL bProgress)
{
	DWORD nLength;
	CString m_ShowTheLastTime;

	GetMediaLength(nLength,bProgress);//得到总长或者已经播放时间
//	Length=nLength;
/*	if(bProgress)
	{
		m_sliderjindu.SetPos (nLength/1000);//设置进度条范围,m_sliderjindu为进度条变量
		nLength=(m_dwTotalLen-nLength);//得到未播放的总长
	}
	else
	{
		m_dwTotalLen=nLength;//保存播放总长度
		m_sliderjindu.SetRange (0,m_dwTotalLen/1000);//显示已经播放进度
	}*/
		 
	nLength=nLength/1000;
	int nHour=nLength/3600;//得到播放的时
	int nMinute=(nLength-nHour*3600)/60;//分
	int nSecond=nLength%60;//秒
	m_ShowTheLastTime.Format("%02d:%02d:%02d",nHour,nMinute,nSecond);//显示播放的时间
	if(OnIsSongOver(m_ShowTheLastTime))
		OnMediaClose();
//	UpdateData(false);
}

BOOL CMyMedia::OnIsSongOver(CString m_SongLastTime)
{
	if(m_ShowTheLastTime=="00:00:00")
	{
		OnMediaClose();
		return true;
	}
	else
		return false;
}

BOOL CMyMedia::GetMediaLength(DWORD &nLength, BOOL bProgress)
{
	int nError;
	char szlength[20];
	mciSendString ("set MYPLAYER time formal milliseconds",NULL,0,NULL);

	if(bProgress)
	{
		nError=mciSendString ("status MYPLAYER position",szlength,20,NULL);//得到现在的播放进度
	}
	else
	{
		nError=mciSendString ("status MYPLAYER length",szlength,20,NULL);//得到播放的总长度
	}

	if(nError!=0)
	{
		char szError[100];
		mciGetErrorString(nError,szError,100);//得到错误字符串
		AfxMessageBox(szError);
//		KillTimer (1);//关闭定时器
		return false;
	}
	nLength=atol(szlength);//转换成长整型
	return true;
}

CString CMyMedia::OnMusicRouteToName(CString m_musicroute)
{
	m_musicroute.MakeReverse ();//将字符串颠倒过来
	m_musicroute=m_musicroute.Left (m_musicroute.Find ('\\'));
	m_musicroute.MakeReverse ();
	m_musicroute=m_musicroute.Left (m_musicroute.GetLength ()-4);
	return m_musicroute;
}
