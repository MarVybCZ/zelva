#if !defined(AFX_BARVY_H__6F8E0078_4B57_442B_8384_7AD67E5C1A0F__INCLUDED_)
#define AFX_BARVY_H__6F8E0078_4B57_442B_8384_7AD67E5C1A0F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Barvy.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CBarvy dialog

class CBarvy : public CDialog
{
// Construction
public:
	CBarvy(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CBarvy)
	enum { IDD = IDD_Barvy };
	float	m_Blue;
	float	m_Green;
	float	m_Red;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBarvy)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CBarvy)
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BARVY_H__6F8E0078_4B57_442B_8384_7AD67E5C1A0F__INCLUDED_)
