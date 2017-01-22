; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CClockDlg
LastTemplate=CWinThread
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Clock.h"

ClassCount=6
Class1=CClockApp
Class2=CClockDlg
Class3=CAboutDlg

ResourceCount=9
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_DIALOG1
Resource4=IDD_CLOCK_DIALOG
Class4=CSetClockTime
Class5=CSetOffCmpTime
Class6=CMediaClass
Resource5=IDD_DIALOG2
Resource6=IDD_DIALOG1 (Chinese (P.R.C.))
Resource7=IDD_ABOUTBOX (Chinese (P.R.C.))
Resource8=IDD_CLOCK_DIALOG (Chinese (P.R.C.))
Resource9=IDD_DIALOG2 (Chinese (P.R.C.))

[CLS:CClockApp]
Type=0
HeaderFile=Clock.h
ImplementationFile=Clock.cpp
Filter=N

[CLS:CClockDlg]
Type=0
HeaderFile=ClockDlg.h
ImplementationFile=ClockDlg.cpp
Filter=D
LastObject=CClockDlg
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=ClockDlg.h
ImplementationFile=ClockDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_CLOCK_DIALOG]
Type=1
Class=CClockDlg
ControlCount=13
Control1=IDC_STATIC,static,1342308352
Control2=IDC_BUT_SET_CLOCKTIME,button,1342242816
Control3=IDC_BUT_OPEN_TELLTIME,button,1342242816
Control4=IDC_BUT_OFF_COMPUTER,button,1342242816
Control5=IDC_STATIC,static,1342308352
Control6=IDC_SHOW_TIME,static,1342308352
Control7=IDC_LIST_SHOWCLOCK,SysListView32,1350631425
Control8=IDC_LIST_SHOWOFFCOM,SysListView32,1350631425
Control9=IDC_STATIC,static,1342308352
Control10=IDC_BUT_DELETEITEM,button,1342242816
Control11=IDC_BUT_DEL_ITEM,button,1342242816
Control12=IDC_BUT_UPDATA,button,1073807360
Control13=IDC_BUT_UPDATA_COM,button,1073807360

[DLG:IDD_DIALOG1]
Type=1
Class=CSetClockTime
ControlCount=19
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_COM_SEL_HOUR,combobox,1344339970
Control5=IDC_STATIC,static,1342308352
Control6=IDC_COM_SEL_MINUTE,combobox,1344339970
Control7=IDC_STATIC,static,1342308352
Control8=IDC_COM_SEL_MUSIC,combobox,1344339970
Control9=IDC_BUT_FIND,button,1342242816
Control10=IDC_BUT_TRYLISTEN,button,1342242816
Control11=IDC_BUT_STOPMUSIC,button,1342242816
Control12=IDC_EDIT_TELLWORD,edit,1350631552
Control13=IDC_STATIC,button,1342177287
Control14=IDC_COM_SEL_DATA,combobox,1344339970
Control15=IDC_BUT_ADDTIME,button,1342242816
Control16=IDC_STATIC,static,1342308352
Control17=IDC_RADIO_ONE,button,1342308361
Control18=IDC_RADIO_ALL,button,1342177289
Control19=IDC_STATIC,static,1342308352

[DLG:IDD_DIALOG2]
Type=1
Class=CSetOffCmpTime
ControlCount=15
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_COM_SEL_HOUR,combobox,1344340226
Control4=IDC_STATIC,static,1342308352
Control5=IDC_COM_SEL_MINUTE,combobox,1344340226
Control6=IDC_STATIC,static,1342308352
Control7=IDC_COM_SEL_SECOND,combobox,1344340226
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352
Control10=IDC_EDIT_TELL_WORD,edit,1350631552
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC,button,1342177287
Control13=IDC_RADIO_ONE,button,1342308361
Control14=IDC_RADIO_ALL,button,1342177289
Control15=IDC_BUT_ADD_OFFTIME,button,1342242816

[CLS:CSetClockTime]
Type=0
HeaderFile=SetClockTime.h
ImplementationFile=SetClockTime.cpp
BaseClass=CDialog
Filter=D
LastObject=CSetClockTime
VirtualFilter=dWC

[CLS:CSetOffCmpTime]
Type=0
HeaderFile=SetOffCmpTime.h
ImplementationFile=SetOffCmpTime.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_RADIO_ONE
VirtualFilter=dWC

[CLS:CMediaClass]
Type=0
HeaderFile=MediaClass.h
ImplementationFile=MediaClass.cpp
BaseClass=CWinThread
Filter=N

[DLG:IDD_ABOUTBOX (Chinese (P.R.C.))]
Type=1
Class=?
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_CLOCK_DIALOG (Chinese (P.R.C.))]
Type=1
Class=?
ControlCount=13
Control1=IDC_STATIC,static,1342308352
Control2=IDC_BUT_SET_CLOCKTIME,button,1342242816
Control3=IDC_BUT_OPEN_TELLTIME,button,1342242816
Control4=IDC_BUT_OFF_COMPUTER,button,1342242816
Control5=IDC_STATIC,static,1342308352
Control6=IDC_SHOW_TIME,static,1342308352
Control7=IDC_LIST_SHOWCLOCK,SysListView32,1350631425
Control8=IDC_LIST_SHOWOFFCOM,SysListView32,1350631425
Control9=IDC_STATIC,static,1342308352
Control10=IDC_BUT_DELETEITEM,button,1342242816
Control11=IDC_BUT_DEL_ITEM,button,1342242816
Control12=IDC_BUT_UPDATA,button,1073807360
Control13=IDC_BUT_UPDATA_COM,button,1073807360

[DLG:IDD_DIALOG1 (Chinese (P.R.C.))]
Type=1
Class=?
ControlCount=19
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_COM_SEL_HOUR,combobox,1344339970
Control5=IDC_STATIC,static,1342308352
Control6=IDC_COM_SEL_MINUTE,combobox,1344339970
Control7=IDC_STATIC,static,1342308352
Control8=IDC_COM_SEL_MUSIC,combobox,1344339970
Control9=IDC_BUT_FIND,button,1342242816
Control10=IDC_BUT_TRYLISTEN,button,1342242816
Control11=IDC_BUT_STOPMUSIC,button,1342242816
Control12=IDC_EDIT_TELLWORD,edit,1350631552
Control13=IDC_STATIC,button,1342177287
Control14=IDC_COM_SEL_DATA,combobox,1344339970
Control15=IDC_BUT_ADDTIME,button,1342242816
Control16=IDC_STATIC,static,1342308352
Control17=IDC_RADIO_ONE,button,1342308361
Control18=IDC_RADIO_ALL,button,1342177289
Control19=IDC_STATIC,static,1342308352

[DLG:IDD_DIALOG2 (Chinese (P.R.C.))]
Type=1
Class=?
ControlCount=15
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_COM_SEL_HOUR,combobox,1344340226
Control4=IDC_STATIC,static,1342308352
Control5=IDC_COM_SEL_MINUTE,combobox,1344340226
Control6=IDC_STATIC,static,1342308352
Control7=IDC_COM_SEL_SECOND,combobox,1344340226
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352
Control10=IDC_EDIT_TELL_WORD,edit,1350631552
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC,button,1342177287
Control13=IDC_RADIO_ONE,button,1342308361
Control14=IDC_RADIO_ALL,button,1342177289
Control15=IDC_BUT_ADD_OFFTIME,button,1342242816

