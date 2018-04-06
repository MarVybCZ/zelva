// Prvek.h: interface for the CPrvek class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PRVEK_H__2B9507D9_354B_426D_B35E_7FABDE8D3052__INCLUDED_)
#define AFX_PRVEK_H__2B9507D9_354B_426D_B35E_7FABDE8D3052__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "defines.h"
#include <afx.h>
#include <afxtempl.h>

class CPrvek  
{
public:
	CString Nazev;
	CPrvek();
	virtual ~CPrvek();

};

#endif // !defined(AFX_PRVEK_H__2B9507D9_354B_426D_B35E_7FABDE8D3052__INCLUDED_)
