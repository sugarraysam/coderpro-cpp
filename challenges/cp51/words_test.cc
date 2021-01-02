#include "words.h"
#include "gtest/gtest.h"

struct Case {
  std::vector<std::string> words;
  bool expected;
};

std::vector<Case> TestCases = {
    Case{.words = {"apple", "eggs", "snack", "kacat", "tuna"},
         .expected = true},
    Case{.words = {"apple", "ea", "apple", "ea"}, .expected = true},
    Case{.words = {""}, .expected = true},
    Case{.words = {"geek", "king"}, .expected = true},
    Case{.words = {"for", "geek", "rig", "kaf"}, .expected = true},
    Case{.words = {"aaa"}, .expected = true},
    Case{.words = {"aaa", "bbb"}, .expected = false},
    Case{.words = {"ijk", "kji", "abc", "cba"}, .expected = false},
};

TEST(cp51, TestSubstring) {
  for (const auto &tc : TestCases)
    ASSERT_EQ(Words(tc.words).can_be_chained(), tc.expected);
}
