#pragma once
#include <unordered_set>
#include <memory>
#include <string>

class Solution
{
private:
    std::string s_{""};

public:
    Solution() : s_{""} {}
    Solution(std::string s) : s_{s} {}

    std::size_t size();
    std::string get_string();

    // Rule of 5, Dest, Copy, Move, CopyA, MoveA
    ~Solution() = default;
    Solution(const Solution &other) = default;
    Solution(Solution &&other) = default;
    Solution &operator=(const Solution &other) = default;
    Solution &operator=(Solution &&other) = default;
};

class Substring
{
private:
    std::string s_{""};

    bool is_duplicate(char c, std::unordered_set<char> &seen);

public:
    Substring(std::string s) : s_{s} {}

    Solution solve();

    // Rule of 5, Dest, Copy, Move, CopyA, MoveA
    ~Substring() = default;
    Substring(const Substring &other) = default;
    Substring(Substring &&other) = default;
    Substring &operator=(const Substring &other) = default;
    Substring &operator=(Substring &&other) = default;
};
