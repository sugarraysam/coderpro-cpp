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

// if words_ is len == 0, we return true
bool Words::can_be_chained() {
  int steps = words_.size();
  if (!steps)
    return true;

  this->populate_word_map();
  char letter = words_[0].front();
  while (steps) {
    int word = word_map_[letter];

    if (this->is_visited(word))
      return false;

    visited_.insert(word);
    letter = this->next_letter(word);
    --steps;
  }

  return this->visited_all_words();
}

void Words::populate_word_map() {
  for (size_t i = 0; i < words_.size(); ++i) {
    word_map_[words_[i].front()] = i;
  }
}

bool Words::is_visited(int word) {
  return visited_.find(word) != visited_.end();
}

char Words::next_letter(int word) { return words_[word].back(); }

bool Words::visited_all_words() { return visited_.size() == words_.size(); }
