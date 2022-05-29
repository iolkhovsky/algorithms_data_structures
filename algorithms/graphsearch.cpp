#include "graphsearch.hpp"

#include <queue>
#include <stack>

namespace algorithms {
namespace graph {

std::vector<int> BreadthFirstSearch(std::vector<std::vector<int>> graph, int start_vertex) {
    int vertices_cnt = static_cast<int>(graph.size());
    if (start_vertex < 0 || start_vertex > vertices_cnt - 1)
        return {};
    
    std::vector<int> explored_vertices;
    std::vector<bool> explored(vertices_cnt, false);
    std::queue<int> fifo;

    fifo.push(start_vertex);
    explored[start_vertex] = true;
    while (!fifo.empty()) {
        int current_vertex = fifo.front();
        fifo.pop();
        explored_vertices.push_back(current_vertex);

        for (const auto& next_vertex : graph[current_vertex]) {
            if (!explored[next_vertex]) {
                fifo.push(next_vertex);
                explored[next_vertex] = true;
            }
        }
    }

    return explored_vertices;
}

std::vector<int> DepthFirstSearch(std::vector<std::vector<int>> graph, int start_vertex) {
    int vertices_cnt = static_cast<int>(graph.size());
    if (start_vertex < 0 || start_vertex > vertices_cnt - 1)
        return {};
    
    std::vector<int> explored_vertices;
    std::vector<bool> explored(vertices_cnt, false);
    std::stack<int> lifo;

    lifo.push(start_vertex);
    explored[start_vertex] = true;
    while (!lifo.empty()) {
        int current_vertex = lifo.top();
        lifo.pop();
        explored_vertices.push_back(current_vertex);

        for (const auto& next_vertex : graph[current_vertex]) {
            if (!explored[next_vertex]) {
                lifo.push(next_vertex);
                explored[next_vertex] = true;
            }
        }
    }

    return explored_vertices;
}

}  // graph
}  // algorithms