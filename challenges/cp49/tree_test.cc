#include "challenges/cp49/tree.h"
#include "gtest/gtest.h"

/*
       1
    2     3
  4  5  6  7
*/
Tree first_tree()
{
    auto root = std::make_unique<Node>(1);
    root->append_both(2, 3);
    root->left->append_both(4, 5);
    root->right->append_both(6, 7);
    return Tree{std::move(root)};
}

/* 0 */
Tree second_tree()
{
    auto root = std::make_unique<Node>(0);
    return Tree{std::move(root)};
}

/*
       1
    2     3
  4     6  7
            8
*/
Tree third_tree()
{
    auto root = std::make_unique<Node>(1);
    root->append_both(2, 3);
    root->left->append_left(4);
    root->right->append_both(6, 7);
    root->right->right->append_right(8);
    return Tree{std::move(root)};
}

struct Case
{
    std::function<Tree()> lambda;
    std::string expected;
};

std::vector<Case> TestCases = {
    Case{lambda : first_tree, expected : "124##5##36##7##"},
    Case{lambda : second_tree, expected : "0##"},
    Case{lambda : third_tree, expected : "124###36##7#8##"},
    Case{lambda : []() { return Tree(); }, expected : "#"},
};

TEST(CP49, TreeSerializeAndDeserialize)
{
    for (auto &tc : TestCases)
    {
        Tree t1 = tc.lambda();
        ASSERT_EQ(t1.serialize(), tc.expected);

        Tree t2 = Tree{tc.expected};
        ASSERT_EQ(t2.serialize(), tc.expected);
    }
}
