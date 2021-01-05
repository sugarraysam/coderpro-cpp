#include "stocks.h"
#include "gtest/gtest.h"

struct Case {
  std::vector<int> prices;
  int expected;
};

std::vector<Case> TestCases = {
    Case{.prices = {7, 1, 5, 3, 6, 4}, .expected = 5},
    Case{.prices = {7, 6, 4, 3, 1}, .expected = 0},
    Case{.prices = {9, 11, 8, 5, 7, 10}, .expected = 5},
};

TEST(CP53, TestStocks) {
  for (auto &tc : TestCases)
    ASSERT_EQ(Stocks(std::move(tc.prices)).solve(), tc.expected);
}
