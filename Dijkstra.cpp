Dijkstra::Dijkstra(Graph &Graph){
    graph = &Graph;
    for (int i = 0; i < Graph.N; ++i){
        Distance[i] = INF;
        Parent[i] = -1;
    }
}


std::vector<long int> Dijkstra::restoreRoute(long int start, long int finish){
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


void Dijkstra::findDistance(long int start){
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
