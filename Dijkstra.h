#ifndef Dijkstra_h
#define Dijkstra_h

class Dijkstra{
    public:
        Dijkstra(Graph &Graph);
        std::vector< long int > findDistances( long int start );
        std::vector< long int > restoreRoute( long int start, long int finish);

        void cleanUp();
        
    private:
        std::vector< long int > Distance;
        std::vector< long int > Parent;
        
        std::priority_queue< std::pair< long int, long int > > Queue;
};

#endif
