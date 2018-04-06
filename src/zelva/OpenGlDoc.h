// OpenGlDoc.h : interface of the COpenGlDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OPENGLDOC_H__44FE9497_E1D0_4F22_9BBB_DE4FEFB06CAC__INCLUDED_)
#define AFX_OPENGLDOC_H__44FE9497_E1D0_4F22_9BBB_DE4FEFB06CAC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class COpenGlDoc : public CDocument
{
protected: // create from serialization only
	COpenGlDoc();
	DECLARE_DYNCREATE(COpenGlDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COpenGlDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~COpenGlDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(COpenGlDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OPENGLDOC_H__44FE9497_E1D0_4F22_9BBB_DE4FEFB06CAC__INCLUDED_)
