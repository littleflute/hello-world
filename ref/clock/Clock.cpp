// ƒ÷÷”.cpp : Defines the entry point for the application.
// Download by http://www.NewXing.com
#include "stdafx.h"
#include "mmsystem.h"

POINT dy[60]={200,18,218,20,234,22,252,28,270,34,288,42,304,51,318,62,334,78,344,90,356,108,362,120,368,135,373,152,378,175,380,200,
			 379,221,375,242,370,260,364,276,356,289,346,306,336,318,320,334,306,345,290,356,272,366,254,373,236,377,220,379,200,380,
			 182,379,166,377,148,373,130,366,112,358,96,347,82,336,66,320,54,306,44,289,36,276,30,260,23,240,21,219,20,200,
			 21,177,24,158,29,141,35,126,44,112,54,94,66,80,80,66,96,53,110,44,130,33,146,27,164,22,180,20};
POINT zy[60]={200,39,216,40,231,42,247,46,263,52,279,60,293,69,305,78,319,92,329,102,339,118,345,128,350,143,355,157,360,178,360,200,
             359,218,357,239,352,252,346,268,342,280,332,294,321,306,309,319,295,331,280,340,263,348,248,353,232,357,218,359,200,360,
             184,360,170,359,154,355,138,348,123,341,110,332,96,323,82,307,71,296,61,282,55,269,48,254,42,236,40,218,40,200,
             41,180,45,162,49,148,53,136,58,122,68,106,78,93,91,81,106,70,120,60,136,52,152,46,168,42,182,40};
POINT xy[60]={200,60,214,61,227,63,241,66,253,70,268,77,280,84,292,94,304,106,312,116,320,128,324,138,330,148,334,160,338,178,340,200,
             339,214,336,232,332,246,326,259,320,270,314,282,306,290,294,304,284,312,270,322,254,330,242,334,228,338,216,340,200,340,
             186,340,174,338,160,334,146,330,132,324,120,316,110,308,96,294,86,284,78,272,72,260,68,248,62,232,60,216,60,200,
             61,182,62,167,66,154,72,142,78,130,86,118,94,106,104,96,116,86,128,78,144,70,158,64,170,62,182,60};          

static SYSTEMTIME sys;

void fenzheng(HDC hdc);
void shizheng(HDC hdc);
void miaozheng(HDC hdc);
void huakj(HDC hdc);
void shuzi(HDC hdc);
void CALLBACK timer(HWND hwnd,UINT message,UINT timerid,DWORD timer);
void CALLBACK yidong(HWND hwnd,UINT message,UINT timerid,DWORD timer);
LRESULT CALLBACK wndproc(HWND hwnd,UINT message,WPARAM wParam,LPARAM lParam);



