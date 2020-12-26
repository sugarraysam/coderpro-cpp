#include "challenges/cp0/cp0.h"
#include "gtest/gtest.h"

TEST(CP0, Addition)
{
    ASSERT_EQ(4, add(3, 1));
    ASSERT_EQ(7, add(7, 0));
    ASSERT_EQ(-3, add(3, -6));
}
