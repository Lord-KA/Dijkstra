#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
#include "Dijkstra.h"
#include "Graph.h"

Dijkstra::Dijkstra(Graph *graph_){
    graph = graph_;
    for (long int i = 0; i < graph->N; ++i){
        Distance.push_back(INF);
        Parent.push_back(-1);
    }
}

void Dijkstra::cleanUp(){
    for (long int i = 0; i < graph->N; ++i){
        Distance[i] = INF;
        Parent[i] = -1;
    }
    while (Queue.size())
        Queue.pop();
}


std::vector<long int> Dijkstra::restoreRoute(long int start, long int finish){
    long int N = graph->N;
    if (!(start < N && start > -1 && finish < N && finish > -1))
        std::cerr << "ERROR: start or finish node does not exitst." << std::endl;

    long int current = finish;
    std::vector<long int> Route;
    while (current != -1 && current != start){
        Route.push_back(current);
        current = Parent[current];
    }
    Route.push_back(start);
    if (current == -1)
        std::cerr << "ERROR: The destination is inaccessible." << std::endl;
    else if (current == start){
        std::reverse(Route.begin(), Route.end());
        return Route;
    }
    else
        std::cerr << "ERROR: Something has gone wrong." << std::endl;
}   


std::vector<long int> Dijkstra::findDistances(long int start){
    if (!(start < graph->N && start > -1))
        std::cerr << "ERROR: start node does not exitst." << std::endl;

    cleanUp();
    Distance[start] = 0;
    for (long int i=0; i < graph->N; ++i)
        if (graph->Matrix[start][i] && start != i)
            Queue.push(std::make_pair(graph->Matrix[start][i], i));
    long int current = start;
    while (Queue.size()){
        for (long int i=0; i < graph->N; ++i)
            if (i != current && graph->Matrix[current][i] && graph->Matrix[current][i] + Distance[current] < Distance[i]){
                Distance[i] = graph->Matrix[current][i] + Distance[current];
                Parent[i] = current;
                //std::cout << Distance[i] << ' ' << i << std::endl;
                Queue.push(std::make_pair(graph->Matrix[current][i], i));
            }
        
        current = Queue.top().second;
        Queue.pop();
    }
    return Distance;
}
