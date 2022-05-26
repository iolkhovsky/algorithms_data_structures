#include <vector>

#include "algorithms/mergesort.hpp"
#include "algorithms/quicksort.hpp"
#include "prettyprint.hpp"

int main(int argc, char** argv) {
    std::vector<int> example = {0, 2, -3, 8, 7, 9, 11, 19, -5, -4};
    std::cout << "Initial unsorted data:\n" << example << "\n";
    algorithms::sorting::mergesort(example);
    std::cout << "Sorted data (mergesort):\n" << example << "\n";

    example = {0, 2, -3, 8, 7, 9, 11, 19, -5, -4};
    algorithms::sorting::quicksort(example);
    std::cout << "Sorted data (quicksort):\n" << example << "\n";
    return 0;
}