// Rotace.h: interface for the CRotace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ROTACE_H__9ACE6959_558A_4DDC_A51D_5ABDC8222AEF__INCLUDED_)
#define AFX_ROTACE_H__9ACE6959_558A_4DDC_A51D_5ABDC8222AEF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Prvek.h"

class CRotace : public CPrvek  
{
public:
	CRotace();
	CRotace(double a, double X, double Y, double Z);
	virtual ~CRotace();

	double angle, x, y, z;
};

#endif // !defined(AFX_ROTACE_H__9ACE6959_558A_4DDC_A51D_5ABDC8222AEF__INCLUDED_)
