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

template <class T>
bool isBalanced_v1(BinaryTreeNode<T>* root) {
  if (root == nullptr) return true;
  size_t leftN = treeDepth(root->left);
  size_t rightN = treeDepth(root->right);
  if (leftN > rightN + 1 || rightN > leftN + 1) return false;
  return isBalanced_v1(root->left) && isBalanced_v1(root->right);
}

template <class T>
bool isBalanced(BinaryTreeNode<T>* root, size_t& depth) {
  if (root == nullptr) {
    depth = 0;
    return true;
  }
  size_t leftN, rightN;
  if (isBalanced(root->left, leftN) && isBalanced(root->right, rightN)) {
    if (leftN <= rightN + 1 && rightN <= leftN + 1) {
      depth = 1 + (leftN > rightN ? leftN : rightN);
      return true;
    }
  }
  return false;
}

template <class T>
bool isBalanced_v2(BinaryTreeNode<T>* root) {
  size_t depth;
  return isBalanced(root, depth);
}

} // namespace ae

TEST(treeDepth, all) {
  {
    auto node7 = ae::createTreeNode<int>(7, nullptr, nullptr);
    auto node6 = ae::createTreeNode<int>(6, nullptr, nullptr);
    auto node5 = ae::createTreeNode<int>(5, nullptr, nullptr);
    auto node4 = ae::createTreeNode<int>(4, nullptr, nullptr);
    auto node3 = ae::createTreeNode<int>(3, node6, node7);
    auto node2 = ae::createTreeNode<int>(2, node4, node5);
    auto node1 = ae::createTreeNode<int>(1, node2, node3);
    EXPECT_TRUE(ae::isBalanced_v1(node1));
    EXPECT_TRUE(ae::isBalanced_v2(node1));
    ae::destroyTree(node1);
  }
  {
    auto node7 = ae::createTreeNode<int>(7, nullptr, nullptr);
    auto node6 = ae::createTreeNode<int>(6, nullptr, nullptr);
    auto node5 = ae::createTreeNode<int>(5, node7, nullptr);
    auto node4 = ae::createTreeNode<int>(4, nullptr, nullptr);
    auto node3 = ae::createTreeNode<int>(3, nullptr, node6);
    auto node2 = ae::createTreeNode<int>(2, node4, node5);
    auto node1 = ae::createTreeNode<int>(1, node2, node3);
    EXPECT_TRUE(ae::isBalanced_v1(node1));
    EXPECT_TRUE(ae::isBalanced_v2(node1));
    ae::destroyTree(node1);
  }
  {
    auto node6 = ae::createTreeNode<int>(6, nullptr, nullptr);
    auto node5 = ae::createTreeNode<int>(5, node6, nullptr);
    auto node4 = ae::createTreeNode<int>(4, nullptr, nullptr);
    auto node3 = ae::createTreeNode<int>(3, nullptr, nullptr);
    auto node2 = ae::createTreeNode<int>(2, node4, node5);
    auto node1 = ae::createTreeNode<int>(1, node2, node3);
    EXPECT_FALSE(ae::isBalanced_v1(node1));
    EXPECT_FALSE(ae::isBalanced_v2(node1));
    ae::destroyTree(node1);
  }
  {
    auto node5 = ae::createTreeNode<int>(5, nullptr, nullptr);
    auto node4 = ae::createTreeNode<int>(4, node5, nullptr);
    auto node3 = ae::createTreeNode<int>(3, node4, nullptr);
    auto node2 = ae::createTreeNode<int>(2, node3, nullptr);
    auto node1 = ae::createTreeNode<int>(1, node2, nullptr);
    EXPECT_FALSE(ae::isBalanced_v1(node1));
    EXPECT_FALSE(ae::isBalanced_v2(node1));
    ae::destroyTree(node1);
  }
  {
    auto node5 = ae::createTreeNode<int>(5, nullptr, nullptr);
    auto node4 = ae::createTreeNode<int>(4, nullptr, node5);
    auto node3 = ae::createTreeNode<int>(3, nullptr, node4);
    auto node2 = ae::createTreeNode<int>(2, nullptr, node3);
    auto node1 = ae::createTreeNode<int>(1, nullptr, node2);
    EXPECT_FALSE(ae::isBalanced_v1(node1));
    EXPECT_FALSE(ae::isBalanced_v2(node1));
    ae::destroyTree(node1);
  }
  {
    auto node1 = ae::createTreeNode<int>(1, nullptr, nullptr);
    EXPECT_TRUE(ae::isBalanced_v1(node1));
    EXPECT_TRUE(ae::isBalanced_v2(node1));
    ae::destroyTree(node1);
  }
  {
    EXPECT_TRUE(ae::isBalanced_v1<int>(nullptr));
    EXPECT_TRUE(ae::isBalanced_v2<int>(nullptr));
  }
}
