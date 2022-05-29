#include <gtest/gtest.h>

#include "algorithms/mergesort.hpp"
#include "algorithms/quicksort.hpp"

TEST(MergeSort, Basic) {
    std::vector<int> sample = {0, 2, -3, 8, 7, 9, 11, 19, -5, -4};
    std::vector<int> target = {-5, -4, -3, 0, 2, 7, 8, 9, 11, 19};
    algorithms::sorting::mergesort(sample);
    EXPECT_EQ(sample, target);
}

TEST(QuickSort, Basic) {
    std::vector<int> sample = {0, 2, -3, 8, 7, 9, 11, 19, -5, -4};
    std::vector<int> target = {-5, -4, -3, 0, 2, 7, 8, 9, 11, 19};
    algorithms::sorting::quicksort(sample);
    EXPECT_EQ(sample, target);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv); 
    return RUN_ALL_TESTS();
}
