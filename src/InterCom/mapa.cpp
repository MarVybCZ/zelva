// Machine generated IDispatch wrapper class(es) created with ClassWizard

#include "stdafx.h"
#include "mapa.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



/////////////////////////////////////////////////////////////////////////////
// IMaPaInter properties

/////////////////////////////////////////////////////////////////////////////
// IMaPaInter operations

void IMaPaInter::AddString(BSTR* name, double* value)
{
	static BYTE parms[] =
		VTS_PBSTR VTS_PR8;
	InvokeHelper(0x1, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 name, value);
}

double IMaPaInter::Parse(BSTR* Formula)
{
	double result;
	static BYTE parms[] =
		VTS_PBSTR;
	InvokeHelper(0x2, DISPATCH_METHOD, VT_R8, (void*)&result, parms,
		Formula);
	return result;
}

CString IMaPaInter::GetErrorMes()
{
	CString result;
	InvokeHelper(0x3, DISPATCH_METHOD, VT_BSTR, (void*)&result, NULL);
	return result;
}
