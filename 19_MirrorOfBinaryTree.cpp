/*
 * Copyright (C) 2017, Yeolar
 */

#include <stack>
#include <gtest/gtest.h>
#include "BinaryTree.h"

namespace ae {

template <class T>
void mirrorTree_v1(BinaryTreeNode<T>* node) {
  if (node == nullptr) return;
  std::swap(node->left, node->right);
  if (node->left) {
    mirrorTree_v1(node->left);
  }
  if (node->right) {
    mirrorTree_v1(node->right);
  }
}

template <class T>
void mirrorTree_v2(BinaryTreeNode<T>* root) {
  if (root == nullptr) return;
  std::stack<BinaryTreeNode<T>*> stack;
  stack.push(root);
  while (!stack.empty()) {
    BinaryTreeNode<T>* node = stack.top();
    stack.pop();
    std::swap(node->left, node->right);
    if (node->left) {
      stack.push(node->left);
    }
    if (node->right) {
      stack.push(node->right);
    }
  }
}

} // namespace ae

TEST(mirrorTree, all) {
  std::stringstream out;
  {
    auto node7 = ae::createTreeNode<int>(11, nullptr, nullptr);
    auto node6 = ae::createTreeNode<int>(9, nullptr, nullptr);
    auto node5 = ae::createTreeNode<int>(7, nullptr, nullptr);
    auto node4 = ae::createTreeNode<int>(5, nullptr, nullptr);
    auto node3 = ae::createTreeNode<int>(10, node6, node7);
    auto node2 = ae::createTreeNode<int>(6, node4, node5);
    auto node1 = ae::createTreeNode<int>(8, node2, node3);
    ae::mirrorTree_v1(node1);
    ae::printTree(node1, out);
    ae::destroyTree(node1);
    EXPECT_STREQ(out.str().c_str(), "8 10 11 9 6 7 5 ");
    out.str("");
  }
  {
    auto node7 = ae::createTreeNode<int>(11, nullptr, nullptr);
    auto node6 = ae::createTreeNode<int>(9, nullptr, nullptr);
    auto node5 = ae::createTreeNode<int>(7, nullptr, nullptr);
    auto node4 = ae::createTreeNode<int>(5, nullptr, nullptr);
    auto node3 = ae::createTreeNode<int>(10, node6, node7);
    auto node2 = ae::createTreeNode<int>(6, node4, node5);
    auto node1 = ae::createTreeNode<int>(8, node2, node3);
    ae::mirrorTree_v2(node1);
    ae::printTree(node1, out);
    ae::destroyTree(node1);
    EXPECT_STREQ(out.str().c_str(), "8 10 11 9 6 7 5 ");
    out.str("");
  }
  {
    auto node5 = ae::createTreeNode<int>(4, nullptr, nullptr);
    auto node4 = ae::createTreeNode<int>(5, node5, nullptr);
    auto node3 = ae::createTreeNode<int>(6, node4, nullptr);
    auto node2 = ae::createTreeNode<int>(7, node3, nullptr);
    auto node1 = ae::createTreeNode<int>(8, node2, nullptr);
    ae::mirrorTree_v1(node1);
    ae::printTree(node1, out);
    ae::destroyTree(node1);
    EXPECT_STREQ(out.str().c_str(), "8 7 6 5 4 ");
    out.str("");
  }
  {
    auto node5 = ae::createTreeNode<int>(4, nullptr, nullptr);
    auto node4 = ae::createTreeNode<int>(5, node5, nullptr);
    auto node3 = ae::createTreeNode<int>(6, node4, nullptr);
    auto node2 = ae::createTreeNode<int>(7, node3, nullptr);
    auto node1 = ae::createTreeNode<int>(8, node2, nullptr);
    ae::mirrorTree_v2(node1);
    ae::printTree(node1, out);
    ae::destroyTree(node1);
    EXPECT_STREQ(out.str().c_str(), "8 7 6 5 4 ");
    out.str("");
  }
  {
    auto node5 = ae::createTreeNode<int>(4, nullptr, nullptr);
    auto node4 = ae::createTreeNode<int>(5, nullptr, node5);
    auto node3 = ae::createTreeNode<int>(6, nullptr, node4);
    auto node2 = ae::createTreeNode<int>(7, nullptr, node3);
    auto node1 = ae::createTreeNode<int>(8, nullptr, node2);
    ae::mirrorTree_v1(node1);
    ae::printTree(node1, out);
    ae::destroyTree(node1);
    EXPECT_STREQ(out.str().c_str(), "8 7 6 5 4 ");
    out.str("");
  }
  {
    auto node5 = ae::createTreeNode<int>(4, nullptr, nullptr);
    auto node4 = ae::createTreeNode<int>(5, nullptr, node5);
    auto node3 = ae::createTreeNode<int>(6, nullptr, node4);
    auto node2 = ae::createTreeNode<int>(7, nullptr, node3);
    auto node1 = ae::createTreeNode<int>(8, nullptr, node2);
    ae::mirrorTree_v2(node1);
    ae::printTree(node1, out);
    ae::destroyTree(node1);
    EXPECT_STREQ(out.str().c_str(), "8 7 6 5 4 ");
    out.str("");
  }
  {
    auto node1 = ae::createTreeNode<int>(8, nullptr, nullptr);
    ae::mirrorTree_v1(node1);
    ae::printTree(node1, out);
    ae::destroyTree(node1);
    EXPECT_STREQ(out.str().c_str(), "8 ");
    out.str("");
  }
  {
    auto node1 = ae::createTreeNode<int>(8, nullptr, nullptr);
    ae::mirrorTree_v2(node1);
    ae::printTree(node1, out);
    ae::destroyTree(node1);
    EXPECT_STREQ(out.str().c_str(), "8 ");
    out.str("");
  }
  {
    ae::mirrorTree_v1<int>(nullptr);
    ae::mirrorTree_v2<int>(nullptr);
  }
}
