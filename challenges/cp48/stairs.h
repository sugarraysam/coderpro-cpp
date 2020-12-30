#pragma once
#include <unordered_map>

class Stairs
{
private:
    std::unordered_map<int, int> cache = {{0, 1}, {1, 1}};

public:
    Stairs(){};
    int solve_with_cache(const int n);
    int solve_without_cache(const int n);
};
