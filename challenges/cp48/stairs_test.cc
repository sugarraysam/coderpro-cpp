#include "challenges/cp48/stairs.h"
#include "gtest/gtest.h"

struct Case
{
    int n;
    int expected;
};

std::vector<Case> TestCases = {
    Case{n : 0, expected : 1},
    Case{n : 1, expected : 1},
    Case{n : 2, expected : 2},
    Case{n : 5, expected : 8},
    Case{n : 10, expected : 89},
    Case{n : 45, expected : 1836311903},
};

TEST(CP48, TestStairsWithCache)
{
    for (auto &tc : TestCases)
    {
        Stairs s{tc.n};
        ASSERT_EQ(s.solve_with_cache(), tc.expected);
    }
}

TEST(CP48, TestStairsWithoutCache)
{
    for (auto &tc : TestCases)
    {
        Stairs s{tc.n};
        ASSERT_EQ(s.solve_without_cache(), tc.expected);
    }
}
