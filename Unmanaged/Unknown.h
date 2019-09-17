#pragma once

namespace ps
{
	namespace com
	{
		//////////////////////////////////////////////////////////////////////
		// C_Unknown -- small class to handle COM-style objects
		//////////////////////////////////////////////////////////////////////
		template<class T>
		static CComPtr<IUnknown> CreateObject(REFIID riid = __uuidof(IUnknown), HRESULT* hResult = nullptr)
		{
			T* pObj = nullptr;
			auto hr = S_OK;
			CComPtr<IUnknown> result;

			pObj = new (std::nothrow)T();

			if (pObj == nullptr) hr = E_OUTOFMEMORY;
			if (SUCCEEDED(hr)) hr = pObj->FinalConstruct();
			if (SUCCEEDED(hr)) hr = pObj->QueryInterface(riid, reinterpret_cast<void**>(& result));
			if (FAILED(hr))
			{
				delete pObj;
				result = nullptr;
			}

			if (hResult)* hResult = hr;

			return result;
		}

		class ATL_NO_VTABLE C_Unknown : public IUnknown
		{
		public:
			C_Unknown(void) : m_cRef(0)
			{
			}
			virtual ~C_Unknown(void)
			{
			}

		public:
			HRESULT FinalConstruct()
			{
				return CoCreateFreeThreadedMarshaler(static_cast<IUnknown*>(static_cast<void*>(this)), &m_pUnkMarshaler.p);
			}

		public:
			STDMETHOD(QueryInterface)(REFIID riid, void** ppv) override
			{
				if (ppv == nullptr) return E_POINTER;

				*ppv = nullptr;
				if (riid == IID_IMarshal) return m_pUnkMarshaler->QueryInterface(riid, ppv);
				else if (riid == IID_IUnknown) return GetInterface(static_cast<IUnknown*>(this), ppv);
				return E_NOINTERFACE;
			}
			STDMETHOD_(ULONG, AddRef)(void) override
			{
				return InterlockedIncrement(&m_cRef);
			}
			STDMETHOD_(ULONG, Release)(void) override
			{
				const auto count = InterlockedDecrement(&m_cRef);
				if (count > 0) return count;

				delete this;
				return 0;
			}

		protected:
			volatile long m_cRef;
			CComPtr<IUnknown> m_pUnkMarshaler;

		protected:
			HRESULT GetInterface(IUnknown* pUnk, void** ppv) { *ppv = pUnk; pUnk->AddRef(); return S_OK; };
		};

#define _IMPLEMENT_IUNKNOWN(baseClassType) \
	        STDMETHOD_(ULONG, AddRef)(void) { return baseClassType::AddRef(); }; \
	        STDMETHOD_(ULONG, Release)(void) { return baseClassType::Release(); }

#define INTERFACE_ENTRY_AGGREGATE(interfaceType, punk)\
		        if (riid == __uuidof(interfaceType))\
			        return punk->QueryInterface(riid, ppv);

#define INTERFACE_ENTRY(interfaceType)\
		        if (riid == __uuidof(interfaceType))\
			        return GetInterface((interfaceType *)this, ppv);

#define INTERFACE_CHAIN_ENTRY(baseClassType)\
		        hr = baseClassType::QueryInterface(riid, ppv);\
		        if (SUCCEEDED(hr)) return hr;

#define INTERFACE_MAP_BEGIN(baseClassType)\
			typedef baseClassType InternalBaseClassType;\
			_IMPLEMENT_IUNKNOWN(baseClassType)\
	        STDMETHOD(QueryInterface)(REFIID riid, void **ppv)\
	        {\
		        HRESULT hr = S_OK;\
		        if (ppv == NULL) return E_POINTER;\
		        *ppv = NULL;

#define INTERFACE_MAP_END()\
				INTERFACE_CHAIN_ENTRY(InternalBaseClassType)\
		        return hr;\
	        }

		///////////////////////////////////////////////////////////////////////////
		// Пример создания простого IUnknown объекта
		// 
		//  Определяем интерфейс в *.idl файле
		//	[
		//		object,
		//		local,
		//		uuid(5688F40C-9DF5-405f-936E-D36B308A5D05),
		//		pointer_default(unique)
		//	]
		//	interface ITestInterface: IUnknown
		//	{
		//		HRESULT Function1([in]BSTR key,[in]VARIANT value);
		//		[propget]HRESULT Property1([out,retval]int* value);
		//		[propput]HRESULT Property1([in]int** value);
		//	};
		// 
		//	Реализация интерфейса
		//	class TestObject:
		//		public C_Unknown
		//	{
		//	public:
		//		TestObject(void);
		//		~TestObject(void);
		//	public:
		//	
		//		INTERFACE_MAP_BEGIN(C_Unknown)//обработка родительского класса
		//			INTERFACE_ENTRY(ITestInterface)//обработка текущего класса
		//		INTERFACE_MAP_END()
		//		
		//	public://ITestInterface
		//		STDMETHOD(Function1)(BSTR key,VARIANT value);
		//		STDMETHOD(get_Property1)(int* value);
		//		STDMETHOD(put_Property1)(int value);
		//	};
		//
		//	Создание объекта:
		//
		//	CComQIPtr<ITestInterface> piSettings = CreateObject<TestObject>(__uuidof(ITestInterface));
		// 
		///////////////////////////////////////////////////////////////////////////
	}
}