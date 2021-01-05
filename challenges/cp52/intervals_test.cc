#include "intervals.h"
#include "gtest/gtest.h"

struct Case {
  std::vector<Interval> intervals;
  std::vector<Interval> expected;
};

std::vector<Case> TestCases = {
    Case{.intervals = {Interval(1, 3), Interval(2, 6), Interval(8, 10),
                       Interval(15, 18)},
         .expected = {Interval(1, 6), Interval(8, 10), Interval(15, 18)}},
    Case{.intervals = {Interval(5, 8), Interval(1, 3), Interval(4, 10),
                       Interval(20, 25)},
         .expected = {Interval(1, 3), Interval(4, 10), Interval(20, 25)}},
    Case{.intervals = {Interval(1, 4), Interval(4, 5)},
         .expected = {Interval(1, 5)}},
    Case{.intervals = {Interval(1, 4)}, .expected = {Interval(1, 4)}},
};

TEST(CP52, TestIntervals) {
  for (const auto &tc : TestCases)
    ASSERT_EQ(Solution(std::move(tc.intervals)).solve(), tc.expected);
}
