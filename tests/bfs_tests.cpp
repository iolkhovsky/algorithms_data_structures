#include <gtest/gtest.h>
#include <unordered_set>

#include "algorithms/graphsearch.hpp"

TEST(BreadthFirstSearch, Basic) {
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

    auto result = algorithms::graph::BreadthFirstSearch(graph, 0);
    std::unordered_set<int> target = {0, 1, 2, 3, 4, 5, 6};
    EXPECT_EQ(
        std::unordered_set<int>(result.begin(), result.end()),
        target
    );

    result = algorithms::graph::BreadthFirstSearch(graph, 8);
    target = {7, 8, 9};
    EXPECT_EQ(
        std::unordered_set<int>(result.begin(), result.end()),
        target
    );
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv); 
    return RUN_ALL_TESTS();
}
