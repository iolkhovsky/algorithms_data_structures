#pragma once

#include <vector>

namespace structures {

constexpr int InitialBufferSize = 8;

template<class T>
struct More {
    bool operator()(const T& lhs, const T& rhs) const {
        return lhs > rhs;
    }
};

template<class T>
struct Less {
    bool operator()(const T& lhs, const T& rhs) const {
        return lhs < rhs;
    }
};

template<class T, class Comparator>
class Heap {
 public:
    Heap()
    : size(0)
    , buffer(InitialBufferSize) {}

    void Push(const T& item) {
        if (size + 1 > static_cast<int>(buffer.size())) {
            buffer.resize(buffer.size() * 2);
        }
        buffer[size] = item;
        propagateUp(size);
        size++;
    }

    T Pop() {
        T out = buffer[0];
        std::swap(buffer[0], buffer[size - 1]);
        size--;
        propagateDown(0);
        return out;
    }

    T Top() const {
        return buffer[0];
    }

    int Size() const {
        return size;
    }

    bool Empty() const {
        return size == 0;
    }

    std::vector<T> getStorage() const {
        return {buffer.begin(), buffer.end() + size};
    }

 private:
    int parentIdx(int idx) {
        if (idx < 1)
            return -1;
        return (idx + 1) / 2 - 1;
    }

    int childLeftIdx(int idx) {
        return (idx + 1) * 2 - 1;
    }

    int childRightIdx(int idx) {
        return (idx + 1) * 2 + 1 - 1;
    }

    bool validIdx(int idx) {
        return (idx >= 0) && (idx < size);
    }

    void propagateUp(int target_idx) {
        int parent_idx = parentIdx(target_idx);
        while (validIdx(parent_idx)) {
            if (!comp(buffer[parent_idx], buffer[target_idx])) {
                std::swap(buffer[parent_idx], buffer[target_idx]);
                target_idx = parent_idx;
                parent_idx = parentIdx(target_idx);
            } else {
                break;
            }
        }
    }

    void propagateDown(int target_idx) {
        int left_child_idx, right_child_idx;

        auto update = [&] () {
            left_child_idx = childLeftIdx(target_idx);
            right_child_idx = childRightIdx(target_idx);
        };

        auto node_is_stable = [&] () {
            bool ok = true;
            if (validIdx(left_child_idx)) {
                ok &= comp(buffer[target_idx], buffer[left_child_idx]);
            }
            if (validIdx(right_child_idx)) {
                ok &= comp(buffer[target_idx], buffer[right_child_idx]);
            }
            return ok;
        };

        auto go_left = [&] () {
            if (validIdx(left_child_idx) && validIdx(right_child_idx)) {
                return comp(buffer[left_child_idx], buffer[right_child_idx]);
            } else if (validIdx(left_child_idx)) {
                return true;
            } else {
                return false;
            }
        };

        update();
        while(!node_is_stable()) {
            if (go_left()) {
                std::swap(buffer[target_idx], buffer[left_child_idx]);
                target_idx = left_child_idx;
            } else {
                std::swap(buffer[target_idx], buffer[right_child_idx]);
                target_idx = right_child_idx;
            }
            update();
        }
    }

    int size;
    std::vector<T> buffer;
    Comparator comp;
};


template<class T, class Comp>
std::ostream& operator<<(std::ostream& os, const Heap<T, Comp>& heap) {
    std::vector<T> data = heap.getStorage();
    int element_per_level = 1;
    int printed = 0;
    os << "Heap data:\n";
    while (printed < heap.Size()) {
        for (int i = printed; i < std::min(printed + element_per_level, heap.Size()); i++)
            os << data[i] << ", ";
        os << "\n";
        printed += element_per_level;
        element_per_level *= 2;
    }
    return os;
}


}  // structures 
