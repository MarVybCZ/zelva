// Machine generated IDispatch wrapper class(es) created with ClassWizard
/////////////////////////////////////////////////////////////////////////////
// IMaPaInter wrapper class

class IMaPaInter : public COleDispatchDriver
{
public:
	IMaPaInter() {CreateDispatch("MaPa.MaPaInter");}		// Calls COleDispatchDriver default constructor
	IMaPaInter(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	IMaPaInter(const IMaPaInter& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	void AddString(BSTR* name, double* value);
	double Parse(BSTR* Formula);
	CString GetErrorMes();
};
