//Download by http://www.NewXing.com
/*----------------------------------------
   BTNLOOK.C -- Button Look Program
                (c) Charles Petzold, 1998
  ----------------------------------------*/

#include <windows.h>
#include <commdlg.h>

void PopFileInitialize (HWND) ;
BOOL PopFileOpenDlg    (HWND, PTSTR, PTSTR) ;
void paly_mp3(char *dress);
void pause_mp3();
void reset_mp3();

struct
{
     int     iStyle ;
     TCHAR * szText ;
}
button[] =
{
     BS_PUSHBUTTON,   TEXT ("Open"),
     BS_PUSHBUTTON,   TEXT ("Play"),
     BS_PUSHBUTTON,   TEXT ("Stop"), 
	 BS_PUSHBUTTON,   TEXT ("Reset"),
     BS_PUSHBUTTON,   TEXT ("Exit"),
} ;

#define NUM (sizeof button / sizeof button[0])
TCHAR szAppName[] = TEXT ("BtnLook") ;

LRESULT CALLBACK WndProc (HWND, UINT, WPARAM, LPARAM) ;

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    PSTR szCmdLine, int iCmdShow)
{
     HWND         hwnd ;
     MSG          msg ;
     WNDCLASS     wndclass ;
     
     wndclass.style         = CS_HREDRAW | CS_VREDRAW ;
     wndclass.lpfnWndProc   = WndProc ;
     wndclass.cbClsExtra    = 0 ;
     wndclass.cbWndExtra    = 0 ;
     wndclass.hInstance     = hInstance ;
     wndclass.hIcon         = LoadIcon (NULL, IDI_APPLICATION) ;
     wndclass.hCursor       = LoadCursor (NULL, IDC_ARROW) ;
     wndclass.hbrBackground = (HBRUSH) GetStockObject (WHITE_BRUSH) ;
     wndclass.lpszMenuName  = NULL ;
     wndclass.lpszClassName = szAppName ;
     
     if (!RegisterClass (&wndclass))
     {
          MessageBox (NULL, TEXT ("This program requires Windows NT!"),
                      szAppName, MB_ICONERROR) ;
          return 0 ;
     }
     
     hwnd = CreateWindow (szAppName, TEXT ("Audio Player"),
                          WS_OVERLAPPEDWINDOW,
                          200, 200,
                          290, 170,
                          NULL, NULL, hInstance, NULL) ;
     
     ShowWindow (hwnd, iCmdShow) ;
     UpdateWindow (hwnd) ;
     
     while (GetMessage (&msg, NULL, 0, 0))
     {
          TranslateMessage (&msg) ;
          DispatchMessage (&msg) ;
     }
     return msg.wParam ;
}

LRESULT CALLBACK WndProc (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
     static HWND  hwndButton[NUM] ;
	 static RECT rect;
     static HDC hdc ;
	 static TCHAR szBuffer[50];
	 static TCHAR szTop[] = TEXT("The song to play:");
	 static TCHAR szFileName[MAX_PATH], szTitleName[MAX_PATH] ;
     static int cxChar, cyChar ;
	 static PAINTSTRUCT  ps ;
	 static int i;

     switch (message)
     {
     case WM_CREATE :
		  cxChar = LOWORD (GetDialogBaseUnits ()) ;
          cyChar = HIWORD (GetDialogBaseUnits ()) ;
          
          for (i = 0 ; i < NUM ; i++)
               hwndButton[i] = CreateWindow ( TEXT("button"), 
                                   button[i].szText,
                                   WS_CHILD | WS_VISIBLE | button[i].iStyle,
                                   cyChar * (1 + 3 * i),cyChar * 5,
                                   5 * cxChar, 7 * cyChar / 4,
                                   hwnd, (HMENU)i,
                                   ((LPCREATESTRUCT) lParam)->hInstance, NULL) ;
		  PopFileInitialize (hwnd) ;
		  EnableWindow (GetDlgItem(hwnd,1), FALSE);
		  EnableWindow (GetDlgItem(hwnd,2), FALSE);
		  EnableWindow (GetDlgItem(hwnd,3), FALSE);
     return 0 ;

     case WM_SIZE :
		           rect.left   = 24 * cxChar ;
          rect.top    =  2 * cyChar ;
          rect.right  = LOWORD (lParam) ;
          rect.bottom = HIWORD (lParam) ;
     return 0 ;    

     case WM_PAINT :
		  InvalidateRect (hwnd, &rect, TRUE) ;
          hdc = BeginPaint (hwnd, &ps) ;
          SetBkMode (hdc, TRANSPARENT) ;
          TextOut (hdc, 2 * cxChar, cyChar, szTop, lstrlen (szTop)) ;
          EndPaint (hwnd, &ps) ;
     return 0 ;  
     case WM_DRAWITEM :
	 return 0 ; 
     case WM_COMMAND :  
        switch (LOWORD (wParam))
		{
		case 0 :
			if (!PopFileOpenDlg (hwnd, szFileName, szTitleName))
			{
				MessageBox(hwnd, TEXT ("give up!"),
                szTitleName,0) ;
                szFileName[0]  = '\0' ;
                szTitleName[0] = '\0' ;
			}
		    else 
			{
		    	hdc=GetDC(hwnd);
			    TextOut (hdc, 2 * cxChar, 3 * cyChar, szTitleName, lstrlen (szTitleName)) ;
				
			    TextOut (hdc, 2 * cxChar, 6 * cyChar, szFileName, lstrlen (szFileName)) ; 
				EnableWindow (GetDlgItem(hwnd,0), FALSE);
			    EnableWindow (GetDlgItem(hwnd,1), TRUE);
		     	EnableWindow (GetDlgItem(hwnd,2), TRUE);
		    	EnableWindow (GetDlgItem(hwnd,3), TRUE);
			}
		    return 0 ;
		case 1:
			paly_mp3(szFileName);
			return 0;
		case 2:
			pause_mp3();
			return 0;
		case 3:
			reset_mp3();
			EnableWindow (GetDlgItem(hwnd,0), TRUE);
			EnableWindow (GetDlgItem(hwnd,1), FALSE);
			EnableWindow (GetDlgItem(hwnd,2), FALSE);
			szFileName[0]  = '\0' ;
            szTitleName[0] = '\0' ;
            return 0;
		case 4:
			exit(0);
			return 0;
		}
		return 0;
     case WM_DESTROY :
		 exit(0);
     return 0 ;
     }
     return DefWindowProc (hwnd, message, wParam, lParam) ;
}
