// SpecFileDlg.cpp : implementation file
//

#include "stdafx.h"
#include "OpenGl.h"
#include "SpecFileDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSpecFileDlg dialog


CSpecFileDlg::CSpecFileDlg(BOOL bOpenFileDialog,
		LPCTSTR lpszDefExt,	LPCTSTR lpszFilename, DWORD dwFlags,
		LPCTSTR lpszFilter,	CWnd* pParent)
	: CFileDialog(bOpenFileDialog,lpszDefExt,lpszFilename,
		dwFlags, lpszFilter, pParent)
{
	//{{AFX_DATA_INIT(CSpecFileDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_ofn.Flags |= OFN_ENABLETEMPLATE;
	m_ofn.lpTemplateName = MAKEINTRESOURCE(IDD_FILESPECIAL);
	m_ofn.lpstrTitle = "Otevreni Souboru";	
}


void CSpecFileDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSpecFileDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSpecFileDlg, CDialog)
	//{{AFX_MSG_MAP(CSpecFileDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSpecFileDlg message handlers
