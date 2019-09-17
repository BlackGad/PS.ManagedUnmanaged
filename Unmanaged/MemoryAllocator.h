#pragma once

#include "UnmanagedAPI.h"
#include "MemoryBlock.h"

namespace objects
{
	class MemoryAllocator final : public ps::com::C_Unknown, IMemoryAllocator
	{
	public:
		MemoryAllocator()
		{
			std::cout << "INFO: MemoryAllocator created" << std::endl;
		}

		virtual ~MemoryAllocator()
		{
			std::cout << "INFO: MemoryAllocator destroyed" << std::endl;
		}

		INTERFACE_MAP_BEGIN(ps::com::C_Unknown)
			INTERFACE_ENTRY(IMemoryAllocator)
		INTERFACE_MAP_END()

		//IMemoryAllocator
		STDMETHOD(Allocate)(IUnknown** ppBlock) override
		{
			if (ppBlock == nullptr) return E_POINTER;

			*ppBlock = ps::com::CreateObject<MemoryBlock>(new MemoryBlock()).Detach();
			return S_OK;
		}
	};
}


