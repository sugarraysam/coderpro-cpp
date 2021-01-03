#pragma once
#include <iostream>
#include <vector>

class Interval {
public:
  int start{0}, end{0};
  Interval(int start, int end) : start(start), end(end) {}

  bool is_subset(const Interval &other);
  bool is_overlap(const Interval &other);

  friend bool operator<(const Interval &lhs, const Interval &rhs);
  friend bool operator==(const Interval &lhs, const Interval &rhs);
  friend std::ostream &operator<<(std::ostream &out, const Interval &data);
};

class Solution {
private:
  std::vector<Interval> _intervals;

  void erase(int idx);
  void merge(int curr, int next);

public:
  Solution(std::vector<Interval> intervals)
      : _intervals(std::move(intervals)) {}

  std::vector<Interval> solve();
};
