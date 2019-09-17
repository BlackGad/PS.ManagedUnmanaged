using System;
using System.Linq;
using Managed.Graphviz;
using Managed.Unmanaged;
using QuickGraph;
using UnmanagedLibrary;

namespace Managed
{
    internal class Program
    {
        #region Static members

        private static ProcessorGraph GraphCreate(int layerCount, int minNodesPerLayer, int maxNodesPerLayer)
        {
            var result = new ProcessorGraph();
            result.AddVertex(Helper.CreateProcessor());

            var random = new Random();

            for (var i = 0; i < layerCount; i++)
            {
                var tailVertices = result.Vertices
                                         .Where(v => !result.OutEdges(v).Any())
                                         .ToList();

                var processorsOnLayer = random.Next(minNodesPerLayer, maxNodesPerLayer);

                for (var j = 0; j < processorsOnLayer; j++)
                {
                    var processor = Helper.CreateProcessor();
                    result.AddVertex(processor);

                    var processorConnectedWithVerticesCount = random.Next(1, tailVertices.Count);
                    for (var k = 0; k < processorConnectedWithVerticesCount; k++)
                    {
                        var processorConnectedWithVertexIndex = random.Next(0, tailVertices.Count);
                        result.AddEdge(new Edge<IProcessor>(tailVertices[processorConnectedWithVertexIndex], processor));
                    }
                }
            }

            return result;
        }

        private static void GraphProcess(ProcessorGraph graph, object block)
        {
            var random = new Random();
            var currentVertex = graph.Vertices.FirstOrDefault(v => !graph.InEdges(v).Any());

            while (currentVertex != null)
            {
                currentVertex.Process(block);

                var followedVertices = graph.Vertices
                                            .Where(v => graph.InEdges(v).Any(e => Equals(e.Source, currentVertex)))
                                            .ToList();

                if (followedVertices.Any())
                {
                    var nextVertexIndex = random.Next(0, followedVertices.Count);
                    currentVertex = followedVertices[nextVertexIndex];
                }
                else
                {
                    currentVertex = null;
                }
            }
        }

        private static string GraphVisualize(ProcessorGraph graph, string[] blockTraceRoute)
        {
            return Graphviz.Graphviz.Format(graph,
                                            new GraphvizConfiguration
                                            {
                                                VertexProcessing = (processor, styles) =>
                                                {
                                                    if (blockTraceRoute.Contains(processor.Id))
                                                    {
                                                        styles.Add("color=\"gold\"");
                                                        styles.Add("style=\"filled\"");
                                                    }
                                                },
                                                EdgeProcessing = (edge, styles) =>
                                                {
                                                    if (blockTraceRoute.Contains(edge.Source.Id) && blockTraceRoute.Contains(edge.Target.Id))
                                                    {
                                                        styles.Add("color=\"green\"");
                                                    }
                                                    else
                                                    {
                                                        styles.Add("style=\"dotted\"");
                                                    }
                                                }
                                            });
        }

        private static void Main(string[] args)
        {
            var graph = GraphCreate(10, 1, 10);

            var allocator = Helper.CreateAllocator();
            var dumper = Helper.CreateDumper();

            var block = allocator.Allocate();
            GraphProcess(graph, block);

            var blockTraceRoute = (string[])dumper.DumpTraceRoute(block);

            var result = dumper.DumpResult(block);

            Console.WriteLine();
            Console.WriteLine("Block route");
            Console.WriteLine($"{string.Join("\n\t\t|\n", blockTraceRoute)}");
            Console.WriteLine();
            Console.WriteLine($"Result: {result}");

            Console.ReadLine();
            var traceGraph = GraphVisualize(graph, blockTraceRoute);
        }

        #endregion
    }
}