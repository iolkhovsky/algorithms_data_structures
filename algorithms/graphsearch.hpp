#pragma once

#include <vector>

namespace algorithms {
namespace graph {

std::vector<int> BreadthFirstSearch(std::vector<std::vector<int>> graph, int start_vertex);
std::vector<int> DepthFirstSearch(std::vector<std::vector<int>> graph, int start_vertex);

}  // graph
}  // algorithms