// Parametrs.cpp: implementation of the CParametrs class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Parametrs.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CParametrs::CParametrs()
{

}

CParametrs::CParametrs(CParametrs &parametr)
{
	
	Hodnota = parametr.Hodnota;
	
	Nazev = parametr.Nazev;
}

/*CParametrs::CParametrs(CString &param)
{
	Nazev = param;

}*/

void CParametrs::operator =(const CParametrs &parametr)
{	
	Hodnota = parametr.Hodnota;
	
	Nazev = parametr.Nazev;
}


CParametrs::~CParametrs()
{

}
