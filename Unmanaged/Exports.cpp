#include "pch.h"
#include "UnmanagedAPI.h"
#include "MemoryAllocator.h"
#include "Dumper.h"
#include "Processor.h"

EXTERN_DLL_EXPORT HRESULT CreateObject(CLSID clsid, IUnknown** ppObject)
{
	if (ppObject == nullptr) return E_POINTER;
	if (*ppObject != nullptr) return E_POINTER;

	if (clsid == CLSID_MemoryAllocator) *ppObject = ps::com::CreateObject<objects::MemoryAllocator>().Detach();
	if (clsid == CLSID_Processor) *ppObject = ps::com::CreateObject<objects::Processor>().Detach();
	if (clsid == CLSID_Dumper) *ppObject = ps::com::CreateObject<objects::Dumper>().Detach();
	
	if (*ppObject == nullptr) return E_INVALIDARG;

	return S_OK;
}
