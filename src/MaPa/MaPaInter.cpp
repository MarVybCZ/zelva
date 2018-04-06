// MaPaInter.cpp : Implementation of CMaPaInter
#include "stdafx.h"
#include "MaPa.h"
#include "MaPaInter.h"

/////////////////////////////////////////////////////////////////////////////
// CMaPaInter


STDMETHODIMP CMaPaInter::AddString(BSTR *name, double *value)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

	CString xxx;	
	
	xxx = *name;
	xxx.MakeUpper();

	MathParser->Parameters.AddString(xxx,value);


	xxx.Empty();
	return S_OK;
}

STDMETHODIMP CMaPaInter::Parse(BSTR *Formula, double *result)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

	// TODO: Add your implementation code here
	CString xxx;
	xxx = *Formula;
	xxx.MakeUpper();
	ErrorMessage = MathParser->Parse(xxx,result);

	xxx.Empty();
	return S_OK;
}

STDMETHODIMP CMaPaInter::GetErrorMes(BSTR *message)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

	// TODO: Add your implementation code here
	BSTR x;
	x = ErrorMessage.AllocSysString();
	*message = x;
	SysFreeString(x);
	return S_OK;
}
