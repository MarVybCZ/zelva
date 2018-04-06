// Expression.h: interface for the CExpression class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_EXPRESSION_H__58013A7A_E5FA_4688_9B87_E15F263E6291__INCLUDED_)
#define AFX_EXPRESSION_H__58013A7A_E5FA_4688_9B87_E15F263E6291__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "defines.h"
#include "Prikazy.h"
#include "mapa.h"
#include <afx.h>
#include <afxtempl.h>

class CExpression  
{
public:	
	
/********************************************************************
vraci delku PoleParam - pole parametru	
	return	: int 
********************************************************************/
	int NumParLen();
	
	CString *Knihovna;
	CArray<CParametrs, CParametrs> PoleParam;
	CString Jmeno;
	CString Param; // parametry fce budto za mezerou nebo zavorkou	
	CExpression(CString ret, CPrikazy *prik = NULL);
	CExpression(CExpression &vyraz);
	virtual ~CExpression();
protected:	
	CPrikazy *Prikaz;
	
/********************************************************************
zpracuje parametry vcetne jejich vyhodnoceni a ulozi do pole parametru
	poz		: in int 
	ret		: in CString
	return	: void
********************************************************************/
	void GetParam(int poz, CString ret);
	
/********************************************************************
vraci text z retezce od pozice from do pozice to
	from	: in int 
	to		: in int
	ret		: CString vtupni retezec
	return	: CString
********************************************************************/
	CString GetFromTo(int from, int to, CString ret);

/********************************************************************
Odstrani z retezce mezery	
	ret		: in CString
	return	: CString
********************************************************************/
	CString GetSpaceOut(CString ret);

/********************************************************************
vyhodnoti matematicky vyraz	
	ret		: in CString
	return	: double hodnota vyrazu
********************************************************************/
	double Evaluate(CString ret);
};

#endif // !defined(AFX_EXPRESSION_H__58013A7A_E5FA_4688_9B87_E15F263E6291__INCLUDED_)
