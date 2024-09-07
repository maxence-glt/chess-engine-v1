#include <gtest/gtest.h>

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
    ASSERT_EQ(3, 4) << "test1";
    ASSERT_EQ(3, 3);
}

TEST(HelloTest, OtherBasicAssertions) {
    ASSERT_EQ(4, 4) << "test2";
    ASSERT_EQ(3, 3);
}
