/*
 * Copyright (C) 2017, Yeolar
 */

#include <gtest/gtest.h>
#include "BinaryTree.h"

namespace ae {

template <class T>
bool doesTree1HaveTree2(BinaryTreeNode<T>* root1, BinaryTreeNode<T>* root2) {
  if (root2 == nullptr) return true;
  if (root1 == nullptr) return false;
  if (root1->value != root2->value) return false;
  return doesTree1HaveTree2(root1->left, root2->left)
    && doesTree1HaveTree2(root1->right, root2->right);
}

template <class T>
bool hasSubtree(BinaryTreeNode<T>* root1, BinaryTreeNode<T>* root2) {
  if (root1 && root2) {
    bool result = false;
    if (root1->value == root2->value) {
      result = doesTree1HaveTree2(root1, root2);
    }
    return result
      || hasSubtree(root1->left, root2)
      || hasSubtree(root1->right, root2);
  }
  return false;
}

} // namespace ae

TEST(hasSubtree, all) {
  {
    auto nodeA7 = ae::createTreeNode<int>(7, nullptr, nullptr);
    auto nodeA6 = ae::createTreeNode<int>(4, nullptr, nullptr);
    auto nodeA5 = ae::createTreeNode<int>(2, nodeA6, nodeA7);
    auto nodeA4 = ae::createTreeNode<int>(9, nullptr, nullptr);
    auto nodeA3 = ae::createTreeNode<int>(7, nullptr, nullptr);
    auto nodeA2 = ae::createTreeNode<int>(8, nodeA4, nodeA5);
    auto nodeA1 = ae::createTreeNode<int>(8, nodeA2, nodeA3);
    auto nodeB3 = ae::createTreeNode<int>(2, nullptr, nullptr);
    auto nodeB2 = ae::createTreeNode<int>(9, nullptr, nullptr);
    auto nodeB1 = ae::createTreeNode<int>(8, nodeB2, nodeB3);
    EXPECT_TRUE(ae::hasSubtree(nodeA1, nodeB1));
    ae::destroyTree(nodeA1);
    ae::destroyTree(nodeB1);
  }
  {
    auto nodeA7 = ae::createTreeNode<int>(7, nullptr, nullptr);
    auto nodeA6 = ae::createTreeNode<int>(4, nullptr, nullptr);
    auto nodeA5 = ae::createTreeNode<int>(3, nodeA6, nodeA7);
    auto nodeA4 = ae::createTreeNode<int>(9, nullptr, nullptr);
    auto nodeA3 = ae::createTreeNode<int>(7, nullptr, nullptr);
    auto nodeA2 = ae::createTreeNode<int>(8, nodeA4, nodeA5);
    auto nodeA1 = ae::createTreeNode<int>(8, nodeA2, nodeA3);
    auto nodeB3 = ae::createTreeNode<int>(2, nullptr, nullptr);
    auto nodeB2 = ae::createTreeNode<int>(9, nullptr, nullptr);
    auto nodeB1 = ae::createTreeNode<int>(8, nodeB2, nodeB3);
    EXPECT_FALSE(ae::hasSubtree(nodeA1, nodeB1));
    ae::destroyTree(nodeA1);
    ae::destroyTree(nodeB1);
  }
  {
    auto nodeA5 = ae::createTreeNode<int>(5, nullptr, nullptr);
    auto nodeA4 = ae::createTreeNode<int>(2, nodeA5, nullptr);
    auto nodeA3 = ae::createTreeNode<int>(9, nodeA4, nullptr);
    auto nodeA2 = ae::createTreeNode<int>(8, nodeA3, nullptr);
    auto nodeA1 = ae::createTreeNode<int>(8, nodeA2, nullptr);
    auto nodeB3 = ae::createTreeNode<int>(2, nullptr, nullptr);
    auto nodeB2 = ae::createTreeNode<int>(9, nodeB3, nullptr);
    auto nodeB1 = ae::createTreeNode<int>(8, nodeB2, nullptr);
    EXPECT_TRUE(ae::hasSubtree(nodeA1, nodeB1));
    ae::destroyTree(nodeA1);
    ae::destroyTree(nodeB1);
  }
  {
    auto nodeA5 = ae::createTreeNode<int>(5, nullptr, nullptr);
    auto nodeA4 = ae::createTreeNode<int>(2, nodeA5, nullptr);
    auto nodeA3 = ae::createTreeNode<int>(9, nodeA4, nullptr);
    auto nodeA2 = ae::createTreeNode<int>(8, nodeA3, nullptr);
    auto nodeA1 = ae::createTreeNode<int>(8, nodeA2, nullptr);
    auto nodeB3 = ae::createTreeNode<int>(3, nullptr, nullptr);
    auto nodeB2 = ae::createTreeNode<int>(9, nodeB3, nullptr);
    auto nodeB1 = ae::createTreeNode<int>(8, nodeB2, nullptr);
    EXPECT_FALSE(ae::hasSubtree(nodeA1, nodeB1));
    ae::destroyTree(nodeA1);
    ae::destroyTree(nodeB1);
  }
  {
    auto nodeA5 = ae::createTreeNode<int>(5, nullptr, nullptr);
    auto nodeA4 = ae::createTreeNode<int>(2, nullptr, nodeA5);
    auto nodeA3 = ae::createTreeNode<int>(9, nullptr, nodeA4);
    auto nodeA2 = ae::createTreeNode<int>(8, nullptr, nodeA3);
    auto nodeA1 = ae::createTreeNode<int>(8, nullptr, nodeA2);
    auto nodeB3 = ae::createTreeNode<int>(2, nullptr, nullptr);
    auto nodeB2 = ae::createTreeNode<int>(9, nullptr, nodeB3);
    auto nodeB1 = ae::createTreeNode<int>(8, nullptr, nodeB2);
    EXPECT_TRUE(ae::hasSubtree(nodeA1, nodeB1));
    ae::destroyTree(nodeA1);
    ae::destroyTree(nodeB1);
  }
  {
    auto nodeA5 = ae::createTreeNode<int>(5, nullptr, nullptr);
    auto nodeA4 = ae::createTreeNode<int>(2, nullptr, nodeA5);
    auto nodeA3 = ae::createTreeNode<int>(9, nullptr, nodeA4);
    auto nodeA2 = ae::createTreeNode<int>(8, nullptr, nodeA3);
    auto nodeA1 = ae::createTreeNode<int>(8, nullptr, nodeA2);
    auto nodeB4 = ae::createTreeNode<int>(2, nullptr, nullptr);
    auto nodeB3 = ae::createTreeNode<int>(3, nullptr, nullptr);
    auto nodeB2 = ae::createTreeNode<int>(9, nodeB3, nodeB4);
    auto nodeB1 = ae::createTreeNode<int>(8, nullptr, nodeB2);
    EXPECT_FALSE(ae::hasSubtree(nodeA1, nodeB1));
    ae::destroyTree(nodeA1);
    ae::destroyTree(nodeB1);
  }
  {
    auto nodeB4 = ae::createTreeNode<int>(2, nullptr, nullptr);
    auto nodeB3 = ae::createTreeNode<int>(3, nullptr, nullptr);
    auto nodeB2 = ae::createTreeNode<int>(9, nodeB3, nodeB4);
    auto nodeB1 = ae::createTreeNode<int>(8, nullptr, nodeB2);
    EXPECT_FALSE(ae::hasSubtree<int>(nullptr, nodeB1));
    ae::destroyTree(nodeB1);
  }
  {
    auto nodeA4 = ae::createTreeNode<int>(2, nullptr, nullptr);
    auto nodeA3 = ae::createTreeNode<int>(3, nullptr, nullptr);
    auto nodeA2 = ae::createTreeNode<int>(9, nodeA3, nodeA4);
    auto nodeA1 = ae::createTreeNode<int>(8, nullptr, nodeA2);
    EXPECT_FALSE(ae::hasSubtree<int>(nodeA1, nullptr));
    ae::destroyTree(nodeA1);
  }
  {
    EXPECT_FALSE(ae::hasSubtree<int>(nullptr, nullptr));
  }
}
