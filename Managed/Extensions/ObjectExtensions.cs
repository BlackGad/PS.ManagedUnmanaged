using System;
using System.Runtime.InteropServices;

namespace Managed.Extensions
{
    public static class ObjectExtensions
    {
        #region Static members

        public static void Free(this object @object)
        {
            if (@object is IDisposable disposable)
            {
                disposable.Dispose();
            }
            else if (Marshal.IsComObject(@object)) Marshal.ReleaseComObject(@object);
        }

        #endregion
    }
}