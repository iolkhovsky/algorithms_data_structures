#pragma once

#include <vector>
#include <iostream>

namespace algorithms {
namespace graph {

template<class WeightType>
struct Edge {
    int from;
    int to;
    WeightType distance;
};

template<class WeightType>
class Graph {
 public:
    using AdjacencyList = std::vector<std::vector<Edge<WeightType>>>;
    using Iterator = typename AdjacencyList::const_iterator;
    Graph(int size) : adjacency_list_(size) {}
    void AddEdge(const Edge<WeightType>& edge) {
        adjacency_list_[edge.from].push_back(edge);
    }
    void SetAdjacency(const AdjacencyList& list) {
        adjacency_list_ = list;
    }
    const AdjacencyList& GetAdjacency() const {
        return adjacency_list_;
    }
    int Size() const {
        return static_cast<int>(adjacency_list_.size());
    }
    const std::vector<Edge<WeightType>>& operator[](int id) const {
        return adjacency_list_[id];
    }
    Iterator begin() const {
        return adjacency_list_.begin();
    }
    Iterator end() const {
        return adjacency_list_.end();
    }
 private:
    AdjacencyList adjacency_list_;
};

template<class WeightType>
std::ostream& operator<<(std::ostream& os, const Graph<WeightType> graph) {
    os << "Graph (" << graph.Size() << "):\n";
    int i = 0;
    for (const auto& vertex_desc : graph) {
        os << "Vertex #" << i << "\n";
        for (const auto& edge : vertex_desc)
            os << "\t- " << edge.from << " --> " << edge.to << " [" << edge.distance << "]\n";
        i++;
    }
    return os;
}

}  // graph
}  // algorithms
