using System;
using Managed.Extensions;
using QuickGraph;
using UnmanagedLibrary;

namespace Managed.Graphviz
{
    public class ProcessorGraph : BidirectionalGraph<IProcessor, IEdge<IProcessor>>, IDisposable
    {
        #region Constructors

        public ProcessorGraph()
            : base(false)
        {
        }

        #endregion

        #region IDisposable Members

        public void Dispose()
        {
            foreach (var processor in Vertices)
            {
                try
                {
                    processor.Free();
                }
                catch
                {
                    //Nothing
                }
            }
        }

        #endregion
    }
}