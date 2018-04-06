// EditorDialog.cpp : implementation file
//

#include "stdafx.h"
#include "OpenGl.h"
#include "EditorDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEditorDialog dialog


CEditorDialog::CEditorDialog(CWnd* pParent /*=NULL*/, CMyInter *inter)
	: CDialog(CEditorDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEditorDialog)
	m_REString = _T("");
	//}}AFX_DATA_INIT
	interpret = inter;	
	Change = false;
	AfxInitRichEdit();	
}

/*CEditorDialog::CEditorDialog(CView *pView, CMyInter *inter)
{
	m_pView = pView;
	interpret = inter;	
	Change = false;
	AfxInitRichEdit();		
}*/

void CEditorDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEditorDialog)
	DDX_Control(pDX, IDC_RichEdit, m_REControl);
	DDX_Control(pDX, IDC_TREE, m_TreeControl);
	DDX_Text(pDX, IDC_RichEdit, m_REString);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CEditorDialog, CDialog)
	//{{AFX_MSG_MAP(CEditorDialog)
	ON_NOTIFY(NM_DBLCLK, IDC_TREE, OnDblclkTree)
	ON_NOTIFY(NM_RETURN, IDC_RichEdit, OnReturnRichEdit)
	ON_COMMAND(ID_FILE_OPEN, OnFileOpen)
	ON_WM_CLOSE()
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_FMLoad, OnFMLoad)
	ON_COMMAND(ID_FMSave, OnFMSave)
	ON_COMMAND(ID_FMUnLoad, OnFMUnLoad)
	ON_NOTIFY(EN_MSGFILTER, IDC_RichEdit, OnMsgfilterRichEdit)
	ON_COMMAND(ID_FMOpen, OnFMOpen)
	ON_COMMAND(ID_FILE_SAVE, OnFileSave)
	ON_COMMAND(ID_FILE_SAVE_AS, OnFileSaveAs)
	ON_COMMAND(ID_FILE_NEW, OnFileNew)
	ON_COMMAND(ID_EDIT_COPY, OnEditCopy)
	ON_COMMAND(ID_EDIT_CUT, OnEditCut)
	ON_COMMAND(ID_EDIT_PASTE, OnEditPaste)
	ON_COMMAND(ID_EDIT_UNDO, OnEditUndo)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEditorDialog message handlers

bool CEditorDialog::Create()
{	
	int x;
	//CDialog::CreateEx(WS_EX_OVERLAPPEDWINDOW, CEditorDialog, Editor,

	x = CDialog::Create(CEditorDialog::IDD);


	modif = false;
	m_TreeControl.SetImageList(&m_ImageList,TVSIL_NORMAL);
	ReloadTree();
	return x;
	
}

/********************************************************************
Reloadne stromovou strukturu knihoven	
	return	: void 
********************************************************************/
void CEditorDialog::ReloadTree()
{	
	HTREEITEM treetem;
	m_TreeControl.DeleteAllItems();
	CString text;


	text = interpret->GetLibName(0);

	for(int i = 0; !text.IsEmpty(); i++)
	{
		if(!text.IsEmpty())
		{
			treetem = m_TreeControl.InsertItem(text,1,1);	

			for(int j = 0;!text.IsEmpty(); j++)
			{
				text = interpret->GetComName(i,j);
				if(!text.IsEmpty())
				{
					if(IsRunAble(text))
					{					
						m_TreeControl.InsertItem(text,3,3,treetem,TVI_SORT);
					}
					else
					{
						m_TreeControl.InsertItem(text,2,2,treetem,TVI_SORT);
					}
						
				}
			}
		}
		text = interpret->GetLibName(i+1);
	}
}

/********************************************************************
Prida danou knihovnu do stromove struktury
	lib		: int - index dane knihovny v poli knihoven
	return	: void 
********************************************************************/
//DEL void CEditorDialog::AddLibToTree(int lib)
//DEL {
//DEL 	CString text;
//DEL 
//DEL 	HTREEITEM treetem;	
//DEL 
//DEL 	text = interpret->GetLibName(lib);
//DEL 
//DEL 	treetem = m_TreeControl.InsertItem(text,1,0);
//DEL 		
//DEL 	for(int j = 0; !text.IsEmpty(); j++)
//DEL 	{
//DEL 		text = interpret->GetComName(lib,j);
//DEL 		m_TreeControl.InsertItem(text,2,2,treetem,TVI_SORT);
//DEL 	}
//DEL }

