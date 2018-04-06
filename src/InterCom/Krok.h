// Krok.h: interface for the CKrok class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_KROK_H__76027563_CC02_4AE3_9322_E6A4B7396DB9__INCLUDED_)
#define AFX_KROK_H__76027563_CC02_4AE3_9322_E6A4B7396DB9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Prvek.h"

class CKrok : public CPrvek  
{
public:
	bool StartPoint;
	double krok;
	double Color[3];
	CKrok();
	virtual ~CKrok();

};

#endif // !defined(AFX_KROK_H__76027563_CC02_4AE3_9322_E6A4B7396DB9__INCLUDED_)
