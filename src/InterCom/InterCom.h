

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 04:14:07 2038
 */
/* Compiler settings for InterCom.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.01.0622 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */



/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __InterCom_h__
#define __InterCom_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IInterface_FWD_DEFINED__
#define __IInterface_FWD_DEFINED__
typedef interface IInterface IInterface;

#endif 	/* __IInterface_FWD_DEFINED__ */


#ifndef __Interface_FWD_DEFINED__
#define __Interface_FWD_DEFINED__

#ifdef __cplusplus
typedef class Interface Interface;
#else
typedef struct Interface Interface;
#endif /* __cplusplus */

#endif 	/* __Interface_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IInterface_INTERFACE_DEFINED__
#define __IInterface_INTERFACE_DEFINED__

/* interface IInterface */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IInterface;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B874BAF5-413A-40F6-B36B-B648568E49CA")
    IInterface : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Load( 
            /* [in] */ BSTR cesta) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE UnLoad( 
            /* [in] */ BSTR cesta) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetPosChange( 
            /* [retval][out] */ BOOL *xx) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetLibName( 
            /* [in] */ int x,
            /* [retval][out] */ BSTR *name) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetLibPath( 
            /* [in] */ int x,
            /* [retval][out] */ BSTR *path) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetComName( 
            /* [in] */ int i,
            /* [in] */ int j,
            /* [retval][out] */ BSTR *name) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ZpracujPrikaz( 
            /* [in] */ BSTR ret,
            /* [in] */ int x,
            /* [retval][out] */ BSTR *outer) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetHistLength( 
            /* [retval][out] */ int *length) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetPrvekData( 
            /* [in] */ int x,
            /* [retval][out] */ BSTR *data) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IInterfaceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInterface * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInterface * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInterface * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IInterface * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IInterface * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IInterface * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IInterface * This,
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
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Load )( 
            IInterface * This,
            /* [in] */ BSTR cesta);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UnLoad )( 
            IInterface * This,
            /* [in] */ BSTR cesta);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetPosChange )( 
            IInterface * This,
            /* [retval][out] */ BOOL *xx);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetLibName )( 
            IInterface * This,
            /* [in] */ int x,
            /* [retval][out] */ BSTR *name);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetLibPath )( 
            IInterface * This,
            /* [in] */ int x,
            /* [retval][out] */ BSTR *path);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetComName )( 
            IInterface * This,
            /* [in] */ int i,
            /* [in] */ int j,
            /* [retval][out] */ BSTR *name);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ZpracujPrikaz )( 
            IInterface * This,
            /* [in] */ BSTR ret,
            /* [in] */ int x,
            /* [retval][out] */ BSTR *outer);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetHistLength )( 
            IInterface * This,
            /* [retval][out] */ int *length);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetPrvekData )( 
            IInterface * This,
            /* [in] */ int x,
            /* [retval][out] */ BSTR *data);
        
        END_INTERFACE
    } IInterfaceVtbl;

    interface IInterface
    {
        CONST_VTBL struct IInterfaceVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInterface_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IInterface_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IInterface_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IInterface_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IInterface_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IInterface_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IInterface_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IInterface_Load(This,cesta)	\
    ( (This)->lpVtbl -> Load(This,cesta) ) 

#define IInterface_UnLoad(This,cesta)	\
    ( (This)->lpVtbl -> UnLoad(This,cesta) ) 

#define IInterface_GetPosChange(This,xx)	\
    ( (This)->lpVtbl -> GetPosChange(This,xx) ) 

#define IInterface_GetLibName(This,x,name)	\
    ( (This)->lpVtbl -> GetLibName(This,x,name) ) 

#define IInterface_GetLibPath(This,x,path)	\
    ( (This)->lpVtbl -> GetLibPath(This,x,path) ) 

#define IInterface_GetComName(This,i,j,name)	\
    ( (This)->lpVtbl -> GetComName(This,i,j,name) ) 

#define IInterface_ZpracujPrikaz(This,ret,x,outer)	\
    ( (This)->lpVtbl -> ZpracujPrikaz(This,ret,x,outer) ) 

#define IInterface_GetHistLength(This,length)	\
    ( (This)->lpVtbl -> GetHistLength(This,length) ) 

#define IInterface_GetPrvekData(This,x,data)	\
    ( (This)->lpVtbl -> GetPrvekData(This,x,data) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IInterface_INTERFACE_DEFINED__ */



#ifndef __INTERCOMLib_LIBRARY_DEFINED__
#define __INTERCOMLib_LIBRARY_DEFINED__

/* library INTERCOMLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_INTERCOMLib;

EXTERN_C const CLSID CLSID_Interface;

#ifdef __cplusplus

class DECLSPEC_UUID("589F17E4-73B3-43A1-9FBF-5A9B09C180B0")
Interface;
#endif
#endif /* __INTERCOMLib_LIBRARY_DEFINED__ */

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


