// Presun.cpp: implementation of the CPresun class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Presun.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPresun::CPresun()
{
	Nazev = "PRESUN";
}

CPresun::CPresun(double a, double b, double c)
{
	Nazev = "PRESUN";
	x = a; y = b; z = c;
}

CPresun::~CPresun()
{

}
