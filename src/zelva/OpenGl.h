// OpenGl.h : main header file for the OPENGL application
//

#if !defined(AFX_OPENGL_H__59F6AAFB_12BE_428D_913E_66677519DB0D__INCLUDED_)
#define AFX_OPENGL_H__59F6AAFB_12BE_428D_913E_66677519DB0D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols
//#include "..\Editor\editor.h"
#include "COMMANDLINE.h"

/////////////////////////////////////////////////////////////////////////////
// COpenGlApp:
// See OpenGl.cpp for the implementation of this class
//

class COpenGlApp : public CWinApp
{
public:
	COpenGlApp();
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COpenGlApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(COpenGlApp)
	afx_msg void OnAppAbout();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OPENGL_H__59F6AAFB_12BE_428D_913E_66677519DB0D__INCLUDED_)
