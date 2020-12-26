#include "challenges/cp0/cp0.h"
#include "gtest/gtest.h"

TEST(CP0, Addition)
{
    ASSERT_EQ(5, add(2, 3));
    ASSERT_EQ(4, add(3, 1));
}
