#ifndef Dijkstra_h
#define Dijkstra_h

#include <vector>
#include <queue>
#include "Graph.h"

class Dijkstra{
    public:
        Dijkstra(Graph *graph);
        std::vector< long int > findDistances( long int start );
        std::vector< long int > restoreRoute( long int start, long int finish );

        void cleanUp();
        
    private:
        std::vector< long int > Distance;
        std::vector< long int > Parent;

        Graph *graph;
        
        std::priority_queue< std::pair< long int, long int > > Queue;
};

#endif
