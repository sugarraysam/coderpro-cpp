/*
Serialize and Deserialize a Binary Tree
https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

Serialization is the process of converting a data structure or object into a
sequence of bits so that it can be stored in a file or memory buffer, or
transmitted across a network connection link to be reconstructed later in the
same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no
restriction on how your serialization/deserialization algorithm should work. You
just need to ensure that a binary tree can be serialized to a string and this
string can be deserialized to the original tree structure.

Clarification: The input/output format is the same as how LeetCode serializes a
binary tree. You do not necessarily need to follow this format, so please be
creative and come up with different approaches yourself.

Time-Complexity:
    O(n), we traverse all nodes in the tree, linear (both serializing &
deserializing)

Space-Complexity:
    O(n), we store each node as a ptr (with val etc.), also...
        serialize -> this is a tail recursive function so the compiler should
optimize this and not pile up function calls on the stack deserialize -> not
tail-recursive, which means we could argue there will be O(n) space used on the
stack for function calls
*/

#include "tree.h"

// Tree methods
std::string Tree::serialize() {
  std::string acc;
  this->serialize_helper(this->root_.get(), acc);
  return acc;
}

// `node` data & ptr are Read-Only
void Tree::serialize_helper(const Node *const node, std::string &acc) {
  if (node == nullptr) {
    acc += this->marker_;
    return;
  }
  acc += std::to_string(node->val);

  serialize_helper(node->left.get(), acc);
  serialize_helper(node->right.get(), acc);
}

Tree::Tree(const std::string &s) {
  size_t i = 0;
  this->root_ = this->deserialize(s, i);
}

std::unique_ptr<Node> Tree::deserialize(const std::string &s, std::size_t &i) {
  if (i >= s.length() || s[i] == this->marker_)
    return nullptr;

  auto node = std::make_unique<Node>(s[i]);
  node->left = this->deserialize(s, ++i);
  node->right = this->deserialize(s, ++i);
  return node;
}

// Node methods
void Node::append_left(int val) { this->left = std::make_unique<Node>(val); }

void Node::append_right(int val) { this->right = std::make_unique<Node>(val); }

void Node::append_both(int lval, int rval) {
  this->append_left(lval);
  this->append_right(rval);
}
