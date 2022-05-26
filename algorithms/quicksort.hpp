#pragma once

#include <vector>

#include "algorithms/utils.hpp"

namespace algorithms {
namespace sorting {

template<class T>
void recursively_quicksort(T* data, int size, utils::UniformRandomIntGenerator& gen) {
    if (size < 2)
        return;
    int pivot = gen.generate(0, size);
    const T pivot_value = data[pivot];
    std::swap(data[0], data[pivot]);
    int border_idx = 0;
    for (int i = 1; i < size; i++) {
        if (data[i] < pivot_value) {
            border_idx++;
            std::swap(data[border_idx], data[i]);
        }
    }
    std::swap(data[0], data[border_idx]);
    recursively_quicksort(data, border_idx, gen);
    recursively_quicksort(data + border_idx + 1, size - (border_idx + 1), gen);
}    

template<class T>
void quicksort(std::vector<T>& data) {
    utils::UniformRandomIntGenerator gen;
    int size = static_cast<int>(data.size());
    recursively_quicksort(data.data(), size, gen);
}

}  // sorting
}  // algorithms
