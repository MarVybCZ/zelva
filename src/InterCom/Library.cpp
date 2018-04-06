// Library.cpp: implementation of the CLibrary class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"

#include "Library.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CLibrary::CLibrary()
{

}

CLibrary::CLibrary(CLibrary &knihovna)
{
	Cesta = knihovna.Cesta;
	Nazev = knihovna.Nazev;
//	ClenPrikazy.Copy(knihovna.ClenPrikazy);
	for(int i = 0;i<=knihovna.ClenPrikazy.GetUpperBound();i++)
	{
		ClenPrikazy.Add(knihovna.ClenPrikazy[i]);
	}
}


CLibrary::CLibrary(CString cesta, CString nazev)
{
	Cesta = cesta;
	Nazev = nazev;
}

CLibrary::~CLibrary()
{

}

CLibrary *CLibrary::operator =(CLibrary &knihovna)
{
	Cesta = knihovna.Cesta;
	Nazev = knihovna.Nazev;
	for(int i = 0;i<=knihovna.ClenPrikazy.GetUpperBound();i++)
	{
		ClenPrikazy.Add(knihovna.ClenPrikazy[i]);
	}
	
	return this;
}

CPrikazy *CLibrary::Find(CString nazev)
{	
	CPrikazy *pom;
	int z = nazev.Find('(',0);
	if(z!=-1)
	{
		nazev.Delete(z,nazev.GetLength()-z);
	}

	pom = NULL;
	for(int i=0;i<=ClenPrikazy.GetUpperBound();i++)
	{
		if(ClenPrikazy[i].Nazev==nazev) 
		{
			return &ClenPrikazy[i];			
		}
	}
	return pom;
}

void CLibrary::Add(CPrikazy *prikaz)
{
	ClenPrikazy.Add(*prikaz);

}

int CLibrary::ClenPrGetUpB()
{
	return ClenPrikazy.GetUpperBound();
}
