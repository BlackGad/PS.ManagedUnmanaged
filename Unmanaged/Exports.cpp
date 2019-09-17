#include "pch.h"
#include "UnmanagedAPI.h"
#include "MemoryAllocator.h"

EXTERN_DLL_EXPORT HRESULT CreateObject(CLSID clsid, IUnknown** ppObject)
{
	if (ppObject == nullptr) return E_POINTER;
	if (*ppObject != nullptr) return E_POINTER;

	if(clsid == CLSID_CMemoryAllocator)
	{
		*ppObject = ps::com::CreateObject<MemoryAllocator>(__uuidof(IMemoryAllocator)).Detach();
	}
	else
	{
		return E_NOTIMPL;
	}

	return S_OK;
}
