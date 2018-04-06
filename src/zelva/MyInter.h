// MyInter.h: interface for the CMyInter class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYINTER_H__1D38EECE_8843_40F2_81DD_CEFB45BF1A85__INCLUDED_)
#define AFX_MYINTER_H__1D38EECE_8843_40F2_81DD_CEFB45BF1A85__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "InterCom.h"

class CMyInter  
{
public:
	CString GetPrvekData(int x);
	int GetHistLength();
	bool GetPosChange();
	CString GetLibPath(int i);
	IInter *interpret;
		
	void ReLoad(CString cesta, int xx);
	int FindLib(CString name);
	CString GetComName(int i, int j);
	CString GetLibName(int i);
	CString ZpracujPrikaz(CString ret, int x);
	CMyInter();
	virtual ~CMyInter();
	

};

#endif // !defined(AFX_MYINTER_H__1D38EECE_8843_40F2_81DD_CEFB45BF1A85__INCLUDED_)
