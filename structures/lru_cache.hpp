#pragma once

#include <list>
#include <unordered_map>

namespace structures {

template<class K, class V>
class LruCache {
 public:
    using Storage = std::unordered_map<K, std::pair<V, typename std::list<K>::iterator>>;

    LruCache(int size)
    : size(size) {}

    bool Has(const K& key) const {
        return data.count(key);
    }

    void Remove(const K& key) {
        auto [value, it] = data[key];
        order.erase(it);
        data.erase(key);
    }

    bool Add(const K& key, const V& value) {
        if (Has(key)) {
            Remove(key);
        }
        order.push_front(key);
        data[key] = {value, order.begin()};
        if (static_cast<int>(order.size()) > size) {
            Remove(order.back());
        }
    }

    V Get(const K& key) {
        V value = data[key].first;
        Remove(key);
        Add(key, value);
        return value;
    }

    int Size() const {
        return static_cast<int>(data.size());
    }

    std::list<K> GetStoredKeys() const {
        return order;
    }

 private:
    const int size;
    Storage data;
    std::list<K> order;
};


}  // structures 
