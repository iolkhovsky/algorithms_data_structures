#pragma once

#include <vector>

namespace algorithms {
namespace sorting {

template<class T>
void merge(std::vector<T>& part1, std::vector<T>& part2, typename std::vector<T>::iterator out) {
    int total_size = static_cast<int>(part1.size() + part2.size());
    auto it1 = part1.begin();
    auto it2 = part2.begin();
    for (int i = 0; i < total_size; i++) {
        if (it1 != part1.end() && it2 != part2.end()) {
            if (*it1 < *it2) {
                *out++ = *it1++;
            } else {
                *out++ = *it2++;
            }
        } else if (it1 != part1.end()) {
            *out++ = *it1++;  
        } else {
            *out++ = *it2++;
        }
    }
}

template<class T>
void mergesort(std::vector<T>& data) {
    int size = static_cast<int>(data.size());
    if (size < 2)
        return;
    int border = size / 2;

    std::vector<T> part1(data.begin(), data.begin() + border);
    std::vector<T> part2(data.begin() + border, data.end());
    mergesort(part1);
    mergesort(part2);
    merge(part1, part2, data.begin());
}

}  // sorting
}  // algorithms
