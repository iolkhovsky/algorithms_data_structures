#include <iostream>

#include "structures/heap.hpp"
#include "prettyprint.hpp"

using namespace structures;

int main(int argc, char** argv) {
    std::vector<int> data = {1, 5, 2, 9, 6, 4, 11, -3, 6, -1, 17};
    std::cout << "Unsorted data:\n" << data << "\n";

    Heap<int, Less<int>> heap;
    for (const auto& item : data)
        heap.Push(item);
    
    std::cout << heap;

    std::cout << "Sorted (non-descending order):\n";
    while (!heap.Empty()) {
        std::cout << heap.Pop() << ", ";
    }
    std::cout << "\n";

    Heap<int, More<int>> heap2;
    for (const auto& item : data)
        heap2.Push(item);
    
    std::cout << heap2;
    
    std::cout << "Sorted (descending order):\n";
    while (!heap2.Empty()) {
        std::cout << heap2.Pop() << ", ";
    }
    std::cout << "\n";
    
    return 0;
}