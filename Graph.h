#ifndef Graph_h
#define Graph_h

#include <vector>
#include <limits>


const size_t INF = std::numeric_limits<long int>::max(); // Infinity

class Graph {
    public:
        Graph( long int N );

        void addConnection( long int start, long int finish, long int distance );
        void delConnection( long int start, long int finish );
        void changeDistance( long int start, long int finish, long int distance );

    private:
        long int N;

        std::vector< std::vector< long int > > Matrix;

        std::vector< std::vector< long int > > Distance;

        friend class Dijkstra;
};

#endif
