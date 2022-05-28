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

template<class First, class Second>
std::ostream& operator<<(std::ostream&os, const std::pair<First, Second>& pair) {
    os << "( " << pair.first << ", " << pair.second << " )";
    return os;
}