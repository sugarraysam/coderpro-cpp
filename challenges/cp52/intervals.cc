/*
Merge Intervals - https://leetcode.com/problems/merge-intervals/

Given an array of intervals where intervals[i] = [starti, endi], merge all
overlapping intervals, and return an array of the non-overlapping intervals
that cover all the intervals in the input.

Time-Complexity:
    O(n log n), because we are sorting the intervals, after we iterate through
              the sorted vector in O(n)

Space-Complexity:
    O(n), we store the intervals
*/

#include "intervals.h"
#include <algorithm>
#include <ostream>

// Interval methods
bool operator<(const Interval &lhs, const Interval &rhs) {
  return lhs.start < rhs.start;
}

bool operator==(const Interval &lhs, const Interval &rhs) {
  return lhs.start == rhs.start && lhs.end == rhs.end;
}

bool Interval::is_overlap(const Interval &other) {
  return (start >= other.start && start <= other.end) ||
         (end <= other.end && end >= other.start);
}

bool Interval::is_subset(const Interval &other) {
  return start >= other.start && end <= other.end;
}

// for GoogleTest output
std::ostream &operator<<(std::ostream &out, const Interval &data) {
  out << "Interval(" << data.start << ", " << data.end << ")";
  return out;
};

// Solution methods
std::vector<Interval> Solution::solve() {
  std::sort(_intervals.begin(), _intervals.end());

  int curr = 0;
  int next = curr + 1;
  while (next < _intervals.size()) {
    if (_intervals[next].is_subset(_intervals[curr]))
      this->erase(next);
    else if (_intervals[next].is_overlap(_intervals[curr]))
      this->merge(curr, next);
    else {
      ++next;
      ++curr;
    }
  }
  return _intervals;
}

void Solution::erase(int idx) { _intervals.erase(_intervals.begin() + idx); }

void Solution::merge(int curr, int next) {
  _intervals[curr].end = _intervals[next].end;
  this->erase(next);
}
