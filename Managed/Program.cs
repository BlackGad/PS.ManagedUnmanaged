using System;

namespace Managed
{
    internal class Program
    {
        #region Static members

        private static void Main(string[] args)
        {
            UnmanagedHelper.CreateObject(new Guid("8FB509AE-500E-44C0-9E83-2233A80838F0"), out var result);
        }

        #endregion
    }
}