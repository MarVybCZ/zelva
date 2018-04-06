// Prikazy.h: interface for the CZpracPrik class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ZPRACPRIK_H__970B54CA_947A_4C88_8125_579C47856465__INCLUDED_)
#define AFX_ZPRACPRIK_H__970B54CA_947A_4C88_8125_579C47856465__INCLUDED_

#include "Parametrs.h"


#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CPrikazy
{
public:
	static	CString GetSpaceOut(CString ret);

	CParametrs *FindProm(CString prom);//najde promenou daneho jmena vraci CParametrs*

	int PoleParamLenght();//PoleParam.GetUpperBound()
	int Pozice;//pozice v danem prikazu

	CString ReturnLine();//vraci radek
	CString Nazev;//nazev prikazu

	CString Telo;//telo prikazu

	CArray<CParametrs, CParametrs> PoleParam;//parametry prikazu
	CPrikazy();
	CPrikazy(const CPrikazy &prikaz);
	virtual ~CPrikazy();
	CPrikazy *operator=(CPrikazy &prikaz);

};

#endif // !defined(AFX_ZPRACPRIK_H__970B54CA_947A_4C88_8125_579C47856465__INCLUDED_)
