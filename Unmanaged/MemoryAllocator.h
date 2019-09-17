#pragma once

#include "UnmanagedAPI.h"

class MemoryAllocator : public ps::com::C_Unknown, IMemoryAllocator
{
public:
	INTERFACE_MAP_BEGIN(ps::com::C_Unknown)
		INTERFACE_ENTRY(IMemoryAllocator)
	INTERFACE_MAP_END()
	
public://IMemoryAllocator
	STDMETHOD(Function1)(BSTR key,VARIANT value);
	STDMETHOD(get_Property1)(int* value);
	STDMETHOD(put_Property1)(int value);
};

