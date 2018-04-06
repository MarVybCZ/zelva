// MyInter.cpp: implementation of the CMyInter class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "OpenGl.h"
#include "MyInter.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMyInter::CMyInter()
{
	AfxOleInit();	
	interpret = new IInter;
	interpret->CreateDispatch("InterCom.Interface");
}

CMyInter::~CMyInter()
{
	interpret->ReleaseDispatch();
	delete interpret;
}

CString CMyInter::GetLibName(int x)
{
	CString name;
	name = interpret->GetLibName(x);
	return name;
}

CString CMyInter::ZpracujPrikaz(CString ret, int x)
{		
	interpret->ZpracujPrikaz(ret, x);
	return "xxx";
}

CString CMyInter::GetComName(int i, int j)
{
	CString name;
	name = interpret->GetComName(i,j);
	return name;
}

int CMyInter::FindLib(CString name)
{		
	CString pom;	
	pom = interpret->GetLibName(0);
	for(int i = 1; !pom.IsEmpty();i++)
	{
		if(pom==name) return i-1;

		pom = interpret->GetLibName(i);		
	}
	return -1;	
}

/***********************************************************************
kdyz je xx 1 provede unload, load;(true == 1)
kdyz je xx 0 provede unload
kdyz je xx 2 provede load
false provede pouze unload
***********************************************************************/
void CMyInter::ReLoad(CString cesta, int xx)
{
	if(xx == 1)
	{
		interpret->UnLoad(cesta);
		interpret->Load(cesta);
	}
	if(xx == 0)
		interpret->UnLoad(cesta);
	if(xx == 2)
		interpret->Load(cesta);

}

CString CMyInter::GetLibPath(int i)
{
	CString path;
	path = interpret->GetLibPath(i);
	return path;
}

//DEL CPtrArray *CMyInter::GetHistory()
//DEL {
//DEL 	return NULL;
//DEL }

bool CMyInter::GetPosChange()
{
	return interpret->GetPosChange();	
}

int CMyInter::GetHistLength()
{
	return interpret->GetHistLength();
}

CString CMyInter::GetPrvekData(int x)
{
	return interpret->GetPrvekData(x);
}

//DEL int CMyInter::GetFilePos(CString Child, CString Parent)
//DEL {
//DEL 	BSTR x,xx;
//DEL 
//DEL 	x = Child.AllocSysString();
//DEL 	xx = Parent.AllocSysString();
//DEL 
//DEL 	return interpret->GetFilePos(&x,&xx);
//DEL }
