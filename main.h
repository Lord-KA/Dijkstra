#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <utility>
#include <algorithm>
#include "Graph.h"
#include "Dijkstra.h"

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


