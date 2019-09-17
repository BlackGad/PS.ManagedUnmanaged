

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

#ifndef __IMemoryBlock_FWD_DEFINED__
#define __IMemoryBlock_FWD_DEFINED__
typedef interface IMemoryBlock IMemoryBlock;

#endif 	/* __IMemoryBlock_FWD_DEFINED__ */


#ifndef __IMemoryAllocator_FWD_DEFINED__
#define __IMemoryAllocator_FWD_DEFINED__
typedef interface IMemoryAllocator IMemoryAllocator;

#endif 	/* __IMemoryAllocator_FWD_DEFINED__ */


#ifndef __IProcessor_FWD_DEFINED__
#define __IProcessor_FWD_DEFINED__
typedef interface IProcessor IProcessor;

#endif 	/* __IProcessor_FWD_DEFINED__ */


#ifndef __IDumper_FWD_DEFINED__
#define __IDumper_FWD_DEFINED__
typedef interface IDumper IDumper;

#endif 	/* __IDumper_FWD_DEFINED__ */


#ifndef __MemoryAllocator_FWD_DEFINED__
#define __MemoryAllocator_FWD_DEFINED__

#ifdef __cplusplus
typedef class MemoryAllocator MemoryAllocator;
#else
typedef struct MemoryAllocator MemoryAllocator;
#endif /* __cplusplus */

#endif 	/* __MemoryAllocator_FWD_DEFINED__ */


#ifndef __Processor_FWD_DEFINED__
#define __Processor_FWD_DEFINED__

#ifdef __cplusplus
typedef class Processor Processor;
#else
typedef struct Processor Processor;
#endif /* __cplusplus */

#endif 	/* __Processor_FWD_DEFINED__ */


#ifndef __Dumper_FWD_DEFINED__
#define __Dumper_FWD_DEFINED__

#ifdef __cplusplus
typedef class Dumper Dumper;
#else
typedef struct Dumper Dumper;
#endif /* __cplusplus */

#endif 	/* __Dumper_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IMemoryBlock_INTERFACE_DEFINED__
#define __IMemoryBlock_INTERFACE_DEFINED__

/* interface IMemoryBlock */
/* [unique][uuid][local][object] */ 


