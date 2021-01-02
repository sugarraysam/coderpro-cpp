/*
Longest Substring Without Repeating Characters
https://leetcode.com/problems/longest-substring-without-repeating-characters/

Given a string s, find the length of the longest substring without repeating
characters.

We return the first occurence of the longest string.

Time-Complexity:
    O(n), using pointers, we do a single pass through the string

Space-Complexity:
    O(n), in worst-case, all chars in string are unique and we store them all in
the unordered_set
*/

#include "substring.h"

// Solution methods
std::size_t Solution::size() { return s_.size(); }

std::string Solution::get_string() { return s_; }

// Substring methods
Solution Substring::solve() {
  Solution sol;
  std::size_t start = 0;
  std::size_t end = 0;
  std::unordered_set<char> seen;

  while (end < s_.size()) {
    if (this->is_duplicate(s_[end], seen)) {
      if ((end - start) > sol.size())
        sol = Solution(s_.substr(start, end - start));
      start = end;
    }
    seen.insert(s_[end++]);
  }

  return (seen.size() == s_.size()) ? Solution(s_) : sol;
}

bool Substring::is_duplicate(char c, std::unordered_set<char> &seen) {
  if (seen.find(c) != seen.end()) {
    seen.clear();
    return true;
  }
  return false;
}
