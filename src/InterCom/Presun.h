// Presun.h: interface for the CPresun class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PRESUN_H__5A8FBDD9_C6E2_46B5_898F_24C902BD500D__INCLUDED_)
#define AFX_PRESUN_H__5A8FBDD9_C6E2_46B5_898F_24C902BD500D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Prvek.h"

class CPresun : public CPrvek  
{
public:
	CPresun();
	CPresun(double a, double b, double c);

	virtual ~CPresun();

	double x, y, z;
};

#endif // !defined(AFX_PRESUN_H__5A8FBDD9_C6E2_46B5_898F_24C902BD500D__INCLUDED_)
