// Machine generated IDispatch wrapper class(es) created with ClassWizard
/////////////////////////////////////////////////////////////////////////////
// IInter wrapper class

class IInter : public COleDispatchDriver
{
public:
	IInter() {}		// Calls COleDispatchDriver default constructor
	IInter(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	IInter(const IInter& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	void Load(LPCTSTR cesta);
	void UnLoad(LPCTSTR cesta);
	long GetPosChange();
	CString GetLibName(long x);
	CString GetLibPath(long x);
	CString GetComName(long i, long j);
	CString ZpracujPrikaz(LPCTSTR ret, long x);
	long GetHistLength();
	CString GetPrvekData(long x);
};
