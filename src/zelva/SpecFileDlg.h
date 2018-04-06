#if !defined(AFX_SPECFILEDLG_H__7569C7E7_8426_4463_B82C_C150FFCA6DB8__INCLUDED_)
#define AFX_SPECFILEDLG_H__7569C7E7_8426_4463_B82C_C150FFCA6DB8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SpecFileDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSpecFileDlg dialog

class CSpecFileDlg : public CFileDialog
{
// Construction
public:

	CSpecFileDlg(BOOL bOpenFileDialog,
		LPCTSTR lpszDefExt = NULL,
		LPCTSTR lpszFilename = NULL,
		DWORD dwFlags = OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT | OFN_FILEMUSTEXIST,
		LPCTSTR lpszFilter = NULL,
		CWnd* pParent = NULL);   // standard constructor

	CString m_strFileName;

// Dialog Data
	//{{AFX_DATA(CSpecFileDlg)
	enum { IDD = IDD_FILESPECIAL };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSpecFileDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSpecFileDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SPECFILEDLG_H__7569C7E7_8426_4463_B82C_C150FFCA6DB8__INCLUDED_)
