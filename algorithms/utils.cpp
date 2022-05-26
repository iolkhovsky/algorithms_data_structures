#include "utils.hpp"

namespace algorithms {
namespace utils {

int UniformRandomIntGenerator::generate(int min, int max) {
    return min + (dist_(rng_)) % (max - min);
}

}  // utils
}  // algorithms
