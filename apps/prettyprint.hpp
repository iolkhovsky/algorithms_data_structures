#pragma once

#include <iostream>
#include <vector>

template<class T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& data) {
    os << "[";
    for (const auto& item : data) {
        os << item << ", ";
    }
    os << "]";
    return os;
}
