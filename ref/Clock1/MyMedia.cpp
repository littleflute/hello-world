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

void CMyMedia::OnMediaClose()//�ر�ý�岥����
{
	mciSendString ("close MYPLAYER",0,0,0);//�رղ���
}

void CMyMedia::OnMediaPlay(CString m_musicroute)//��ʼ��������
{
	OnMediaClose();
	OnOpenMedia(m_musicroute);
	mciSendString("play MYPLAYER",NULL,0,NULL);//������Ƶ�ļ�
}

BOOL CMyMedia::OnOpenMedia(LPCTSTR lpszName)
{
	MCI_OPEN_PARMS mciOpen;//�����򿪽ṹ��
	CString strMusic = lpszName;
	CString strExtent = strMusic.Right(3);//�õ��ļ��ĺ�׺��
	strExtent.MakeLower ();//ʹ��׺���Сд��ĸ

	if(strExtent=="wav")
		mciOpen.lpstrDeviceType ="waveaudio";//�����豸����Ϊwaveaudio
	else
		mciOpen.lpstrDeviceType ="mpegvideo";//�����豸����Ϊmpegvideo

	mciOpen.lpstrElementName =strMusic;//�õ��ļ���ȫ��
	mciOpen.lpstrAlias ="MyPlayer";//���ÿ�ѡ�豸�ı���

	int nError;
	nError=mciSendCommand (NULL,MCI_OPEN,
							MCI_OPEN_ELEMENT | MCI_OPEN_ALIAS | MCI_OPEN_TYPE,
							(DWORD)&mciOpen);//���豸���ʹ���Ƶ�ļ�������

	if(nError!=0)
	{
		char szError[100];
		mciGetErrorString(nError,szError,100);
		AfxMessageBox("�Ҳ����ø���!");
		return false;
	}
	return true;
}

void CMyMedia::OnMediaStop()
{
	mciSendString("stop MYPLAYER",NULL,0,NULL);//��ͣ��Ƶ�ļ�
}

void CMyMedia::UpdatePlayTime(BOOL bProgress)
{
	DWORD nLength;
	CString m_ShowTheLastTime;

	GetMediaLength(nLength,bProgress);//�õ��ܳ������Ѿ�����ʱ��
//	Length=nLength;
/*	if(bProgress)
	{
		m_sliderjindu.SetPos (nLength/1000);//���ý�������Χ,m_sliderjinduΪ����������
		nLength=(m_dwTotalLen-nLength);//�õ�δ���ŵ��ܳ�
	}
	else
	{
		m_dwTotalLen=nLength;//���沥���ܳ���
		m_sliderjindu.SetRange (0,m_dwTotalLen/1000);//��ʾ�Ѿ����Ž���
	}*/
		 
	nLength=nLength/1000;
	int nHour=nLength/3600;//�õ����ŵ�ʱ
	int nMinute=(nLength-nHour*3600)/60;//��
	int nSecond=nLength%60;//��
	m_ShowTheLastTime.Format("%02d:%02d:%02d",nHour,nMinute,nSecond);//��ʾ���ŵ�ʱ��
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
		nError=mciSendString ("status MYPLAYER position",szlength,20,NULL);//�õ����ڵĲ��Ž���
	}
	else
	{
		nError=mciSendString ("status MYPLAYER length",szlength,20,NULL);//�õ����ŵ��ܳ���
	}

	if(nError!=0)
	{
		char szError[100];
		mciGetErrorString(nError,szError,100);//�õ������ַ���
		AfxMessageBox(szError);
//		KillTimer (1);//�رն�ʱ��
		return false;
	}
	nLength=atol(szlength);//ת���ɳ�����
	return true;
}

CString CMyMedia::OnMusicRouteToName(CString m_musicroute)
{
	m_musicroute.MakeReverse ();//���ַ����ߵ�����
	m_musicroute=m_musicroute.Left (m_musicroute.Find ('\\'));
	m_musicroute.MakeReverse ();
	m_musicroute=m_musicroute.Left (m_musicroute.GetLength ()-4);
	return m_musicroute;
}
