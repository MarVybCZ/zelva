; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CEditorDialog
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "OpenGl.h"
LastPage=0

ClassCount=10
Class1=COpenGlApp
Class2=COpenGlDoc
Class3=COpenGlView
Class4=CMainFrame

ResourceCount=10
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDR_FileMenu
Resource4=IDD_Barvy
Class5=CAboutDlg
Class6=CCOMMANDLINE
Class7=MyOpen
Resource5=IDR_EditorMenu
Class8=CSpecFileDlg
Resource6=IDD_COMMAND_LINE
Class9=CEditorDialog
Resource7=IDD_FILESPECIAL
Resource8=IDD_ABOUTBOX (English (U.S.))
Resource9=IDD_EditorDialog
Class10=CBarvy
Resource10=IDR_MAINFRAME (English (U.S.))

[CLS:COpenGlApp]
Type=0
HeaderFile=OpenGl.h
ImplementationFile=OpenGl.cpp
Filter=W
BaseClass=CWinApp
VirtualFilter=AC

[CLS:COpenGlDoc]
Type=0
HeaderFile=OpenGlDoc.h
ImplementationFile=OpenGlDoc.cpp
Filter=N

[CLS:COpenGlView]
Type=0
HeaderFile=OpenGlView.h
ImplementationFile=OpenGlView.cpp
Filter=W
BaseClass=CView
VirtualFilter=VWC
LastObject=COpenGlView


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=CMainFrame
BaseClass=CFrameWnd
VirtualFilter=fWC




[CLS:CAboutDlg]
Type=0
HeaderFile=OpenGl.cpp
ImplementationFile=OpenGl.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Class=CAboutDlg

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_MRU_FILE1
Command6=ID_APP_EXIT
Command10=ID_EDIT_PASTE
Command11=ID_VIEW_TOOLBAR
Command12=ID_VIEW_STATUS_BAR
Command13=ID_APP_ABOUT
CommandCount=13
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command7=ID_EDIT_UNDO
Command8=ID_EDIT_CUT
Command9=ID_EDIT_COPY

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command5=ID_EDIT_CUT
Command6=ID_EDIT_COPY
Command7=ID_EDIT_PASTE
Command8=ID_EDIT_UNDO
Command9=ID_EDIT_CUT
Command10=ID_EDIT_COPY
Command11=ID_EDIT_PASTE
Command12=ID_NEXT_PANE
CommandCount=13
Command4=ID_EDIT_UNDO
Command13=ID_PREV_PANE


[TB:IDR_MAINFRAME (English (U.S.))]
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
CommandCount=8

[MNU:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=CMainFrame
Command1=ID_PRIKAZOVARADKA
Command2=ID_Editor
Command3=ID_BarPoz
Command4=ID_BarKriz
Command5=ExportEPS
Command6=ExternEps
CommandCount=6

[ACL:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_UNDO
Command5=ID_EDIT_CUT
Command6=ID_EDIT_COPY
Command7=ID_EDIT_PASTE
Command8=ID_EDIT_UNDO
Command9=ID_EDIT_CUT
Command10=ID_EDIT_COPY
Command11=ID_EDIT_PASTE
Command12=ID_NEXT_PANE
Command13=ID_PREV_PANE
CommandCount=13

[DLG:IDD_ABOUTBOX (English (U.S.))]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_COMMAND_LINE]
Type=1
Class=CCOMMANDLINE
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_LINE,edit,1350631552

[CLS:CCOMMANDLINE]
Type=0
HeaderFile=COMMANDLINE.h
ImplementationFile=COMMANDLINE.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_LINE

[CLS:MyOpen]
Type=0
HeaderFile=MyOpen.h
ImplementationFile=MyOpen.cpp
BaseClass=CFileDialog
Filter=D
LastObject=MyOpen

[DLG:IDD_FILESPECIAL]
Type=1
Class=CSpecFileDlg
ControlCount=1
Control1=stc32,button,1073741831

[CLS:CSpecFileDlg]
Type=0
HeaderFile=SpecFileDlg.h
ImplementationFile=SpecFileDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=stc32

[DLG:IDD_EditorDialog]
Type=1
Class=CEditorDialog
ControlCount=2
Control1=IDC_TREE,SysTreeView32,1350631463
Control2=IDC_RichEdit,RICHEDIT,1345401028

[CLS:CEditorDialog]
Type=0
HeaderFile=EditorDialog.h
ImplementationFile=EditorDialog.cpp
BaseClass=CDialog
Filter=D
LastObject=CEditorDialog
VirtualFilter=dWC

[MNU:IDR_EditorMenu]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_MRU_FILE1
Command6=ID_APP_EXIT
Command7=ID_EDIT_UNDO
Command8=ID_EDIT_CUT
Command9=ID_EDIT_COPY
Command10=ID_EDIT_PASTE
CommandCount=10

[MNU:IDR_FileMenu]
Type=1
Class=CEditorDialog
Command1=ID_FMOpen
Command2=ID_FMLoad
Command3=ID_FMSave
Command4=ID_FMUnLoad
CommandCount=4

[DLG:IDD_Barvy]
Type=1
Class=CBarvy
ControlCount=8
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_Blue,edit,1350631552
Control4=IDC_Green,edit,1350631552
Control5=IDC_Red,edit,1350631552
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352

[CLS:CBarvy]
Type=0
HeaderFile=Barvy.h
ImplementationFile=Barvy.cpp
BaseClass=CDialog
Filter=D
LastObject=IDOK
VirtualFilter=dWC

