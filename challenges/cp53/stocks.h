#pragma once
#include <algorithm>
#include <vector>

class Stocks {
private:
  int _max_profit{0};
  std::vector<int> _prices;

public:
  Stocks(std::vector<int> &&prices) : _prices(prices) {}

  int solve();
};
