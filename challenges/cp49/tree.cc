/*
Serialize and Deserialize a Binary Tree
https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

Serialization is the process of converting a data structure or object into a sequence
of bits so that it can be stored in a file or memory buffer, or transmitted across a
network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on
how your serialization/deserialization algorithm should work. You just need to ensure that
a binary tree can be serialized to a string and this string can be deserialized to the original
tree structure.

Clarification: The input/output format is the same as how LeetCode serializes a binary tree.
You do not necessarily need to follow this format, so please be creative and come up with
different approaches yourself.

Time-Complexity:
    O(n), we traverse all nodes in the tree, linear (both serializing & deserializing)

Space-Complexity:
    O(n), we store each node as a ptr (with val etc.), because its both serialize and deserialize
        are recursive, we could argue the call stack also takes O(n) space
*/

#include "challenges/cp49/tree.h"

using namespace std;

string Tree::serialize()
{
    string acc;
    this->serialize_helper(this->root, acc);
    return acc;
}

void Tree::serialize_helper(const unique_ptr<Node> &node, string &acc)
{
    if (node == nullptr)
    {
        acc += this->marker;
        return;
    }
    acc += to_string(node->val);

    serialize_helper(node->left, acc);
    serialize_helper(node->right, acc);
}

Tree::Tree(const string &s)
{
    int i = 0;
    this->root = move(this->deserialize(s, i));
}

unique_ptr<Node> Tree::deserialize(const std::string &s, int &i)
{
    if (i >= s.length() || s[i] == this->marker)
        return nullptr;

    // convert char '2' -> int 2 OR char '3' -> int 3, etc.
    auto node = make_unique<Node>(s[i] - '0');

    auto lnode = this->deserialize(s, ++i);
    if (lnode != nullptr)
        node->left = move(lnode);

    auto rnode = this->deserialize(s, ++i);
    if (rnode != nullptr)
        node->right = move(rnode);

    return node;
}

// Node methods
void Node::append_left(const int val)
{
    this->left = std::make_unique<Node>(val);
}

void Node::append_right(const int val)
{
    this->right = std::make_unique<Node>(val);
}

void Node::append_both(const int lval, const int rval)
{
    this->append_left(lval);
    this->append_right(rval);
}
