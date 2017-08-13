/*
 * Copyright (C) 2017, Yeolar
 */

#include <gtest/gtest.h>
#include "BinaryTree.h"

namespace ae {

template <class T>
size_t treeDepth(BinaryTreeNode<T>* root) {
  if (root == nullptr) return 0;
  size_t leftN = treeDepth(root->left);
  size_t rightN = treeDepth(root->right);
  return leftN > rightN ? leftN + 1 : rightN + 1;
}

} // namespace ae

TEST(treeDepth, all) {
  {
    auto node7 = ae::createTreeNode<int>(7, nullptr, nullptr);
    auto node6 = ae::createTreeNode<int>(6, nullptr, nullptr);
    auto node5 = ae::createTreeNode<int>(5, node7, nullptr);
    auto node4 = ae::createTreeNode<int>(4, nullptr, nullptr);
    auto node3 = ae::createTreeNode<int>(3, nullptr, node6);
    auto node2 = ae::createTreeNode<int>(2, node4, node5);
    auto node1 = ae::createTreeNode<int>(1, node2, node3);
    EXPECT_EQ(ae::treeDepth(node1), 4);
    ae::destroyTree(node1);
  }
  {
    auto node5 = ae::createTreeNode<int>(5, nullptr, nullptr);
    auto node4 = ae::createTreeNode<int>(4, node5, nullptr);
    auto node3 = ae::createTreeNode<int>(3, node4, nullptr);
    auto node2 = ae::createTreeNode<int>(2, node3, nullptr);
    auto node1 = ae::createTreeNode<int>(1, node2, nullptr);
    EXPECT_EQ(ae::treeDepth(node1), 5);
    ae::destroyTree(node1);
  }
  {
    auto node5 = ae::createTreeNode<int>(5, nullptr, nullptr);
    auto node4 = ae::createTreeNode<int>(4, nullptr, node5);
    auto node3 = ae::createTreeNode<int>(3, nullptr, node4);
    auto node2 = ae::createTreeNode<int>(2, nullptr, node3);
    auto node1 = ae::createTreeNode<int>(1, nullptr, node2);
    EXPECT_EQ(ae::treeDepth(node1), 5);
    ae::destroyTree(node1);
  }
  {
    auto node1 = ae::createTreeNode<int>(1, nullptr, nullptr);
    EXPECT_EQ(ae::treeDepth(node1), 1);
    ae::destroyTree(node1);
  }
  {
    EXPECT_EQ(ae::treeDepth<int>(nullptr), 0);
  }
}