EXTERN_C const IID IID_IMemoryBlock;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A1DF52E1-642F-42F2-8117-C7E126E72BA1")
    IMemoryBlock : public IUnknown
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Value( 
            /* [retval][out] */ int *value) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_Value( 
            /* [in] */ int value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_TraceRoute( 
            /* [retval][out] */ SAFEARRAY * *traceRoute) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE TraceProcessor( 
            /* [in] */ BSTR name) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IMemoryBlockVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMemoryBlock * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMemoryBlock * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMemoryBlock * This);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Value )( 
            IMemoryBlock * This,
            /* [retval][out] */ int *value);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE *put_Value )( 
            IMemoryBlock * This,
            /* [in] */ int value);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_TraceRoute )( 
            IMemoryBlock * This,
            /* [retval][out] */ SAFEARRAY * *traceRoute);
        
        HRESULT ( STDMETHODCALLTYPE *TraceProcessor )( 
            IMemoryBlock * This,
            /* [in] */ BSTR name);
        
        END_INTERFACE
    } IMemoryBlockVtbl;

    interface IMemoryBlock
    {
        CONST_VTBL struct IMemoryBlockVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMemoryBlock_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMemoryBlock_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMemoryBlock_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMemoryBlock_get_Value(This,value)	\
    ( (This)->lpVtbl -> get_Value(This,value) ) 

#define IMemoryBlock_put_Value(This,value)	\
    ( (This)->lpVtbl -> put_Value(This,value) ) 

#define IMemoryBlock_get_TraceRoute(This,traceRoute)	\
    ( (This)->lpVtbl -> get_TraceRoute(This,traceRoute) ) 

#define IMemoryBlock_TraceProcessor(This,name)	\
    ( (This)->lpVtbl -> TraceProcessor(This,name) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMemoryBlock_INTERFACE_DEFINED__ */


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
        virtual HRESULT STDMETHODCALLTYPE Allocate( 
            /* [retval][out] */ IUnknown **block) = 0;
        
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
        
        HRESULT ( STDMETHODCALLTYPE *Allocate )( 
            IMemoryAllocator * This,
            /* [retval][out] */ IUnknown **block);
        
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


#define IMemoryAllocator_Allocate(This,block)	\
    ( (This)->lpVtbl -> Allocate(This,block) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMemoryAllocator_INTERFACE_DEFINED__ */


#ifndef __IProcessor_INTERFACE_DEFINED__
#define __IProcessor_INTERFACE_DEFINED__

/* interface IProcessor */
/* [unique][uuid][local][object] */ 


EXTERN_C const IID IID_IProcessor;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C0554AAB-752D-41B1-8DEB-8E9FA24CADC6")
    IProcessor : public IUnknown
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Id( 
            /* [retval][out] */ BSTR *id) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Process( 
            /* [in] */ IUnknown *memoryBlock) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IProcessorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IProcessor * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IProcessor * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IProcessor * This);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Id )( 
            IProcessor * This,
            /* [retval][out] */ BSTR *id);
        
        HRESULT ( STDMETHODCALLTYPE *Process )( 
            IProcessor * This,
            /* [in] */ IUnknown *memoryBlock);
        
        END_INTERFACE
    } IProcessorVtbl;

    interface IProcessor
    {
        CONST_VTBL struct IProcessorVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IProcessor_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IProcessor_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IProcessor_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IProcessor_get_Id(This,id)	\
    ( (This)->lpVtbl -> get_Id(This,id) ) 

#define IProcessor_Process(This,memoryBlock)	\
    ( (This)->lpVtbl -> Process(This,memoryBlock) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IProcessor_INTERFACE_DEFINED__ */


#ifndef __IDumper_INTERFACE_DEFINED__
#define __IDumper_INTERFACE_DEFINED__

/* interface IDumper */
/* [unique][uuid][local][object] */ 


EXTERN_C const IID IID_IDumper;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9930FD13-79BA-42FA-A6B7-A6669BA50BF8")
    IDumper : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE DumpTraceRoute( 
            /* [in] */ IUnknown *memoryBlock,
            /* [retval][out] */ SAFEARRAY * *traceRoute) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DumpResult( 
            /* [in] */ IUnknown *memoryBlock,
            /* [retval][out] */ int *value) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IDumperVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDumper * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDumper * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDumper * This);
        
        HRESULT ( STDMETHODCALLTYPE *DumpTraceRoute )( 
            IDumper * This,
            /* [in] */ IUnknown *memoryBlock,
            /* [retval][out] */ SAFEARRAY * *traceRoute);
        
        HRESULT ( STDMETHODCALLTYPE *DumpResult )( 
            IDumper * This,
            /* [in] */ IUnknown *memoryBlock,
            /* [retval][out] */ int *value);
        
        END_INTERFACE
    } IDumperVtbl;

    interface IDumper
    {
        CONST_VTBL struct IDumperVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDumper_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDumper_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDumper_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDumper_DumpTraceRoute(This,memoryBlock,traceRoute)	\
    ( (This)->lpVtbl -> DumpTraceRoute(This,memoryBlock,traceRoute) ) 

#define IDumper_DumpResult(This,memoryBlock,value)	\
    ( (This)->lpVtbl -> DumpResult(This,memoryBlock,value) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDumper_INTERFACE_DEFINED__ */



#ifndef __UnmanagedLibrary_LIBRARY_DEFINED__
#define __UnmanagedLibrary_LIBRARY_DEFINED__

/* library UnmanagedLibrary */
/* [uuid] */ 


EXTERN_C const IID LIBID_UnmanagedLibrary;

EXTERN_C const CLSID CLSID_MemoryAllocator;

#ifdef __cplusplus

class DECLSPEC_UUID("8FB509AE-500E-44C0-9E83-2233A80838F0")
MemoryAllocator;
#endif

EXTERN_C const CLSID CLSID_Processor;

#ifdef __cplusplus

class DECLSPEC_UUID("201DCE94-3EE2-493C-AA8E-97B1DD8D47B1")
Processor;
#endif

EXTERN_C const CLSID CLSID_Dumper;

#ifdef __cplusplus

class DECLSPEC_UUID("F80DE37B-24D4-4147-8CFF-21B29221B23D")
Dumper;
#endif
#endif /* __UnmanagedLibrary_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


