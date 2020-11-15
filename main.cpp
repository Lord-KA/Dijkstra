#include "main.h"

int main()
{
    const int n = 6;
    const int start = 0, finish = 3;
    Graph graph(n);

    graph.addConnection(0, 1, 30);
    graph.addConnection(0, 4, 10);
    graph.addConnection(4, 5, 10);
    graph.addConnection(5, 2, 10);
    graph.addConnection(1, 3, 30);
    graph.addConnection(1, 2, 10);
    graph.addConnection(2, 3, 5);
    Dijkstra dijkstra(graph);
    dijkstra.findDistance(start);
    std::cout << graph.Matrix << std::endl;
    std::cout << dijkstra.Distance << std::endl;
    std::cout << dijkstra.restoreRoute(start, finish) << std::endl;
    return 0;
}