void CEditorDialog::OnDblclkTree(NMHDR* pNMHDR, LRESULT* pResult) 
{
	HTREEITEM Item;	

	CString ItemString;

	Item = m_TreeControl.GetSelectedItem();

	if(!Item) return;

	ItemString = m_TreeControl.GetItemText(Item);

	if(IsRunAble(ItemString))
	{
		BeginWaitCursor();
		interpret->ZpracujPrikaz(ItemString,0);
		EndWaitCursor();
	}
	Change = true;

	*pResult = 0;
}

/********************************************************************
Vlozi text do richeditu
	Parent	: CString - jmeno rodicovskeho prvku ze stromu, 
			ekvivalentni jmenu knihovny
	Child	: CString - jmeno detskeho prvku ze stromu, ekvivalentni
			jmenu prikazu
	return	: void 
********************************************************************/
void CEditorDialog::FillRichEdit(CString *Parent, CString *Child)
{	
	CString message;
	FILE *soubor;
	char znak;
	int pos=0;
	bool Acess;
	int index=-1;
	int id;
	
	m_REControl.LineScroll(0);

	index = interpret->FindLib(*Parent);	
	
	if(index<0) return; //nebyla nalezena knihovna

	InterLib.Nazev = interpret->GetLibName(index);

	InterLib.Cesta = interpret->GetLibPath(index);
	
	/*if(Child) //byl otevren prikaz
	{		
		pos = interpret->GetFilePos(*Child,*Parent);
	}*/	

	if(InterLib.Cesta == OpenLib.Cesta) //knihovna je jiz otevrena
	{
		id = AfxMessageBox("Knihovna je jiz otevrena\n prejete si ji reloadnout?",MB_YESNO);
		if(id==IDNO) return;		
	}

	//if(m_REControl.GetModify())
	if(modif)
	{
		id = AfxMessageBox("Text byl zmenen,\n prejete si ho ulozit?",MB_YESNO);
		if(id==IDYES)
		{
			Save(&OpenLib.Cesta);
		/*	interpret->Interpret->UnLoad(OpenLib.Cesta);
			interpret->Interpret->LoadFile(OpenLib.Cesta);			*/
			interpret->ReLoad(OpenLib.Cesta, true);
		}
	}
	m_REControl.SetModify(FALSE);
	modif = false;

	bool x = m_REControl.GetModify();

	//if((soubor  = fopen_s( InterLib.Cesta, "r" )) == NULL )
	if ((fopen_s(&soubor, InterLib.Cesta, "r")) != NULL)
	{
		message="The file '"+ InterLib.Cesta + "' was not opened.";
		Acess = false;
		AfxMessageBox( message,MB_OK, 0);
	}
	else
	{
		message="The file '"+ InterLib.Cesta + "' was opened.";
		Acess = true;
	}
	

	if(Acess)
	{
		m_REString.Empty();
		while(!feof(soubor))
		{
			znak = fgetc(soubor);
			if(!feof(soubor))
			m_REString.Insert(m_REString.GetLength(),znak);			
			
		}
		fclose(soubor);
		OpenLib.Cesta = InterLib.Cesta;
		OpenLib.Nazev = InterLib.Nazev;

		/*interpret->Interpret->UnLoad(*OpenLib.Cesta);
		interpret->Interpret->LoadFile(*OpenLib.Cesta);*/
		interpret->ReLoad(*OpenLib.Cesta,true);

		m_REControl.SetWindowText(m_REString);

		if(Child)
		{
			int xxx = 0;
			int z = Child->Find('(',0);
			if(z!=-1)
			{
				Child->Delete(z,Child->GetLength()-z);
			}
			
			int k = 0;

			for(int i = 0;i<m_REString.GetLength();i++)
			{
				if(m_REString[i]=='\n')
					k++;

				xxx = m_REString.Find("define",i);
				if(xxx!=-1)
				{					
					int mez = m_REString.Find('\n',xxx);
					xxx = m_REString.Find(*Child,xxx);
					if((xxx!=-1)&&(xxx<mez))
						pos = k;
				}
			}
		}
		m_REControl.LineScroll(pos);
	//	m_REControl.SetSel(20,50);
	}		
}



void CEditorDialog::OnReturnRichEdit(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	
	*pResult = 0;
}



void CEditorDialog::OnFileOpen() 
{
	// TODO: Add your command handler code here
	CString File;
 	static char BASED_CODE szFilter[] = "Textove soubory(*.txt)|*.txt|Zelvi Files (*.trt)|*.trt|All Files (*.*)|*.*||"; 
 	CSpecFileDlg dlgFile(TRUE,NULL,"*.txt",OFN_FILEMUSTEXIST,szFilter);
 	int nModal = dlgFile.DoModal();
 	if (nModal == IDOK)  File = dlgFile.GetPathName();
 	if(!File.IsEmpty())
	{
 		interpret->ReLoad(File,2);
		ReloadTree();
	}	
}

