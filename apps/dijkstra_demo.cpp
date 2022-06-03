#include <iostream>

#include "algorithms/dijkstra.hpp"
#include "prettyprint.hpp"

using namespace algorithms::graph;

int main(int argc, char** argv) {
    Graph<float> graph(4);
    /* <1>"""(1)"""<6>
      /       |      \
     (0)     <2>     (2)
      \       |      /
       <4>___(3)___<3>
    */
    graph.AddEdge(Edge<float>{0, 1, 1.});
    graph.AddEdge(Edge<float>{0, 3, 4.});
    graph.AddEdge(Edge<float>{1, 3, 2.});
    graph.AddEdge(Edge<float>{1, 2, 6.});
    graph.AddEdge(Edge<float>{3, 2, 3.});
    std::cout << graph << "\n";

    std::vector<std::pair<float, int>> paths = DijkstraSHortestPath(graph, 0);

    auto extract_path = [&paths] (int target_vertex) {
        std::vector<int> path;
        int next_vertex = target_vertex;
        while (next_vertex != -1) {
            path.push_back(next_vertex);
            next_vertex = paths[next_vertex].second;
        }
        return std::vector<int>(path.rbegin(), path.rend());
    };

    for (int i = 0; i < graph.Size(); i++) {
        std::cout << "Shortest path to vertex #" << i << ":\n";
        std::cout <<  extract_path(i) << "\n";
    }
    
    return 0;
}