#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <utility>
#include <algorithm>

const size_t INF = std::numeric_limits<long int>::max();

// cout overloading for pretty vector outp
template<typename T> 
std::ostream& operator<<(std::ostream &out, const std::vector<T> &a)
{
    for (const auto &x : a)
         out << x << " ";
    out << "\n";
    return out;
}


// cout overloading for pretty two-dimensional vector outp
template<typename T>
std::ostream& operator<<(std::ostream &out, const std::vector<std::vector<T>> &a)
{
    for (const std::vector<T> &x : a)
    {
            for (const auto &w : x)
                out << " " << w;
            out << "\n";
        }
    return out;
}



class Graph {
    public:
        Graph(long int N);

        void Dijkstra(long int start); // function to find the distance to a node using Dijkstra algorithm
        std::vector< long int > restoreRoute(long int start, long int finish);

        void addConnection(long int start, long int finish, long int distance); // function to add connections to the Matrix

        void cleanUp(); // function to clear Distance and Queue before starting another Dijkstra


    private:
        long int N;
        
        std::vector<std::vector<long int>> Matrix;  // A matrix with weights

        std::vector<long int> Distance;  // Final min distance from start
        std::vector<long int> Parent; // Parent for each node, is used to restore the route
        
        std::priority_queue<std::pair<long int, long int>> Queue; // a priority queue for nodes of current interest
};


Graph::Graph(long int n) { // initialize graph
    N = n;

    for (long int i = 0; i < N; ++i){
        Distance.push_back(INF);
        Parent.push_back(-1);
    }   
    for (long int i = 0; i < N; ++i){
        Matrix.push_back(std::vector<long int>());
        for (long int j = 0; j < N; ++j)
            Matrix[i].push_back(0);
    }
}


void Graph::addConnection(long int start, long int finish, long int distance)
{
    Matrix[start][finish] = distance;
}


void Graph::cleanUp(){ 
    for (long int i = 0; i < N; ++i){
        Distance[i] = INF;
        Parent[i] = -1;
    }
    while (Queue.size())
        Queue.pop();

}


std::vector<long int> Graph::restoreRoute(long int start, long int finish){
    long int current = finish;
    std::vector<long int> Route;
    while (current != -1 && current != start){
        Route.push_back(current);
        current = Parent[current];
    }
    Route.push_back(start);
    if (current == -1)
        std::cout << "ERROR: The destination is inaccessible." << std::endl;
    else if (current == start){
        std::reverse(Route.begin(), Route.end());
        return Route;
    }
    else
        std::cout << "ERROR: Something has gone wrong." << std::endl;
}   


void Graph::Dijkstra(long int start){
    cleanUp();
    Distance[start] = 0;
    for (long int i=0; i < N; ++i)
        if (Matrix[start][i] && start != i)
            Queue.push(std::make_pair(Matrix[start][i], i));
    long int current = start;
    while (Queue.size()){
        for (long int i=0; i < N; ++i)
            if (i != current && Matrix[current][i] && Matrix[current][i] + Distance[current] < Distance[i]){
                Distance[i] = Matrix[current][i] + Distance[current];
                Parent[i] = current;
                //std::cout << Distance[i] << ' ' << i << std::endl;
                Queue.push(std::make_pair(Matrix[current][i], i));
            }
        
        current = Queue.top().second;
        Queue.pop();
    }
}




int main()
{
    const int n = 6;
    const int start = 0, finish = 3;
    Graph graph = Graph(n);

    graph.addConnection(0, 1, 30);
    graph.addConnection(0, 4, 10);
    graph.addConnection(4, 5, 10);
    graph.addConnection(5, 2, 10);
    graph.addConnection(1, 3, 30);
    graph.addConnection(1, 2, 10);
    graph.addConnection(2, 3, 5);
    graph.Dijkstra(start);
    //std::cout << graph.Matrix << std::endl;
    //std::cout << graph.Distance << std::endl;
    //
    std::cout << graph.restoreRoute(start, finish) << std::endl;
    return 0;
}