void CEditorDialog::OnClose() 
{
	Modify();
	ShowWindow(SW_HIDE);
	/*m_REString.Empty();	
	OpenLib.Cesta.Empty();
	OpenLib.Nazev.Empty();

	m_TreeControl.DeleteAllItems();
	m_ImageList.DeleteImageList();
	CEditorDialog::DestroyWindow();
	CDialog::OnClose();*/
}

void CEditorDialog::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	// TODO: Add your message handler code here
	CMenu menu;	
	if (menu.LoadMenu(IDR_FileMenu))
	{			
		menu.GetSubMenu(0)->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, this);
	}
}

void CEditorDialog::OnFMLoad() 
{
	HTREEITEM Item;
	HTREEITEM ItemParent;

	CString ItemString, ItemParStr;

	Item = m_TreeControl.GetSelectedItem();

	if(!Item) return;

	ItemString = m_TreeControl.GetItemText(Item);
	ItemParent = m_TreeControl.GetParentItem(Item);

	if(ItemParent)
	{
		ItemParStr = m_TreeControl.GetItemText(ItemParent);
		FillRichEdit(&ItemParStr,&ItemString);
	}
	else
	{
		FillRichEdit(&ItemString,NULL);		
	}

//	UpdateData(FALSE);	
}

void CEditorDialog::OnFMSave() 
{
	// TODO: Add your command handler code here
	if(!OpenLib.Nazev.IsEmpty())
	Save(&OpenLib.Cesta);
	else OnFileSaveAs();
}

void CEditorDialog::OnFMUnLoad() 
{
	HTREEITEM Item;
	HTREEITEM ItemParent;

	CString ItemString, ItemParStr;

	Item = m_TreeControl.GetSelectedItem();

	if(!Item) return;

	ItemString = m_TreeControl.GetItemText(Item);
	ItemParent = m_TreeControl.GetParentItem(Item);

	
	if(ItemParent)
	{
		ItemParStr = m_TreeControl.GetItemText(ItemParent);

		m_TreeControl.DeleteItem(ItemParent);

		//interpret->UnLoad(ItemParStr);
		interpret->ReLoad(ItemParStr, false);

		if(ItemParStr==OpenLib.Nazev)
		{
			Modify();
			OpenLib.Nazev.Empty();
			OpenLib.Cesta.Empty();
			m_REString.Empty();
			m_REControl.SetWindowText(m_REString);
		}
	}
	else
	{
		m_TreeControl.DeleteItem(Item);
		//interpret->Interpret->UnLoad(ItemString);
		interpret->ReLoad(ItemString,false);


		if(ItemString==OpenLib.Nazev)
		{
			Modify();
			OpenLib.Nazev.Empty();
			OpenLib.Cesta.Empty();
			m_REString.Empty();
			m_REControl.SetWindowText(m_REString);
		}
	}	
}

void CEditorDialog::OnMsgfilterRichEdit(NMHDR* pNMHDR, LRESULT* pResult) 
{
	CString ret;
	MSGFILTER *pMsgFilter = reinterpret_cast<MSGFILTER *>(pNMHDR);
	// TODO: The control will not send this notification unless you override the
	// CDialog::OnInitDialog() function to send the EM_SETEVENTMASK message
	// to the control with either the ENM_KEYEVENTS or ENM_MOUSEEVENTS flag 
	// ORed into the lParam mask.
	
	// TODO: Add your control notification handler code here
	if((pMsgFilter->wParam>=20)&&(pMsgFilter->wParam<=127))
	{
		m_REControl.SetModify(TRUE);
		modif = true;
	}
	
}

