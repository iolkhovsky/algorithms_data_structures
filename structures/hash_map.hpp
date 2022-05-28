#pragma once

#include <list>
#include <memory>
#include <utility>
#include <vector>

namespace structures {

constexpr int SparsityCoefficient = 2;
constexpr int InitialBucketsSize = 4;

struct IntHasher {
    size_t operator()(const int& value) const {
        return static_cast<size_t>(value);
    }
};

template<class Key, class Value, class Hasher>
class HashMap {
public:
    struct Item {
        Key key;
        Value value;
        typename std::list<Item*>::iterator it;
    };

    using ListIterator = typename std::list<Item*>::const_iterator;

    class Iterator {
    public:
        explicit Iterator(ListIterator it) : _it(it) {}
        bool operator==(const Iterator& other) const { return _it == other._it; }
        bool operator!=(const Iterator& other) const { return _it != other._it; }
        std::pair<Key, Value> operator*() const { return {(*_it)->key, (*_it)->value}; }
        Iterator operator++() { return Iterator(_it++); }
    private:
        ListIterator _it;
    };

    explicit HashMap()
    : _buckets(InitialBucketsSize) {
        initBuckets();
    }

    void Add(const Key& key, const Value& value) {
        if ((!Has(key)) && (_items.size() * SparsityCoefficient >= _buckets.size()) ) {
            reallocateBuckets();
        } 
        size_t bucket_id = getBucketId(key);
        _items.push_back(nullptr);
        _buckets[bucket_id] = {key, value, std::prev(_items.end())};
        _items.back() = &_buckets[bucket_id];
    }

    Value Get(const Key& key) const {
        if (!Has(key))
            throw std::runtime_error("Key doesn't exist");
        size_t bucket_id = getBucketId(key);
        return _buckets[bucket_id].value;
    }

    bool Has(const Key& key) const {
        size_t bucket_id = getBucketId(key);
        return _buckets[bucket_id].it != _items.end();
    }

    void Erase(const Key& key) {
        size_t bucket_id = getBucketId(key);
        _items.erase(_buckets[bucket_id].it);
        _buckets[bucket_id].it = _items.end();
    }

    Iterator begin() const {
        return Iterator(_items.begin());
    }

    Iterator end() const { 
        return Iterator(_items.end());
    }

private:
    size_t getBucketId(const Key& key) const {
        return _hasher(key) % _buckets.size();
    }

    void initBuckets() {
        for (auto& bucket: _buckets) {
            bucket.it = _items.end();
        }
    }

    void reallocateBuckets() {
        std::vector<std::pair<Key, Value>> existing_items;
        for (const auto& [key, value] : *this) {
            existing_items.push_back({key, value});
        }
        _buckets.resize(_buckets.size() * 2);
        _items.clear();
        initBuckets();
        for (const auto& [key, value] : existing_items)
            Add(key, value);
    }

    Hasher _hasher;
    std::vector<Item> _buckets;
    std::list<Item*> _items;
};

}  // structures 
