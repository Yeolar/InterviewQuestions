/*
 * Copyright (C) 2017, Yeolar
 */

#include <queue>
#include <gtest/gtest.h>
#include "BinaryTree.h"

namespace ae {

template <class T>
void printFromTopToBottom(BinaryTreeNode<T>* root, std::stringstream& out) {
  if (root == nullptr) return;
  std::queue<BinaryTreeNode<T>*> queue;
  queue.push(root);
  while (!queue.empty()) {
    BinaryTreeNode<T>* node = queue.front();
    queue.pop();
    out << node->value << " ";
    if (node->left) {
      queue.push(node->left);
    }
    if (node->right) {
      queue.push(node->right);
    }
  }
}

} // namespace ae

TEST(printFromTopToBottom, all) {
  std::stringstream out;
  {
    auto node7 = ae::createTreeNode<int>(16, nullptr, nullptr);
    auto node6 = ae::createTreeNode<int>(12, nullptr, nullptr);
    auto node5 = ae::createTreeNode<int>(8, nullptr, nullptr);
    auto node4 = ae::createTreeNode<int>(4, nullptr, nullptr);
    auto node3 = ae::createTreeNode<int>(14, node6, node7);
    auto node2 = ae::createTreeNode<int>(6, node4, node5);
    auto node1 = ae::createTreeNode<int>(10, node2, node3);
    ae::printFromTopToBottom(node1, out);
    ae::destroyTree(node1);
    EXPECT_STREQ(out.str().c_str(), "10 6 14 4 8 12 16 ");
    out.str("");
  }
  {
    auto node5 = ae::createTreeNode<int>(1, nullptr, nullptr);
    auto node4 = ae::createTreeNode<int>(2, node5, nullptr);
    auto node3 = ae::createTreeNode<int>(3, node4, nullptr);
    auto node2 = ae::createTreeNode<int>(4, node3, nullptr);
    auto node1 = ae::createTreeNode<int>(5, node2, nullptr);
    ae::printFromTopToBottom(node1, out);
    ae::destroyTree(node1);
    EXPECT_STREQ(out.str().c_str(), "5 4 3 2 1 ");
    out.str("");
  }
  {
    auto node5 = ae::createTreeNode<int>(5, nullptr, nullptr);
    auto node4 = ae::createTreeNode<int>(4, node5, nullptr);
    auto node3 = ae::createTreeNode<int>(3, node4, nullptr);
    auto node2 = ae::createTreeNode<int>(2, node3, nullptr);
    auto node1 = ae::createTreeNode<int>(1, node2, nullptr);
    ae::printFromTopToBottom(node1, out);
    ae::destroyTree(node1);
    EXPECT_STREQ(out.str().c_str(), "1 2 3 4 5 ");
    out.str("");
  }
  {
    auto node1 = ae::createTreeNode<int>(1, nullptr, nullptr);
    ae::printFromTopToBottom(node1, out);
    ae::destroyTree(node1);
    EXPECT_STREQ(out.str().c_str(), "1 ");
    out.str("");
  }
  {
    ae::printFromTopToBottom<int>(nullptr, out);
    EXPECT_STREQ(out.str().c_str(), "");
    out.str("");
  }
}
