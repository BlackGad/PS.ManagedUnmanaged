using System;
using System.Runtime.InteropServices;
using UnmanagedLibrary;

namespace Managed.Unmanaged
{
    public static class Helper
    {
        #region Static members

        public static IMemoryAllocator CreateAllocator()
        {
            return Create<IMemoryAllocator>(typeof(MemoryAllocatorClass));
        }

        public static IDumper CreateDumper()
        {
            return Create<IDumper>(typeof(DumperClass));
        }

        public static IProcessor CreateProcessor()
        {
            return Create<IProcessor>(typeof(ProcessorClass));
        }

        private static TInterface Create<TInterface>(Type type)
        {
            CreateObject(type.GUID, out var result);
            return (TInterface)result;
        }

        [DllImport("Unmanaged.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern void CreateObject([In] Guid id,
                                                [Out] [MarshalAs(UnmanagedType.IUnknown)]
                                                out object result);

        #endregion
    }
}