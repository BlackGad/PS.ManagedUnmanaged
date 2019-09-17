#pragma once

#include "UnmanagedAPI.h"
#include <iostream>

namespace objects
{
	class Dumper final : public ps::com::C_Unknown, IDumper
	{
	public:
		Dumper()
		{
			std::cout << "INFO: Dumper created" << std::endl;
		}

		virtual ~Dumper()
		{
			std::cout << "INFO: Dumper destroyed" << std::endl;
		}
	
		INTERFACE_MAP_BEGIN(ps::com::C_Unknown)
			INTERFACE_ENTRY(IDumper)
		INTERFACE_MAP_END()

		//IDumper
		/*
		 HRESULT DumpTraceRoute([in]IUnknown* memoryBlock, [out, retval]SAFEARRAY(BSTR)* traceRoute);
	HRESULT DumpResult([in]IUnknown* memoryBlock, [out, retval]int *value);
		 
		 */
		STDMETHOD(DumpResult)(IUnknown* pBlock, int* value) override
		{
			if (pBlock == nullptr) return E_POINTER;
			if (value == nullptr) return E_POINTER;

			CComQIPtr<IMemoryBlock> block = pBlock;
			if (block == nullptr)
			{
				std::cout << "ERROR: Block must be allocated by MemoryAllocator" << std::endl;
				return E_INVALIDARG;
			}

			return block->get_Value(value);
		}
		STDMETHOD(DumpTraceRoute)(IUnknown* pBlock, SAFEARRAY** traceRoute) override
		{
			if (pBlock == nullptr) return E_POINTER;
			if (traceRoute == nullptr) return E_POINTER;

			CComQIPtr<IMemoryBlock> block = pBlock;
			if (block == nullptr)
			{
				std::cout << "ERROR: Block must be allocated by MemoryAllocator" << std::endl;
				return E_INVALIDARG;
			}
			return block->get_TraceRoute(traceRoute);
		}
	};
}


