// COMMANDLINE.cpp : implementation file
//

#include "stdafx.h"
#include "OpenGl.h"
#include "COMMANDLINE.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCOMMANDLINE dialog


CCOMMANDLINE::CCOMMANDLINE(CWnd* pParent /*=NULL*/)
	: CDialog(CCOMMANDLINE::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCOMMANDLINE)
	m_retezec = _T("");
	//}}AFX_DATA_INIT
	m_pView = NULL;
}

CCOMMANDLINE::CCOMMANDLINE(CView *pView, CMyInter *inter)
{	
	Change = false;
	m_pView = pView;
	interpret = inter;
}

void CCOMMANDLINE::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCOMMANDLINE)
	DDX_Text(pDX, IDC_LINE, m_retezec);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCOMMANDLINE, CDialog)
	//{{AFX_MSG_MAP(CCOMMANDLINE)
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCOMMANDLINE message handlers

void CCOMMANDLINE::OnCancel() 
{
	/*if(m_pView != NULL)
	{
		//m_pView->PostMessage(WM_GOODBYE,IDCANCEL);
		DestroyWindow();
	}*/
	
	CDialog::OnCancel();
	DestroyWindow();
}

void CCOMMANDLINE::OnOK() 
{
	m_retezec.Empty();
	if(m_pView != NULL)
	{
		UpdateData(true);
		BeginWaitCursor();
		interpret->ZpracujPrikaz(m_retezec,0);
		EndWaitCursor();
		m_retezec.Empty();
		UpdateData(false);	
		Change = true;
		InvalidateRect(NULL,FALSE);
	}
	else
	CDialog::OnOK();
}

bool CCOMMANDLINE::Create()
{
	return CDialog::Create(CCOMMANDLINE::IDD);
}

//DEL void CCOMMANDLINE::OnKillFocus(CWnd* pNewWnd) 
//DEL {
//DEL 	CDialog::OnKillFocus(pNewWnd);
//DEL 	
//DEL 	// TODO: Add your message handler code here
//DEL 	
//DEL }

//DEL void CCOMMANDLINE::OnCaptureChanged(CWnd *pWnd) 
//DEL {
//DEL 	// TODO: Add your message handler code here
//DEL 	
//DEL 	CDialog::OnCaptureChanged(pWnd);
//DEL }

void CCOMMANDLINE::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	DestroyWindow();	
	CDialog::OnClose();
}
