#pragma once

#include "UnmanagedAPI.h"
#include <iostream>

namespace objects
{
	class Processor final : public ps::com::C_Unknown, IProcessor
	{
		CComBSTR m_id;
		int m_increment;
	public:
		Processor()
		{
			std::cout << "INFO: Processor created" << std::endl;

			GUID guid;
			CoCreateGuid(&guid);
			m_id = CComBSTR(guid);

			m_increment = rand() % 100;
		}

		virtual ~Processor()
		{
			std::cout << "INFO: Processor destroyed" << std::endl;
		}

		INTERFACE_MAP_BEGIN(ps::com::C_Unknown)
			INTERFACE_ENTRY(IProcessor)
		INTERFACE_MAP_END()

		//IProcessor
		STDMETHOD(get_Id)(BSTR* id) override
		{
			if (id == nullptr) return E_POINTER;
			m_id.CopyTo(id);
			return S_OK;
		}

		STDMETHOD(Process)(IUnknown* pBlock) override
		{
			if (pBlock == nullptr) return E_POINTER;

			CComQIPtr<IMemoryBlock> block = pBlock;
			if (block == nullptr)
			{
				std::cout << "ERROR: Block must be allocated by MemoryAllocator" << std::endl;
				return E_INVALIDARG;
			}

			int value = 0;
			block->get_Value(&value);
			block->put_Value(value += 2);
			block->TraceProcessor(m_id);

			std::cout << "INFO: Block processed successfully" << std::endl;
			return S_OK;
		}
	};
}


