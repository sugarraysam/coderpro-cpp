#pragma once
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Words {
private:
  std::vector<std::string> words_;
  std::unordered_set<int> visited_;
  std::unordered_map<char, int> word_map_;

  void populate_word_map();
  bool is_visited(int word);
  char next_letter(int word);
  bool visited_all_words();

public:
  Words(std::vector<std::string> words) : words_(std::move(words)) {}

  bool can_be_chained();
};
