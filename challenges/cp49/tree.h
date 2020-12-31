#pragma once
#include <string>
#include <memory>

using namespace std;

class Node
{
public:
    // convert char '2' -> int 2 OR char '3' -> int 3, etc.
    Node(const char c) : val(c - '0') {}
    Node(const int v) : val(v) {}

    void append_left(const int val);
    void append_right(const int val);
    void append_both(const int lval, const int rval);

    const int val;
    unique_ptr<Node> left{nullptr};
    unique_ptr<Node> right{nullptr};
};

class Tree
{
private:
    void serialize_helper(const unique_ptr<Node> &node, string &acc);
    unique_ptr<Node> deserialize(const string &s, size_t &i);

public:
    Tree() {}
    Tree(unique_ptr<Node> root) : root{move(root)} {}
    Tree(const string &s);

    string serialize();

    unique_ptr<Node> root{nullptr};
    char marker{'#'};
};
