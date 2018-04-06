#if !defined(AFX_COMMANDLINE_H__BF833A78_4645_49FD_A521_21D868498A44__INCLUDED_)
#define AFX_COMMANDLINE_H__BF833A78_4645_49FD_A521_21D868498A44__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// COMMANDLINE.h : header file
//
#include "MyInter.h"
#define WM_GOODBYE WM_USER + 5


/////////////////////////////////////////////////////////////////////////////
// CCOMMANDLINE dialog

class CCOMMANDLINE : public CDialog
{
// Construction
public:
	bool Change;
	CCOMMANDLINE(CWnd* pParent = NULL);   // standard constructor
	CCOMMANDLINE(CView *pView, CMyInter *inter);
	bool Create();
// Dialog Data
	//{{AFX_DATA(CCOMMANDLINE)
	enum { IDD = IDD_COMMAND_LINE };
	CString	m_retezec;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCOMMANDLINE)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCOMMANDLINE)
	virtual void OnCancel();
	virtual void OnOK();
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CView *m_pView;
	CMyInter *interpret;

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COMMANDLINE_H__BF833A78_4645_49FD_A521_21D868498A44__INCLUDED_)
