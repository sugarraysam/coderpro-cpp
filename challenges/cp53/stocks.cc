/*

Best Time to Buy and Sell Stock
https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

Say you have an array for which the ith element is the price of a given stock on
day i.

If you were only permitted to complete at most one transaction (i.e., buy one
and sell one share of the stock), design an algorithm to find the maximum
profit.

Note that you cannot sell a stock before you buy one.

Time-Complexity:
    O(n), we traverse prices a single time in reverse order

Space-Complexity:
    O(1), constant, only storing max_sell_price and _max_profit
*/

#include "stocks.h"

int Stocks::solve() {
  int max_sell_price = _prices.back();

  for (auto rit = ++_prices.rbegin(); rit != _prices.rend(); ++rit) {
    _max_profit = std::max(_max_profit, max_sell_price - *rit);
    max_sell_price = std::max(max_sell_price, *rit);
  }
  return _max_profit;
}
