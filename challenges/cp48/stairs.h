#pragma once
#include <unordered_map>

class Stairs
{
private:
    const unsigned int n;
    std::unordered_map<int, int> cache = {{0, 1}, {1, 1}};

public:
    Stairs(const unsigned int n) : n(n){};
    int solve_with_cache();
    int solve_without_cache();
};
