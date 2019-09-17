using System.Collections.Generic;
using System.Linq;
using System.Text;
using UnmanagedLibrary;

namespace Managed.Graphviz
{
    public static class Graphviz
    {
        #region Static members

        public static string Format(ProcessorGraph graph, GraphvizConfiguration configuration = null)
        {
            configuration = configuration ?? new GraphvizConfiguration();
            var indent = "".PadLeft(configuration.IndentStep);

            var builder = new StringBuilder();
            builder.AppendLine("digraph G");
            builder.AppendLine("{");

            var vertices = graph.Vertices.ToList();
            foreach (var vertex in vertices)
            {
                var attributes = new List<string>();

                var shape = "box";

                attributes.Add($"label=\"{vertex.Id}\"");
                attributes.Add($"shape=\"{shape}\"");

                configuration.VertexProcessing?.Invoke(vertex, attributes);

                builder.AppendLine(indent + $"{GetVertexId(vertex)} [{string.Join(", ", attributes)}]");
            }

            builder.AppendLine();

            var edges = graph.Edges.ToList();
            foreach (var edge in edges)
            {
                var attributes = new List<string>();

                configuration.EdgeProcessing?.Invoke(edge, attributes);

                builder.AppendLine(indent + $"{GetVertexId(edge.Source)} -> {GetVertexId(edge.Target)} [{string.Join(", ", attributes)}]");
            }

            builder.AppendLine();

            builder.AppendLine("}");
            return builder.ToString();
        }

        private static string GetVertexId(IProcessor task)
        {
            return "_" + task.Id
                             .Replace("-", "")
                             .Replace("{", "")
                             .Replace("}", "");
        }

        #endregion
    }
}