BOOL CEditorDialog::OnInitDialog() 
{	
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_ImageList.Create(16,16,0,2,2);

	HICON hIcon[4];
	hIcon[0] = AfxGetApp()->LoadIcon(IDI_OpenNode);
	hIcon[1] = AfxGetApp()->LoadIcon(IDI_CloseNode);
	hIcon[2] = AfxGetApp()->LoadIcon(IDI_Comm);
	hIcon[3] = AfxGetApp()->LoadIcon(IDI_RunComm);
	m_ImageList.Add(hIcon[0]);
	m_ImageList.Add(hIcon[1]);
	m_ImageList.Add(hIcon[2]);
	m_ImageList.Add(hIcon[3]);

	m_REControl.SetEventMask(ENM_KEYEVENTS|ENM_CHANGE);
	m_TreeControl.DragAcceptFiles();	
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CEditorDialog::OnFMOpen() 
{
	// TODO: Add your command handler code here
	OnFileOpen();
}

void CEditorDialog::Save(CString *cesta)
{
	CString ret;
	FILE *soub;
	CString message;
	m_REControl.GetWindowText(ret);	
	
 	//if((soub  = fopen_s( *cesta, "w" )) == NULL )
	if ((fopen_s(&soub, *cesta, "w")) != NULL)
 	{
 		message="The file '"+ *cesta + "' was not opened.";
 		AfxMessageBox( message,MB_OK, 0);
 		return;
 	}
 	m_REControl.SetModify(FALSE);
 	modif = false;

	
 	fputs(ret,soub);
 	fclose(soub);
	/*interpret->Interpret->UnLoad(*cesta);
	interpret->Interpret->LoadFile(*cesta);*/
	interpret->ReLoad(*cesta, true);
	m_TreeControl.DeleteAllItems();
	ReloadTree();
}

void CEditorDialog::OnFileSave() 
{	
 	// TODO: Add your command handler code here
	if(!OpenLib.Nazev.IsEmpty())
	Save(&OpenLib.Cesta);
	else OnFileSaveAs();
}

void CEditorDialog::OnFileSaveAs() 
{
	// TODO: Add your command handler code here
	CString File;
 	static char BASED_CODE szFilter[] = "Textove soubory(*.txt)|*.txt|Zelvi Files (*.trt)|*.trt|All Files (*.*)|*.*||"; 
 	CSpecFileDlg dlgFile(FALSE,NULL,"*.txt",OFN_OVERWRITEPROMPT,szFilter);
 	int nModal = dlgFile.DoModal();
 	if (nModal == IDOK)  File = dlgFile.GetPathName();
 	if(!File.IsEmpty())
 	Save(&File);
}

void CEditorDialog::OnFileNew() 
{
	int id;

	//if(m_REControl.GetModify())
	if(modif)
	{
		id = AfxMessageBox("Text byl zmenen,\n prejete si ho ulozit?",MB_YESNO);
		if(id==IDYES)
		{
			Save(&OpenLib.Cesta);
			/*interpret->Interpret->UnLoad(OpenLib.Cesta);
			interpret->Interpret->LoadFile(OpenLib.Cesta);			*/
			interpret->ReLoad(OpenLib.Cesta,true);
		}
	}
	m_REControl.SetModify(FALSE);
	modif = false;
	m_REString.Empty();
	m_REControl.SetWindowText(m_REString);
	OpenLib.Cesta.Empty();
	OpenLib.Nazev.Empty();
}

void CEditorDialog::OnEditCopy() 
{
	// TODO: Add your command handler code here
	m_REControl.Copy();
}

void CEditorDialog::OnEditCut() 
{
	// TODO: Add your command handler code here
	m_REControl.Cut();
}

void CEditorDialog::OnEditPaste() 
{
	// TODO: Add your command handler code here
	m_REControl.Paste();
}

void CEditorDialog::OnEditUndo() 
{
	// TODO: Add your command handler code here
	m_REControl.Undo();
}

void CEditorDialog::Modify()
{
	int id;

	bool x;
	x = m_REControl.GetModify(); 
	
	//if(m_REControl.GetModify())
	if(modif)
	{
		id = AfxMessageBox("Text byl zmenen,\n prejete si ho ulozit?",MB_YESNO);
		if(id==IDYES)
		{
			Save(&OpenLib.Cesta);			
		}
	}
	m_REControl.SetModify(FALSE);
	modif = false;
}

//DEL void CEditorDialog::OnChangeRichEdit() 
//DEL {
//DEL 	// TODO: If this is a RICHEDIT control, the control will not
//DEL 	// send this notification unless you override the CDialog::OnInitDialog()
//DEL 	// function and call CRichEditCtrl().SetEventMask()
//DEL 	// with the ENM_CHANGE flag ORed into the mask.
//DEL 	
//DEL 	// TODO: Add your control notification handler code here
//DEL /*	m_REControl.SetModify(TRUE);
//DEL 	modif = true;	*/
//DEL }




int CEditorDialog::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	
	return 0;
}

bool CEditorDialog::IsRunAble(CString text)
{
	if((text[text.GetLength()-1]==')')&&(text[text.GetLength()-2]=='('))
		return true;
	else return false;
}

void CEditorDialog::OnDestroy() 
{
	CDialog::OnDestroy();
	
	// TODO: Add your message handler code here
	m_REString.Empty();	
	OpenLib.Cesta.Empty();
	OpenLib.Nazev.Empty();

	m_TreeControl.DeleteAllItems();
	m_ImageList.DeleteImageList();	
	m_REString.Empty();
	m_REControl.DestroyWindow();
	m_TreeControl.DestroyWindow();
}
