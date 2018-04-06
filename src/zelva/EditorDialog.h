#if !defined(AFX_EDITORDIALOG_H__DAAEAB63_E78C_4CC4_94FB_52190AADD260__INCLUDED_)
#define AFX_EDITORDIALOG_H__DAAEAB63_E78C_4CC4_94FB_52190AADD260__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// EditorDialog.h : header file
//

#include "SpecFileDlg.h"
#include "MyInter.h"

#define WM_GOODBYE WM_USER + 5

/////////////////////////////////////////////////////////////////////////////
// CEditorDialog dialog

class CEditorDialog : public CDialog
{
// Construction
public:
	bool Change;
	bool IsRunAble(CString text);
	struct OpLib
	{
		CString Cesta;
		CString Nazev;
	//protected:
		//CString StrLine;
	} OpenLib, InterLib;//cesta k aktualne otevrene knihovne/souboru

	CMyInter *interpret;
	void FillRichEdit(CString *Parent,CString *Child);
	void ReloadTree();
	bool Create();
	CEditorDialog(CWnd* pParent = NULL, CMyInter *inter = NULL);   // standard constructor
//	CEditorDialog(CView *pView, CMyInter *inter);
	CImageList m_ImageList;
// Dialog Data
	//{{AFX_DATA(CEditorDialog)
	enum { IDD = IDD_EditorDialog };
	CRichEditCtrl	m_REControl;
	CTreeCtrl	m_TreeControl;
	CString	m_REString;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEditorDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	bool modif;
	void Modify();
	void Save(CString *cesta);
	//cesta k aktualne otevrene knihovne/souboru
//	CString strOpenLib;

	// Generated message map functions
	//{{AFX_MSG(CEditorDialog)
	afx_msg void OnDblclkTree(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnReturnRichEdit(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnFileOpen();
	afx_msg void OnClose();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnFMLoad();
	afx_msg void OnFMSave();
	afx_msg void OnFMUnLoad();
	afx_msg void OnMsgfilterRichEdit(NMHDR* pNMHDR, LRESULT* pResult);
	virtual BOOL OnInitDialog();
	afx_msg void OnFMOpen();
	afx_msg void OnFileSave();
	afx_msg void OnFileSaveAs();
	afx_msg void OnFileNew();
	afx_msg void OnEditCopy();
	afx_msg void OnEditCut();
	afx_msg void OnEditPaste();
	afx_msg void OnEditUndo();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);	
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CView *m_pView;
	

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EDITORDIALOG_H__DAAEAB63_E78C_4CC4_94FB_52190AADD260__INCLUDED_)
