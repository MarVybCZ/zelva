// TurBlok.h: interface for the CTurBlok class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TURBLOK_H__CE83C58F_BB19_4390_9902_32B93D1186C8__INCLUDED_)
#define AFX_TURBLOK_H__CE83C58F_BB19_4390_9902_32B93D1186C8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Prvek.h"

class CTurBlok : public CPrvek  
{
public:
	CString Value;
	CTurBlok(CString value);
	virtual ~CTurBlok();

};

#endif // !defined(AFX_TURBLOK_H__CE83C58F_BB19_4390_9902_32B93D1186C8__INCLUDED_)
