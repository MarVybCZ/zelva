// MaPaInter.h : Declaration of the CMaPaInter

#ifndef __MAPAINTER_H_
#define __MAPAINTER_H_

#include "resource.h"       // main symbols
#include "MathParser.h"
/////////////////////////////////////////////////////////////////////////////
// CMaPaInter
class ATL_NO_VTABLE CMaPaInter : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CMaPaInter, &CLSID_MaPaInter>,
	public IDispatchImpl<IMaPaInter, &IID_IMaPaInter, &LIBID_MAPALib>
{
public:
	CMaPaInter()
	{
		MathParser = new CMathParser;
	}
	virtual ~CMaPaInter()
	{
		delete MathParser;
	}

DECLARE_REGISTRY_RESOURCEID(IDR_MAPAINTER)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CMaPaInter)
	COM_INTERFACE_ENTRY(IMaPaInter)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IMaPaInter
public:
	CString ErrorMessage;
	CMathParser *MathParser;
	STDMETHOD(GetErrorMes)(/*[out, retval]*/ BSTR *message);
	STDMETHOD(Parse)(/*[in]*/ BSTR *Formula, /*[out,retval]*/ double *result);
	STDMETHOD(AddString)(/*[in]*/BSTR *name, /*[in]*/ double *value);
};

#endif //__MAPAINTER_H_