int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     szCmdLine,
                     int       iCmdShow)
{
 	// TODO: Place code here.
    HWND hwnd;
	MSG msg;
	static TCHAR szappname[]=TEXT("Clock");
	WNDCLASS wndclass;
	wndclass.cbClsExtra=0;
	wndclass.cbWndExtra=0;
	wndclass.style=CS_VREDRAW|CS_HREDRAW;
	wndclass.lpfnWndProc=wndproc;
	wndclass.hInstance=hInstance;
	wndclass.hIcon=LoadIcon(NULL,IDI_APPLICATION);
	wndclass.hCursor=LoadCursor(NULL,IDC_ARROW);
	wndclass.hbrBackground=(HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass.lpszClassName=szappname;
	wndclass.lpszMenuName=NULL;
	RegisterClass(&wndclass);
	hwnd=CreateWindow(szappname,TEXT("ClockWnd"),WS_OVERLAPPEDWINDOW,500,100,400,500,
		NULL,NULL,hInstance,NULL);
	ShowWindow(hwnd,iCmdShow);
	UpdateWindow(hwnd);
	while(GetMessage(&msg,NULL,NULL,NULL))
	{
	  TranslateMessage(&msg);
	  DispatchMessage(&msg);
	}
	return msg.wParam;
}

LRESULT CALLBACK wndproc(HWND hwnd,UINT message,WPARAM wParam,LPARAM lParam)
{
  HWND hwndedit,hwndstatic;
  static HINSTANCE hInstance;
  HDC hdc;
  PAINTSTRUCT ps;
  switch(message)
  {
  case WM_CREATE:
	  {
		hwndstatic=CreateWindow(TEXT("STATIC"),TEXT("Time:"),WS_CHILD|WS_VISIBLE,100,400,160,20,hwnd,(HMENU)1,hInstance,NULL);
		hwndedit=CreateWindow(TEXT("EDIT"),TEXT(""),WS_CHILD|WS_VISIBLE|ES_READONLY,190,400,140,20,hwnd,(HMENU)2,hInstance,NULL);
		SetTimer(hwnd,0,1000,timer);
		SetTimer(hwnd,1,1000,yidong);
	    return 0;
	  }
  case WM_PAINT:
	  {
	   hdc=BeginPaint(hwnd,&ps);
	   huakj(hdc);
	   EndPaint(hwnd,&ps);
	   return 0;
	  }
  case WM_DESTROY:
	  {
	    PostQuitMessage(0);
		return 0;
	  }
  }
  return DefWindowProc(hwnd,message,wParam,lParam);
}

void huakj(HDC hdc)
{
  HPEN hPen,hPen1;
  HBRUSH hBrush,hBrush1,hBrush2;
  hBrush=CreateSolidBrush(RGB(0,0,255));
  hBrush1=CreateSolidBrush(RGB(0,255,0));
  hBrush2=CreateSolidBrush(RGB(255,0,0));
  hPen=CreatePen(PS_SOLID,0,RGB(255,0,0));
  hPen1=CreatePen(PS_SOLID,0,RGB(0,0,0));
  SelectObject(hdc,hBrush);
  SelectObject(hdc,hPen);
  Ellipse(hdc,20,20,380,380);
  for(int i=0;i<60;i++)
  {
  SelectObject(hdc,hBrush);
  Ellipse(hdc,dy[i].x-10,dy[i].y-10,dy[i].x+10,dy[i].y+10);
  if(i%5==0)
  {
  SelectObject(hdc,hBrush2);
  Ellipse(hdc,dy[i].x-5,dy[i].y-5,dy[i].x+5,dy[i].y+5);
  Ellipse(hdc,190,190,208,208);
  }
  else
  {
  SelectObject(hdc,hBrush1);
  Ellipse(hdc,dy[i].x-3,dy[i].y-3,dy[i].x+3,dy[i].y+3);
  }
  }
}

void CALLBACK timer(HWND hwnd,UINT message,UINT timerid,DWORD timer)
{
 GetLocalTime(&sys);
 TCHAR time[256];
 wsprintf(time,"%02d-%02d-%02d %02d:%02d:%02d",sys.wYear,sys.wMonth,sys.wDay,sys.wHour,sys.wMinute,sys.wSecond);
 SetDlgItemText(hwnd,2,time);
}

void CALLBACK yidong(HWND hwnd,UINT message,UINT timerid,DWORD timer)
{
 HDC hdc;
 HBRUSH hBrush,hBrush1,hBrush2;
 hdc=GetDC(hwnd);
 huakj(hdc);
 hBrush=CreateSolidBrush(RGB(0,0,255));
 hBrush1=CreateSolidBrush(RGB(255,0,0));
 hBrush2=CreateSolidBrush(RGB(0,0,0));
 SelectObject(hdc,hBrush);
 Ellipse(hdc,20,20,380,380);
 SelectObject(hdc,hBrush2);
 Ellipse(hdc,180,180,218,218);
 SelectObject(hdc,hBrush1);
 miaozheng(hdc);
 fenzheng(hdc);
 shuzi(hdc);
 shizheng(hdc);
 ReleaseDC(hwnd,hdc);
}
void miaozheng(HDC hdc)
{
 static int i;
 Ellipse(hdc,190,190,208,208);
 MoveToEx(hdc,200,200,NULL);
 i=sys.wSecond;
 ++i%=60;
 LineTo(hdc,dy[i].x,dy[i].y);
 Ellipse(hdc,dy[i].x-10,dy[i].y-10,dy[i].x+10,dy[i].y+10);
}

void fenzheng(HDC hdc)
{
for(int i=0;i<60;i++)
{
static int j;
Ellipse(hdc,zy[i].x-2,zy[i].y-2,zy[i].x+2,zy[i].y+2);
j=sys.wMinute; 
MoveToEx(hdc,200,200,NULL);
LineTo(hdc,zy[j].x,zy[j].y);
Rectangle(hdc,zy[j].x-5,zy[j].y-5,zy[j].x+5,zy[j].y+5);
if(sys.wSecond==0)
{
 ++j%=60;
 PlaySound(TEXT("xuanzhuan.wav"),NULL,SND_FILENAME|SND_ASYNC);
}
}
}

void shuzi(HDC hdc)
{
SetBkColor(hdc,RGB(0,0,255));
SetTextColor(hdc,RGB(255,0,0));
TextOut(hdc,344,190,TEXT("3"),1);
TextOut(hdc,195,340,TEXT("6"),1);
TextOut(hdc,50,192,TEXT("9"),1);
TextOut(hdc,193,46,TEXT("12"),2);
}

void shizheng(HDC hdc)
{
 HBRUSH hBrush;
 hBrush=CreateSolidBrush(RGB(255,255,255));
 SelectObject(hdc,hBrush);
 static int i,j=0;
 i=(sys.wHour-12)*5;
 //Ellipse(hdc,60,60,340,340);
 for(int k=0;k<60;k++)
 {
 Ellipse(hdc,xy[k].x-1,xy[k].y-1,xy[k].x+2,xy[k].y+2);
 }
 if(sys.wMinute==0)
 {
  j=i;
 }
 if(sys.wMinute>=12)
 {
  j=i+1;
 }
 if(sys.wMinute>=24)
 {
  j=i+2;
 }
 if(sys.wMinute>=36)
 {
  j=i+3;
 }
 if(sys.wMinute>=48)
 {
  j=i+4;
 }
 MoveToEx(hdc,200,200,NULL);
 LineTo(hdc,xy[j].x,xy[j].y);
}