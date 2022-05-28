#include <functional>
#include <iostream>
#include <string>

#include "structures/hash_map.hpp"
#include "prettyprint.hpp"

template<class Key, class Value, class Hasher>
std::ostream& operator<<(std::ostream& os, const structures::HashMap<Key, Value, Hasher>& map) {
    os << "structures::HashMap: {\n";
    for (const auto& item : map)
        os << "\t" << item << ",\n";
    os << "}\n";
    return os;
}

int main(int argc, char** argv) {
    structures::HashMap<int, std::string, structures::IntHasher> map;
    std::cout << map << "\n";
    map.Add(2, "foo");
    map.Add(4, "bar");
    std::cout << map << "\n";
    map.Add(7, "qwerty");
    std::cout << map << "\n";
    map.Add(-3, "foobar");
    std::cout << map << "\n";
    map.Erase(7);
    std::cout << map << "\n";

    structures::HashMap<std::string, int, std::hash<std::string>> map2;
    map2.Add("foo", 7);
    map2.Add("bar", 9);
    std::cout << map2 << "\n";
    map2.Erase("foo");
    std::cout << map2.Has("bar") << "\n";
    std::cout << map2 << "\n";

    return 0;
}