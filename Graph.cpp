#include <iostream>
#include <vector>
#include <limits>
#include "Graph.h"

Graph::Graph(long int n) { // initialize graph
    if (N < 1)
        std::cerr << "ERROR: The number of nodes is wrong." << std::endl;
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
    if (!(start < N && start > -1 && finish < N && finish > -1))
        std::cerr << "ERROR: start or finish node does not exitst." << std::endl;
    if (distance < 1)
        std::cerr << "WARNING: distance is negative." << std::endl;
    if (!Matrix[start][finish])
        Matrix[start][finish] = distance;
    else
        std::cerr << "WARNING: connection already exitst." << std::endl;
}


void Graph::delConnection(long int start, long int finish){
    if (!(start < N && start > - 1 && finish < N && finish > -1))
        std::cerr << "ERROR: start or finish node does not exist." << std::endl;
    Matrix[start][finish] = 0;
}


void Graph::changeDistance(long int start, long int finish, long int distance){
    if (!(start < N && start > -1 && finish < N && finish > -1))
        std::cerr << "ERROR: start or finish node does not exitst." << std::endl;
    if (distance < 1)
        std::cerr << "WARNING: distance is negative." << std::endl;
    Matrix[start][finish] = distance;
}

