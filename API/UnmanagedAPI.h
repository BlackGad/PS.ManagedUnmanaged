

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 05:14:07 2038
 */
/* Compiler settings for API.idl:
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

#ifndef __UnmanagedAPI_h__
#define __UnmanagedAPI_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IMemoryAllocator_FWD_DEFINED__
#define __IMemoryAllocator_FWD_DEFINED__
typedef interface IMemoryAllocator IMemoryAllocator;

#endif 	/* __IMemoryAllocator_FWD_DEFINED__ */


#ifndef __CMemoryAllocator_FWD_DEFINED__
#define __CMemoryAllocator_FWD_DEFINED__

#ifdef __cplusplus
typedef class CMemoryAllocator CMemoryAllocator;
#else
typedef struct CMemoryAllocator CMemoryAllocator;
#endif /* __cplusplus */

#endif 	/* __CMemoryAllocator_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IMemoryAllocator_INTERFACE_DEFINED__
#define __IMemoryAllocator_INTERFACE_DEFINED__

/* interface IMemoryAllocator */
/* [unique][uuid][local][object] */ 


EXTERN_C const IID IID_IMemoryAllocator;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5494BFCB-F321-4815-8D48-77CBC12CB950")
    IMemoryAllocator : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Function1( 
            /* [in] */ BSTR key,
            /* [in] */ VARIANT value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Property1( 
            /* [retval][out] */ int *value) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_Property1( 
            /* [in] */ int value) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IMemoryAllocatorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMemoryAllocator * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMemoryAllocator * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMemoryAllocator * This);
        
        HRESULT ( STDMETHODCALLTYPE *Function1 )( 
            IMemoryAllocator * This,
            /* [in] */ BSTR key,
            /* [in] */ VARIANT value);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Property1 )( 
            IMemoryAllocator * This,
            /* [retval][out] */ int *value);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE *put_Property1 )( 
            IMemoryAllocator * This,
            /* [in] */ int value);
        
        END_INTERFACE
    } IMemoryAllocatorVtbl;

    interface IMemoryAllocator
    {
        CONST_VTBL struct IMemoryAllocatorVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMemoryAllocator_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMemoryAllocator_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMemoryAllocator_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMemoryAllocator_Function1(This,key,value)	\
    ( (This)->lpVtbl -> Function1(This,key,value) ) 

#define IMemoryAllocator_get_Property1(This,value)	\
    ( (This)->lpVtbl -> get_Property1(This,value) ) 

#define IMemoryAllocator_put_Property1(This,value)	\
    ( (This)->lpVtbl -> put_Property1(This,value) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMemoryAllocator_INTERFACE_DEFINED__ */



#ifndef __UnmanagedLibrary_LIBRARY_DEFINED__
#define __UnmanagedLibrary_LIBRARY_DEFINED__

/* library UnmanagedLibrary */
/* [uuid] */ 


EXTERN_C const IID LIBID_UnmanagedLibrary;

EXTERN_C const CLSID CLSID_CMemoryAllocator;

#ifdef __cplusplus

class DECLSPEC_UUID("8FB509AE-500E-44C0-9E83-2233A80838F0")
CMemoryAllocator;
#endif
#endif /* __UnmanagedLibrary_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


