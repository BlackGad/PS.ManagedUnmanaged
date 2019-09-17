#include "pch.h"
#include "MemoryAllocator.h"

STDMETHODIMP MemoryAllocator::Function1(BSTR key, VARIANT value)
{
	return S_OK;
}

STDMETHODIMP MemoryAllocator::get_Property1(int* value)
{
	return S_OK;
}

STDMETHODIMP MemoryAllocator::put_Property1(int value)
{
	return S_OK;
}