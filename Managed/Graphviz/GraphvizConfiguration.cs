using System;
using System.Collections.Generic;
using QuickGraph;
using UnmanagedLibrary;

namespace Managed.Graphviz
{
    public class GraphvizConfiguration
    {
        #region Constructors

        public GraphvizConfiguration()
        {
            IndentStep = 4;
        }

        #endregion

        #region Properties

        public Action<IEdge<IProcessor>, IList<string>> EdgeProcessing { get; set; }
        public IFormatProvider FormatProvider { get; set; }
        public int IndentStep { get; set; }
        public Action<IProcessor, IList<string>> VertexProcessing { get; set; }

        #endregion
    }
}