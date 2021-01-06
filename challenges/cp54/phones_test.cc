#include "phones.h"
#include "gtest/gtest.h"

struct Case {
  std::string digits;
  std::vector<std::string> words;
  std::unordered_set<std::string> expected;
};

std::vector<Case> TestCases = {
    Case{.digits = "364",
         .words = {"dog", "cat", "fish", "fog"},
         .expected = {"dog", "fog"}},
    Case{.digits = "2", .words = {"a", "b"}, .expected = {"a", "b"}},
    Case{.digits = "567",
         .words = {"jor", "cat", "fish", "loq", "kor", "zzz"},
         .expected = {"jor", "loq", "kor"}},

};

TEST(CP53, Testphones) {
  for (auto &tc : TestCases)
    ASSERT_EQ(Phones(tc.digits, std::move(tc.words)).solve(), tc.expected);
}
