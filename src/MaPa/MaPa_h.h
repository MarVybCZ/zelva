

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Wed Mar 14 13:40:51 2018
 */
/* Compiler settings for MaPa.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.00.0603 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __MaPa_h_h__
#define __MaPa_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IMaPaInter_FWD_DEFINED__
#define __IMaPaInter_FWD_DEFINED__
typedef interface IMaPaInter IMaPaInter;

#endif 	/* __IMaPaInter_FWD_DEFINED__ */


#ifndef __MaPaInter_FWD_DEFINED__
#define __MaPaInter_FWD_DEFINED__

#ifdef __cplusplus
typedef class MaPaInter MaPaInter;
#else
typedef struct MaPaInter MaPaInter;
#endif /* __cplusplus */

#endif 	/* __MaPaInter_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IMaPaInter_INTERFACE_DEFINED__
#define __IMaPaInter_INTERFACE_DEFINED__

/* interface IMaPaInter */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IMaPaInter;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E05E32C5-1676-4971-944C-A08A8BDFD347")
    IMaPaInter : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddString( 
            /* [in] */ BSTR *name,
            /* [in] */ double *value) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Parse( 
            /* [in] */ BSTR *Formula,
            /* [retval][out] */ double *result) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetErrorMes( 
            /* [retval][out] */ BSTR *message) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IMaPaInterVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMaPaInter * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMaPaInter * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMaPaInter * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMaPaInter * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMaPaInter * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMaPaInter * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMaPaInter * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddString )( 
            IMaPaInter * This,
            /* [in] */ BSTR *name,
            /* [in] */ double *value);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Parse )( 
            IMaPaInter * This,
            /* [in] */ BSTR *Formula,
            /* [retval][out] */ double *result);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetErrorMes )( 
            IMaPaInter * This,
            /* [retval][out] */ BSTR *message);
        
        END_INTERFACE
    } IMaPaInterVtbl;

    interface IMaPaInter
    {
        CONST_VTBL struct IMaPaInterVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMaPaInter_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMaPaInter_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMaPaInter_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMaPaInter_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMaPaInter_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMaPaInter_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMaPaInter_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IMaPaInter_AddString(This,name,value)	\
    ( (This)->lpVtbl -> AddString(This,name,value) ) 

#define IMaPaInter_Parse(This,Formula,result)	\
    ( (This)->lpVtbl -> Parse(This,Formula,result) ) 

#define IMaPaInter_GetErrorMes(This,message)	\
    ( (This)->lpVtbl -> GetErrorMes(This,message) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMaPaInter_INTERFACE_DEFINED__ */



#ifndef __MAPALib_LIBRARY_DEFINED__
#define __MAPALib_LIBRARY_DEFINED__

/* library MAPALib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_MAPALib;

EXTERN_C const CLSID CLSID_MaPaInter;

#ifdef __cplusplus

class DECLSPEC_UUID("7F9FB35E-04EC-4B7C-8828-A0966A038DA2")
MaPaInter;
#endif
#endif /* __MAPALib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  BSTR_UserSize64(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal64(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal64(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree64(     unsigned long *, BSTR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


