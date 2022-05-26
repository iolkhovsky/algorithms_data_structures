#pragma once

#include <random>

namespace algorithms {
namespace utils {

class UniformRandomIntGenerator {
public:
    explicit UniformRandomIntGenerator()
    : rng_(dev_()) {}
    int generate(int min, int max);
private:
    std::random_device dev_;
    std::mt19937 rng_;
    std::uniform_int_distribution<std::mt19937::result_type> dist_;
};

}  // utils
}  // algorithms
