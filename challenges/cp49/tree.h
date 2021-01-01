#pragma once
#include <string>
#include <memory>

class Node
{
public:
    int val;
    std::unique_ptr<Node> left{nullptr};
    std::unique_ptr<Node> right{nullptr};

    // convert char '2' -> int 2 OR char '3' -> int 3, etc.
    Node(const char c) : val(c - '0') {}
    Node(int v) : val(v) {}

    // Rule of 5 - Dest, Copy, Move, CopyA, MoveA
    ~Node() = default;
    Node(const Node &other) = delete;
    Node(Node &&other)
        : val(other.val), left(std::move(other.left)), right(std::move(other.right))
    {
    }
    Node &operator=(const Node &other) = delete;
    Node &operator=(Node &&other)
    {
        this->val = other.val;
        std::swap(this->left, other.left);
        std::swap(this->right, other.right);
        return *this;
    }

    void append_left(int val);
    void append_right(int val);
    void append_both(int lval, int rval);
};

class Tree
{
private:
    std::unique_ptr<Node> root_{nullptr};
    char marker_{'#'};

    void serialize_helper(const Node *const node, std::string &acc);
    std::unique_ptr<Node> deserialize(const std::string &s, std::size_t &i);

public:
    Tree() {}
    Tree(std::unique_ptr<Node> &&root) : root_(std::move(root)) {}
    Tree(const std::string &s);

    // Rule of 5 - Dest, Copy, Move, CopyA, MoveA
    ~Tree() = default;
    Tree(const Tree &other) = delete;
    Tree(Tree &&other) : root_(std::move(other.root_)) {}
    Tree &operator=(const Tree &other) = delete;
    Tree &operator=(Tree &&other) noexcept
    {
        std::swap(this->root_, other.root_);
        return *this;
    }

    std::string serialize();
};
