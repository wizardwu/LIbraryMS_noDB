; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CLibraryDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Library.h"

ClassCount=3
Class1=CLibraryApp
Class2=CLibraryDlg

ResourceCount=8
Resource1=IDR_MAINFRAME
Resource2=IDD_BORROW
Class3=CRegist
Resource3=IDD_LOGINED
Resource4=IDD_LIBRARY_DIALOG
Resource5=IDD_BOOKQUERY
Resource6=IDD_REGIST
Resource7=IDD_SHOWBOOK
Resource8=IDD_BOOKIN

[CLS:CLibraryApp]
Type=0
HeaderFile=Library.h
ImplementationFile=Library.cpp
Filter=N
BaseClass=CWinApp
VirtualFilter=AC
LastObject=CLibraryApp

[CLS:CLibraryDlg]
Type=0
HeaderFile=LibraryDlg.h
ImplementationFile=LibraryDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CLibraryDlg



[DLG:IDD_LIBRARY_DIALOG]
Type=1
Class=CLibraryDlg
ControlCount=12
Control1=IDC_LOGIN,button,1342242816
Control2=IDC_USERNAME,edit,1350631552
Control3=IDC_PASSWORD,edit,1350631584
Control4=IDC_STATIC1,static,1342308866
Control5=IDC_STATIC2,static,1342308866
Control6=IDC_REGIST,button,1342242816
Control7=IDC_BOOK,button,1342242816
Control8=IDC_QUERY,button,1342242816
Control9=IDC_USER,button,1342242816
Control10=IDC_BACK,button,1342242816
Control11=IDC_STATIC0,button,1342177287
Control12=IDC_EXIT,button,1342242816

[DLG:IDD_REGIST]
Type=1
Class=CRegist
ControlCount=10
Control1=IDC_STATIC,static,1342308866
Control2=IDC_STATIC,static,1342308866
Control3=IDC_STATIC,static,1342308866
Control4=IDC_REGIST_UNAME,edit,1350631552
Control5=IDC_REGIST_PWD,edit,1350631584
Control6=IDC_REGIST_PWD_REP,edit,1350631584
Control7=IDC_STATIC,static,1342308866
Control8=IDC_REGIST_SUBMIT,button,1342242816
Control9=IDC_REGIST_CLEAR,button,1342242816
Control10=IDC_REGIST_UTYPE,combobox,1342243075

[CLS:CRegist]
Type=0
HeaderFile=Regist.h
ImplementationFile=Regist.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CRegist

[DLG:IDD_BORROW]
Type=1
Class=?
ControlCount=7
Control1=IDC_STATIC,static,1342308865
Control2=IDC_STATIC,static,1342308865
Control3=IDC_BORROWCARDID,edit,1350631552
Control4=IDC_BORROWBOOKID,edit,1350631552
Control5=IDC_BORROWQUERY,button,1342242816
Control6=IDC_BORROWSUBMIT,button,1342242816
Control7=IDC_BORROWEXIT,button,1342242816

[DLG:IDD_SHOWBOOK]
Type=1
Class=?
ControlCount=1
Control1=IDC_LISTBOOK,SysListView32,1350664193

[DLG:IDD_BOOKQUERY]
Type=1
Class=?
ControlCount=15
Control1=IDC_NAMEQUERY,button,1342242817
Control2=IDC_WORD1,edit,1350631552
Control3=IDC_STATIC,button,1342177287
Control4=IDC_STATIC,button,1342177287
Control5=IDC_STATIC,static,1342308865
Control6=IDC_STATIC,static,1342308865
Control7=IDC_STATIC,static,1342308865
Control8=IDC_KEY1,edit,1350631552
Control9=IDC_KEY2,edit,1350631552
Control10=IDC_KEY3,edit,1350631552
Control11=IDC_KEYQUERY,button,1342242816
Control12=IDC_QUERYCLEAR,button,1342242816
Control13=IDC_CANCEL,button,1342242816
Control14=IDC_WORD,combobox,1344340227
Control15=IDC_WORD2,edit,1350631552

[DLG:IDD_BOOKIN]
Type=1
Class=?
ControlCount=21
Control1=IDC_STATIC,static,1342308865
Control2=IDC_STATIC,static,1342308865
Control3=IDC_STATIC,static,1342308866
Control4=IDC_STATIC,static,1342308865
Control5=IDC_INBOOKCATEGORY,edit,1350631552
Control6=IDC_INBOOKNAME,edit,1350631552
Control7=IDC_INBOOKPUBYEAR,edit,1350631552
Control8=IDC_INBOOKPRICE,edit,1350631552
Control9=IDC_STATIC,static,1342308865
Control10=IDC_STATIC,static,1342308866
Control11=IDC_STATIC,static,1342308866
Control12=IDC_INBOOKPRESS,edit,1350631552
Control13=IDC_INBOOKID,edit,1350631552
Control14=IDC_INBOOKAUTHOR,edit,1350631552
Control15=IDC_STATIC,static,1342308866
Control16=IDC_INBOOKNUM,edit,1350631552
Control17=IDC_SINGLESUBMIT,button,1342242816
Control18=IDC_BOOKINEXIT,button,1342242816
Control19=IDC_BOOKCLEAR,button,1342242816
Control20=IDC_STATIC,button,1342177287
Control21=IDC_BOOKRUSH,button,1342242816

[DLG:IDD_LOGINED]
Type=1
Class=?
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816

