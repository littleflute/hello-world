//������ʹ�õ���VC�е�MCI���
#include <stdio.h> 
#include <stdlib.h>
#include <windows.h>
#include <mmsystem.h>//����windows�����ý���йصĴ�����ӿ�
#include <conio.h>
#define SHOWMSG(_msg) MessageBox(NULL, _msg, TEXT("msg"), MB_OK)
//Download by http://www.NewXing.com
MCI_PLAY_PARMS mciPlay; 
UINT DeviceID;
MCI_OPEN_PARMS mciOpen;

#pragma comment(lib,"winmm.lib")//���̱���ӵ�һ�仰

void paly_mp3(char *dress)//����MP3����
{
	char buf[128]={0}; 
    MCIERROR mciError; 
    mciOpen.lpstrDeviceType = "mpegvideo"; 
    mciOpen.lpstrElementName = dress;//�����ļ��ĵ�ַ,֧�ָ�ʽmp3 
    mciError = mciSendCommand(0,MCI_OPEN,MCI_OPEN_TYPE | MCI_OPEN_ELEMENT,(DWORD)&mciOpen); 
    if(mciError) 
	{ 
		mciGetErrorString(mciError,buf,128); 
	} 
	DeviceID = mciOpen.wDeviceID ; 
    mciError = mciSendCommand(DeviceID,MCI_PLAY,0 ,(DWORD)&mciPlay); 
    if(mciError) 
	{ 
		MessageBox (NULL, TEXT ("send MCI_PLAY command failed!"), NULL, 0) ;
	}
}

void pause_mp3()//��ͣ���ֲ��� 
{
	DWORD dwReturn = 0;
    dwReturn = mciSendCommand(DeviceID,MCI_PAUSE,0 ,(DWORD)&mciPlay);
    if (dwReturn) {
        SHOWMSG("MCI stop error");
    }
}

void reset_mp3()//����
{
    DWORD dwReturn = 0;
    dwReturn = mciSendCommand(DeviceID,MCI_STOP,0 ,(DWORD)&mciPlay);
    if (dwReturn) {
        SHOWMSG("MCI stop error");
    }
	dwReturn = mciSendCommand(DeviceID,MCI_CLOSE,0 ,(DWORD)&mciPlay);
    if (dwReturn) {
        SHOWMSG("MCI close error");
    }
}
