#pragma once
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Words {
private:
  std::vector<std::string> words_;
  std::unordered_set<int> visited_;
  std::unordered_map<char, std::vector<int>> graph_;

  bool is_cycle_dfs(int curr, int start, int len);
  char first_letter(int i);
  char last_letter(int i);
  std::vector<int> get_neighbors(int i);
  bool is_visited(int i);

public:
  Words(std::vector<std::string> words) : words_(std::move(words)) {}

  bool can_be_chained();
};
