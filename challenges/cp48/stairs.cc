/*
Climbing Stairs - https://leetcode.com/problems/climbing-stairs/

You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

The problem respects the fibonacci sequence formula: f(n) = f(n-1) + f(n-2)

Time-Complexity:
    O(n), we upgrade the cache linearly until reaching n

Space-Complexity:
    [with cache] O(n), we store f(n) for each value up until n
    [without cache] O(1), we dont store intermediary results
*/

#include "challenges/cp48/stairs.h"

int Stairs::solve_with_cache()
{
    if (n < 2)
        return 1;

    for (int i = 2; i < n; ++i)
        cache.insert({i, cache[i - 1] + cache[i - 2]});

    return cache[n - 1] + cache[n - 2];
}

int Stairs::solve_without_cache()
{
    if (n < 2)
        return 1;

    int n1 = 1;
    int n2 = 1;
    int tmp = 0;
    for (int i = 2; i < n; ++i)
    {
        tmp = n2;
        n2 = n1 + n2;
        n1 = tmp;
    }
    return n1 + n2;
}
