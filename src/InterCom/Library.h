// Library.h: interface for the CLibrary class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LIBRARY_H__4ED137A2_A4D2_460A_835B_6D89556A5F8E__INCLUDED_)
#define AFX_LIBRARY_H__4ED137A2_A4D2_460A_835B_6D89556A5F8E__INCLUDED_

#include "Prikazy.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CLibrary  
{
public:
	
/********************************************************************
vraci velikost pole clenskych prikazu
	return	: int
********************************************************************/
	int ClenPrGetUpB();

/********************************************************************
prida prikaz do pole clenskych prikazu
	prikaz	: in CPrikazy*
	return	: int
********************************************************************/
	void Add(CPrikazy *prikaz);	

	CString Cesta; //cesta k souboru knihovny

/********************************************************************
hleda prikaz
	nazev	: in CString nazev hledaneho prikazu
	return	: CPrikazy*
********************************************************************/
	CPrikazy *Find(CString nazev);

	CString Nazev; //nazev knihovny - nazev souboru bez cesty a bez pripony
	CArray<CPrikazy, CPrikazy> ClenPrikazy; //pole prikazu patricich to teto knihovny
	
	CLibrary();
	CLibrary(CString cesta, CString nazev);
	CLibrary(CLibrary &knihovna);
	CLibrary *operator =(CLibrary &knihovna);
	virtual ~CLibrary();

};

#endif // !defined(AFX_LIBRARY_H__4ED137A2_A4D2_460A_835B_6D89556A5F8E__INCLUDED_)
