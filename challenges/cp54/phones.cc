/*

Letter Combinations of a Phone Number
https://leetcode.com/problems/letter-combinations-of-a-phone-number/

Given a string containing digits from 2-9 inclusive, return all possible letter
combinations that the number could represent. Return the answer in any order.

A mapping of digit to letters (just like on the telephone buttons) is given
below. Note that 1 does not map to any letters.

Time-Complexity:
    O(n^3), where n == len(digits), and 3 is because we have 3 chars per digit
            on average

Space-Complexity:
    O(4n + 2m), we are storing a set of words (len(words) == m) twice (second
                set is the response accumulator) plus a digits_map (3n) and the
                digits (n)
*/

#include "phones.h"
#include <iostream>

// Global phone digit -> char map
std::unordered_map<char, std::vector<char>> DIGITS_MAP = {
    {'1', {}}, // NOT given in tests
    {'2', {'a', 'b', 'c'}},
    {'3', {'d', 'e', 'f'}},
    {'4', {'g', 'h', 'i'}},
    {'5', {'j', 'k', 'l'}},
    {'6', {'m', 'n', 'o'}},
    {'7', {'p', 'q', 'r', 's'}},
    {'8', {'t', 'u', 'v'}},
    {'9', {'x', 'y', 'z'}},
};

// Phones methods - digits between 2-9 (inclusive), ALL chars and strings
// lowercase (not checking this for simplicity)
std::unordered_set<std::string> Phones::solve() {
  std::unordered_set<std::string> res;
  solve_helper(0, _digits.size(), "", res);
  return res;
}

void Phones::solve_helper(int pos, int end, std::string word,
                          std::unordered_set<std::string> &acc) {
  if (pos == end) {
    if (_words.find(word) != _words.end())
      acc.insert(word);
    return;
  }

  for (char c : DIGITS_MAP[_digits[pos]])
    solve_helper(pos + 1, end, word + c, acc);
}
