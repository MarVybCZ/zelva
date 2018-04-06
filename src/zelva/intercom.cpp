// Machine generated IDispatch wrapper class(es) created with ClassWizard

#include "stdafx.h"
#include "intercom.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



/////////////////////////////////////////////////////////////////////////////
// IInter properties

/////////////////////////////////////////////////////////////////////////////
// IInter operations

void IInter::Load(LPCTSTR cesta)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x2, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 cesta);
}

void IInter::UnLoad(LPCTSTR cesta)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x3, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 cesta);
}

long IInter::GetPosChange()
{
	long result;
	InvokeHelper(0x4, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
	return result;
}

CString IInter::GetLibName(long x)
{
	CString result;
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x5, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms,
		x);
	return result;
}

CString IInter::GetLibPath(long x)
{
	CString result;
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x6, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms,
		x);
	return result;
}

CString IInter::GetComName(long i, long j)
{
	CString result;
	static BYTE parms[] =
		VTS_I4 VTS_I4;
	InvokeHelper(0x7, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms,
		i, j);
	return result;
}

CString IInter::ZpracujPrikaz(LPCTSTR ret, long x)
{
	CString result;
	static BYTE parms[] =
		VTS_BSTR VTS_I4;
	InvokeHelper(0x9, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms,
		ret, x);
	return result;
}

long IInter::GetHistLength()
{
	long result;
	InvokeHelper(0xb, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
	return result;
}

CString IInter::GetPrvekData(long x)
{
	CString result;
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0xc, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms,
		x);
	return result;
}

//DEL long IInter::GetFilePos(BSTR* Child, BSTR* Parent)
//DEL {
//DEL 	long result;
//DEL 	static BYTE parms[] =
//DEL 		VTS_PBSTR VTS_PBSTR;
//DEL 	InvokeHelper(0xd, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
//DEL 		Child, Parent);
//DEL 	return result;
//DEL }
