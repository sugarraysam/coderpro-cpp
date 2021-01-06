#pragma once
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Phones {
private:
  std::string _digits;
  std::unordered_set<std::string> _words;

  void solve_helper(int pos, int end, std::string word,
                    std::unordered_set<std::string> &acc);

public:
  Phones(std::string &digits, std::vector<std::string> &&words)
      : _digits(digits), _words(words.begin(), words.end()) {}

  std::unordered_set<std::string> solve();
};
