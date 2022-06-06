#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <unordered_set>
#include <unordered_map>

template<class T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& data) {
    os << "[";
    for (const auto& item : data) {
        os << item << ", ";
    }
    os << "]";
    return os;
}

template<class T>
std::ostream& operator<<(std::ostream& os, const std::list<T>& data) {
    os << "[";
    for (const auto& item : data) {
        os << item << " -> ";
    }
    os << "]";
    return os;
}

template<class First, class Second>
std::ostream& operator<<(std::ostream&os, const std::pair<First, Second>& pair) {
    os << "( " << pair.first << ", " << pair.second << " )";
    return os;
}

template<class First, class Second>
std::ostream& operator<<(std::ostream&os, const std::unordered_map<First, Second>& map) {
    os << "{";
    for (const auto& pair : map)
        os << pair << ", ";
    os << "}";
    return os;
}

template<class T>
std::ostream& operator<<(std::ostream&os, const std::unordered_set<T>& set) {
    os << "{";
    for (const auto& item : set)
        os << item << ", ";
    os << "}";
    return os;
}