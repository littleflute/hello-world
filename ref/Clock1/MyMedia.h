// MyMedia.h: interface for the CMyMedia class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYMEDIA_H__FF211E9C_0A68_4DB9_9576_2ADDB7285A4B__INCLUDED_)
#define AFX_MYMEDIA_H__FF211E9C_0A68_4DB9_9576_2ADDB7285A4B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMyMedia  
{
public:
	CString m_ShowTheLastTime;
	CString OnMusicRouteToName(CString m_musicroute);
	BOOL GetMediaLength(DWORD &nLength,BOOL bProgress);
	BOOL OnIsSongOver(CString m_SongLastTime);
	void UpdatePlayTime(BOOL bProgress);
	void OnMediaStop();
	BOOL OnOpenMedia(LPCTSTR lpszName);
	void OnMediaPlay(CString m_musicroute);
	void OnMediaClose();
	CMyMedia();
	virtual ~CMyMedia();

};

#endif // !defined(AFX_MYMEDIA_H__FF211E9C_0A68_4DB9_9576_2ADDB7285A4B__INCLUDED_)
