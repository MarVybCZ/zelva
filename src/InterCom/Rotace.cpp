// Rotace.cpp: implementation of the CRotace class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Rotace.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CRotace::CRotace()
{
	Nazev = "ROTACE";
}

CRotace::CRotace(double a, double X, double Y, double Z)
{
	Nazev = "ROTACE";
	angle = a; x =X; y = Y; z = Z;
}

CRotace::~CRotace()
{

}
