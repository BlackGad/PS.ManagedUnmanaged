using System;
using System.Runtime.InteropServices;

namespace Managed
{
    public static class UnmanagedHelper
    {
        #region Static members

        [DllImport("Unmanaged.dll", CallingConvention = CallingConvention.StdCall)]
        public static extern void CreateObject([In] Guid id,
                                               [Out] [MarshalAs(UnmanagedType.IUnknown)]
                                               out object result);

        #endregion
    }
}