// OpenGlDoc.cpp : implementation of the COpenGlDoc class
//

#include "stdafx.h"
#include "OpenGl.h"

#include "OpenGlDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COpenGlDoc

IMPLEMENT_DYNCREATE(COpenGlDoc, CDocument)

BEGIN_MESSAGE_MAP(COpenGlDoc, CDocument)
	//{{AFX_MSG_MAP(COpenGlDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COpenGlDoc construction/destruction

COpenGlDoc::COpenGlDoc()
{
	// TODO: add one-time construction code here

}

COpenGlDoc::~COpenGlDoc()
{
}

BOOL COpenGlDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// COpenGlDoc serialization

void COpenGlDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// COpenGlDoc diagnostics

#ifdef _DEBUG
void COpenGlDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void COpenGlDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// COpenGlDoc commands
