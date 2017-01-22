; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDlgDemo
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "GdiPlusDemo.h"
LastPage=0

ClassCount=6
Class1=CGdiPlusDemoApp
Class2=CGdiPlusDemoDoc
Class3=CGdiPlusDemoView
Class4=CMainFrame

ResourceCount=3
Resource1=IDR_MAINFRAME
Resource2=IDD_ABOUTBOX
Class5=CAboutDlg
Class6=CDlgDemo
Resource3=IDD_DIALOG1

[CLS:CGdiPlusDemoApp]
Type=0
HeaderFile=GdiPlusDemo.h
ImplementationFile=GdiPlusDemo.cpp
Filter=N
BaseClass=CWinApp
VirtualFilter=AC

[CLS:CGdiPlusDemoDoc]
Type=0
HeaderFile=GdiPlusDemoDoc.h
ImplementationFile=GdiPlusDemoDoc.cpp
Filter=N

[CLS:CGdiPlusDemoView]
Type=0
HeaderFile=GdiPlusDemoView.h
ImplementationFile=GdiPlusDemoView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=CGdiPlusDemoView


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T




[CLS:CAboutDlg]
Type=0
HeaderFile=GdiPlusDemo.cpp
ImplementationFile=GdiPlusDemo.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_VIEW_TOOLBAR
Command15=ID_VIEW_STATUS_BAR
Command16=ID_APP_ABOUT
CommandCount=16

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
Command9=ID_GDIPLUS_DEMO
CommandCount=9

[DLG:IDD_DIALOG1]
Type=1
Class=CDlgDemo
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_TREE1,SysTreeView32,1350631463
Control4=IDC_BUTTON1,button,1342242816

[CLS:CDlgDemo]
Type=0
HeaderFile=DlgDemo.h
ImplementationFile=DlgDemo.cpp
BaseClass=CDialog
Filter=D
LastObject=CDlgDemo
VirtualFilter=dWC

