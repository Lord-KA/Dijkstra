#ifndef Graph_h
#define Graph_h

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

        std::priority_queue< std::pair< long int, long int > > Queue;

        friend class Dijkstra;
};

#endif
