/*
Circle of Chained Words
https://www.geeksforgeeks.org/given-array-strings-find-strings-can-chained-form-circle/

Given an array of strings, find if the given strings can be chained to form a
circle. A string X can be put before another string Y in circle if the last
character of X is same as first character of Y.

Time-Complexity:
    O(n), (2n) to be exact, loop through words once to build the word_map, and
        then a second time to try traversing graph see if we visit all nodes

Space-Complexity:
    O(n), we store a letter->wordID hashmap
*/

#include "challenges/cp51/words.h"

bool Words::can_be_chained() {
  for (size_t i = 0; i < words_.size(); ++i) {
    char c = words_[i].front();
    graph_[c].push_back(i);
  }

  return is_cycle_dfs(0, 0, words_.size() - 1);
}

bool Words::is_cycle_dfs(int curr, int start, int len) {
  if (len == 0) {
    return this->last_letter(curr) == this->first_letter(start);
  }
  visited_.insert(curr);
  for (auto neighbor : this->get_neighbors(curr)) {
    if (!this->is_visited(neighbor))
      return this->is_cycle_dfs(neighbor, start, len - 1);
  }
  visited_.erase(curr);
  return false;
}

char Words::first_letter(int i) { return words_[i].front(); }

char Words::last_letter(int i) { return words_[i].back(); }

std::vector<int> Words::get_neighbors(int i) {
  return graph_[this->last_letter(i)];
}

bool Words::is_visited(int i) { return visited_.find(i) != visited_.end(); }
