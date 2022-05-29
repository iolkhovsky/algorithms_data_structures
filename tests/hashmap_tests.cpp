#include <gtest/gtest.h>

#include "structures/hash_map.hpp"

TEST(HashMap, Basic) {
    structures::HashMap<int, std::string, structures::IntHasher> map;
    EXPECT_FALSE(map.Has(1));
    map.Add(1, "one");
    EXPECT_TRUE(map.Has(1));
    EXPECT_EQ(map.Get(1), "one");
    map.Erase(1);
    EXPECT_FALSE(map.Has(1));
}

TEST(HashMap, Exceptions) {
    structures::HashMap<int, std::string, structures::IntHasher> map;
    EXPECT_THROW(
        map.Get(1),
        std::runtime_error
    );
}

TEST(HashMap, Iterators) {
    structures::HashMap<int, std::string, structures::IntHasher> map;
    map.Add(1, "one");
    auto it = map.begin();
    EXPECT_EQ((*it).first, 1);
    EXPECT_EQ((*it).second, "one");
    ++it;
    EXPECT_EQ(it, map.end());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv); 
    return RUN_ALL_TESTS();
}
