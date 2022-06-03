#pragma once

#include "algorithms/graph.hpp"

#include <queue>

namespace algorithms {
namespace graph {

template<class T>
bool operator<(const std::pair<T, Edge<T>>& lhs, const std::pair<T, Edge<T>>& rhs) {
    return lhs.first + lhs.second.distance > rhs.first + rhs.second.distance;
}

template<class T>
std::vector<std::pair<T, int>> DijkstraSHortestPath(const Graph<T>& graph, int start_vertex) {
    std::vector<std::pair<T, int>> res(graph.Size());
    for (auto& [distance, prev_vertex] : res) {
        distance = -1;
        prev_vertex = -1;
    }
    res[start_vertex] = {0, -1};

    std::priority_queue<std::pair<T, Edge<T>>> edge_heap;
    for (const auto& edge : graph[start_vertex])
        edge_heap.push({res[start_vertex].first, edge});
    
    while(!edge_heap.empty()) {
        auto [distance, edge] = edge_heap.top();
        edge_heap.pop();
        if (res[edge.to].first < 0) {
            res[edge.to] = {distance + edge.distance, edge.from};
            for (const auto& new_edge : graph[edge.to]) {
                edge_heap.push({res[edge.to].first, new_edge});
            }
        }
    }

    return res;
}

}
}