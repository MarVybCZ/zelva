// Parametrs.h: interface for the CParametrs class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PARAMETRS_H__FFC2AC19_EA90_4637_B737_B5E298BA5194__INCLUDED_)
#define AFX_PARAMETRS_H__FFC2AC19_EA90_4637_B737_B5E298BA5194__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "defines.h"
#include <afx.h>
#include <afxtempl.h>

class CParametrs  
{
public:
	CString Nazev;
	double Hodnota;
	CParametrs();
	CParametrs(CParametrs &parametr);
//	CParametrs(CString &param);
	void operator =(const CParametrs &parametr);
	virtual ~CParametrs();

};

#endif // !defined(AFX_PARAMETRS_H__FFC2AC19_EA90_4637_B737_B5E298BA5194__INCLUDED_)
