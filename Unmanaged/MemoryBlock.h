#pragma once

#include "UnmanagedAPI.h"
#include <memory>
#include <iostream>
#include <vector>

class MemoryBlock : public ps::com::C_Unknown, IMemoryBlock
{
	int m_value;
	std::vector<CComBSTR> m_traceRoute;

public:

	MemoryBlock()
	{
		m_value = 0;
		std::cout << "INFO: MemoryBlock created" << std::endl;
	}

	virtual ~MemoryBlock()
	{
		std::cout << "INFO: MemoryBlock destroyed" << std::endl;
	}

	//COM map
	INTERFACE_MAP_BEGIN(ps::com::C_Unknown)
		INTERFACE_ENTRY(IMemoryBlock)
	INTERFACE_MAP_END()

	STDMETHOD(get_Value)(int* value) override
	{
		if (value == nullptr) return E_POINTER;
		*value = m_value;
		return S_OK;
	}
	
	STDMETHOD(put_Value)(int value) override
	{
		m_value = value;
		return S_OK;
	}

	STDMETHOD(TraceProcessor)(BSTR name) override
	{
		m_traceRoute.emplace_back(name);
		return S_OK;
	}

	STDMETHOD(get_TraceRoute)(SAFEARRAY** traceRoute) override
	{
		const auto psa = SafeArrayCreateVector(VT_BSTR, 0, m_traceRoute.size());

		BSTR* content = nullptr;
		SafeArrayAccessData(psa, reinterpret_cast<void**>(&content));
		for (std::size_t i = 0; i < m_traceRoute.size(); ++i)
		{
			content[i] = SysAllocString(m_traceRoute[i]);
		}
		SafeArrayUnaccessData(psa);

		*traceRoute = psa;
		return S_OK;
	}
};

