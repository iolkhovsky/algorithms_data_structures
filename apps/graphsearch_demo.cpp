#include <iostream>

#include "algorithms/graphsearch.hpp"
#include "prettyprint.hpp"

int main(int argc, char** argv) {
    /*
     /---1---2---3    7-----8
    0         \        \   /
     \---4-----5---6     9
    */
    std::vector<std::vector<int>> graph(10);
    graph[0] = {1, 4};
    graph[1] = {0, 2};
    graph[2] = {1, 3, 5};
    graph[3] = {2};
    graph[4] = {0, 5};
    graph[5] = {4, 2, 6};
    graph[6] = {5};
    graph[7] = {8, 9};
    graph[8] = {7, 9};
    graph[9] = {8, 7};

    std::cout << "BFS starting from 0 vertex:\n";
    std::cout << algorithms::graph::BreadthFirstSearch(graph, 0) << "\n";
    std::cout << "DFS starting from 0 vertex:\n";
    std::cout << algorithms::graph::DepthFirstSearch(graph, 0) << "\n";

    std::cout << "BFS starting from 5 vertex:\n";
    std::cout << algorithms::graph::BreadthFirstSearch(graph, 5) << "\n";
    std::cout << "DFS starting from 5 vertex:\n";
    std::cout << algorithms::graph::DepthFirstSearch(graph, 5) << "\n";

    std::cout << "BFS starting from 9 vertex:\n";
    std::cout << algorithms::graph::BreadthFirstSearch(graph, 9) << "\n";
    std::cout << "DFS starting from 5 vertex:\n";
    std::cout << algorithms::graph::DepthFirstSearch(graph, 9) << "\n";
    return 0;
}