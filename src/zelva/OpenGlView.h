// OpenGlView.h : interface of the COpenGlView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OPENGLVIEW_H__2651CC1C_24CC_45C3_A6E0_0A78956CAE9C__INCLUDED_)
#define AFX_OPENGLVIEW_H__2651CC1C_24CC_45C3_A6E0_0A78956CAE9C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "COMMANDLINE.h"
#include "EditorDialog.h"
#include "Barvy.h"
#include "MyInter.h"




class COpenGlView : public CView
{
protected: // create from serialization only
	COpenGlView();
	DECLARE_DYNCREATE(COpenGlView)

	// Attributes
public:
	COpenGlDoc * GetDocument();

	// Operations
public:

	// Overrides
		// ClassWizard generated virtual function overrides
		//{{AFX_VIRTUAL(COpenGlView)
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
public:
	void ShowHideDlg(UINT x);
	CString FileDlg();
	CString GetData(int *index, CString in);
	void CreateSL();
	void CreateSceneList();
	CMyInter *Interpret;

	void RenderGl();

	CPtrArray MatrixHist;

	int m_sceneList;
	float *matrix;

	void Kriz();
	void SetupLighting();
	HGLRC m_hRC; //Rendering Context
	CDC* m_pDC; //Device Context

	GLfloat m_xAngle, m_yAngle, m_xPos, m_yPos;
	CPoint m_MouseDownPoint;

	//HGLRC is a 'Handle to a Rendering Context' and we need to obtain a valid rendering context from a Windows Device context which is 

	BOOL InitializeOpenGL();

	BOOL SetupPixelFormat();

	void RenderScene();

	CCOMMANDLINE *m_pDlg;
	CEditorDialog *m_pEditorDlg;


	virtual ~COpenGlView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	GLUquadricObj * obj;
	GLfloat zoom;
	GLfloat RGBkriz[3];

	// Generated message map functions
protected:
	void Cone(float rx, float ry, float rz, float x, float y, float z);
	//{{AFX_MSG(COpenGlView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnPrikazovaradka();
	afx_msg void OnEditor();
	afx_msg void OnBarPoz();
	afx_msg void OnBarKriz();
	afx_msg void OnExportEPS();
	afx_msg void OnExternEps();
	//}}AFX_MSG
	afx_msg LRESULT OnGoodbye(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()

private:

};

#ifndef _DEBUG  // debug version in OpenGlView.cpp
inline COpenGlDoc* COpenGlView::GetDocument()
{
	return (COpenGlDoc*)m_pDocument;
}
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OPENGLVIEW_H__2651CC1C_24CC_45C3_A6E0_0A78956CAE9C__INCLUDED_)
