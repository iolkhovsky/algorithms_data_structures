#include <iostream>

#include "structures/lru_cache.hpp"
#include "prettyprint.hpp"

using namespace structures;

int main(int argc, char** argv) {
    std::vector<std::pair<std::string, int>> data = {
        {"seven", 7},
        {"one", 0},
        {"one", 1},
        {"two", 2},
        {"three", 3},
        {"four", 4},
        {"one", -1},
    };
    std::cout << "Test data:\n" << data << "\n";

    LruCache<std::string, int> cache(4);
    std::cout << "Cache items: " << cache.GetStoredKeys() << "\n";

    for (const auto& pair : data) {
        cache.Add(pair.first, pair.second);
        std::cout << "Cache items: " << cache.GetStoredKeys() << "\n";
    }

    std::cout << "cache.Get('two'): " << cache.Get("two") << "\n";
    std::cout << "Cache items: " << cache.GetStoredKeys() << "\n";

    cache.Add("five", 5);
    std::cout << "cache.Has('five'): " << cache.Has("five") << "\n";
    std::cout << "Cache items: " << cache.GetStoredKeys() << "\n";

    std::cout << "cache.Get('one')" << cache.Get("one") << "\n";
    std::cout << "Cache items: " << cache.GetStoredKeys() << "\n";
        
    return 0;
}