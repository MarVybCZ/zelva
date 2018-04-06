// Barvy.cpp : implementation file
//

#include "stdafx.h"
#include "OpenGl.h"
#include "Barvy.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBarvy dialog


CBarvy::CBarvy(CWnd* pParent /*=NULL*/)
	: CDialog(CBarvy::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBarvy)
	m_Blue = 0.0f;
	m_Green = 0.0f;
	m_Red = 0.0f;
	//}}AFX_DATA_INIT
}


void CBarvy::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBarvy)
	DDX_Text(pDX, IDC_Blue, m_Blue);
	DDV_MinMaxFloat(pDX, m_Blue, 0.f, 1.f);
	DDX_Text(pDX, IDC_Green, m_Green);
	DDV_MinMaxFloat(pDX, m_Green, 0.f, 1.f);
	DDX_Text(pDX, IDC_Red, m_Red);
	DDV_MinMaxFloat(pDX, m_Red, 0.f, 1.f);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CBarvy, CDialog)
	//{{AFX_MSG_MAP(CBarvy)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBarvy message handlers

void CBarvy::OnOK() 
{
	// TODO: Add extra validation here
	
	CDialog::OnOK();
	UpdateData(TRUE);
}

void CBarvy::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}
