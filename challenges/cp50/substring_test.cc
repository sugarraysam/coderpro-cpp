#include "substring.h"
#include "gtest/gtest.h"

struct Case {
  std::string s;
  std::string expected;
};

std::vector<Case> TestCases = {
    Case{.s = "abcabcbb", .expected = "abc"},
    Case{.s = "bbbbb", .expected = "b"},
    Case{.s = "pwwkew", .expected = "wke"},
    Case{.s = "", .expected = ""},
    Case{.s = "0123456789", .expected = "0123456789"},
    Case{.s = "z", .expected = "z"},
};

TEST(CP50, TestSubstring) {
  for (auto &tc : TestCases)
    ASSERT_EQ(Substring(tc.s).solve().get_string(), tc.expected);
}
