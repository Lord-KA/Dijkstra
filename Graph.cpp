#include <iostream>
#include <vector>
#include <limits>
#include "Graph.h"

Graph::Graph(long int n) { // initialize graph
    N = n;

    for (long int i = 0; i < N; ++i){
        Matrix.push_back(std::vector<long int>());
        Distance.push_back(std::vector<long int>());
        for (long int j = 0; j < N; ++j){
            Matrix[i].push_back(0);
            Distance[i].push_back(INF);
        }
    }
}


void Graph::addConnection(long int start, long int finish, long int distance)
{
    if (!Matrix[start][finish])
        Matrix[start][finish] = distance;
    else
        std::cerr << "WARNING: connection already exitst." << std::endl;
}


void Graph::delConnection(long int start, long int finish){
    Matrix[start][finish] = 0;
}


void Graph::changeDistance(long int start, long int finish, long int distance){
    Matrix[start][finish] = distance;
}
