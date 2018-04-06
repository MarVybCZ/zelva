// Interface.h : Declaration of the CInterface

#ifndef __INTERFACE_H_
#define __INTERFACE_H_

#include "resource.h"       // main symbols
#include "Interpret.h"
/////////////////////////////////////////////////////////////////////////////
// CInterface
class ATL_NO_VTABLE CInterface : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CInterface, &CLSID_Interface>,
	public ISupportErrorInfo,
	public IDispatchImpl<IInterface, &IID_IInterface, &LIBID_INTERCOMLib>
{
public:
	CInterpret * Interpret;
	CInterface()
	{
		Interpret = new CInterpret;
	}
	virtual ~CInterface()
	{
		delete Interpret;
	}

DECLARE_REGISTRY_RESOURCEID(IDR_INTERFACE)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CInterface)
	COM_INTERFACE_ENTRY(IInterface)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
END_COM_MAP()

// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// IInterface
public:

	STDMETHOD(GetPrvekData)(/*[in]*/ int x, /*[out, retval]*/BSTR *data);
	STDMETHOD(GetHistLength)(/*[out,retval]*/ int * length);
	STDMETHOD(ZpracujPrikaz)(/*[in]*/BSTR ret,/*[in]*/int x,/*[out,retval]*/ BSTR *outer);
	STDMETHOD(GetComName)(/*[in]*/int i,/*[in]*/ int j,/*[out,retval]*/ BSTR* name);
	STDMETHOD(GetLibPath)(/*[in]*/int x,/*[out,retval]*/ BSTR *path);
	STDMETHOD(GetLibName)(/*[in]*/int x,/*[out,retval]*/ BSTR *name);
	STDMETHOD(GetPosChange)(/*[out,retval]*/BOOL *xx);
	STDMETHOD(UnLoad)(/*[in]*/BSTR cesta);
	STDMETHOD(Load)(/*[in]*/BSTR cesta);
	
};

#endif //__INTERFACE_H_
