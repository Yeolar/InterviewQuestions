/*
 * Copyright (C) 2017, Yeolar
 */

#include <gtest/gtest.h>
#include "Tree.h"

namespace ae {

template <class T>
bool getNodePath(TreeNode<T>* root, TreeNode<T>* node,
                 std::vector<TreeNode<T>*>& path) {
  if (root == node) return true;
  path.push_back(root);
  bool found = false;
  auto it = root->children.begin();
  while (!found && it != root->children.end()) {
    found = getNodePath(*it, node, path);
    it++;
  }
  if (!found) {
    path.pop_back();
  }
  return found;
}

template <class T>
TreeNode<T>* getLastCommonNode(const std::vector<TreeNode<T>*>& path1,
                               const std::vector<TreeNode<T>*>& path2) {
  auto it1 = path1.begin();
  auto it2 = path2.begin();
  TreeNode<T>* last = nullptr;
  while (it1 != path1.end() && it2 != path2.end()) {
    if (*it1 == *it2) {
      last = *it1;
    }
    it1++;
    it2++;
  }
  return last;
}

template <class T>
TreeNode<T>* getLastCommonParent(TreeNode<T>* root,
                                 TreeNode<T>* node1,
                                 TreeNode<T>* node2) {
  if (root == nullptr || node1 == nullptr || node2 == nullptr) return nullptr;
  std::vector<TreeNode<T>*> path1;
  getNodePath(root, node1, path1);
  std::vector<TreeNode<T>*> path2;
  getNodePath(root, node2, path2);
  return getLastCommonNode(path1, path2);
}

} // namespace ae

TEST(getLastCommonParent, all) {
  {
    auto node1 = ae::createTreeNode<int>(1, nullptr);
    auto node2 = ae::createTreeNode<int>(2, node1);
    auto node3 = ae::createTreeNode<int>(3, node1);
    auto node4 = ae::createTreeNode<int>(4, node2);
    auto node5 = ae::createTreeNode<int>(5, node2);
    auto node6 = ae::createTreeNode<int>(6, node4);
    auto node7 = ae::createTreeNode<int>(7, node4);
    auto node8 = ae::createTreeNode<int>(8, node5);
    auto node9 = ae::createTreeNode<int>(9, node5);
    auto node10 = ae::createTreeNode<int>(10, node5);
    EXPECT_EQ(ae::getLastCommonParent(node1, node6, node8), node2);
    ae::destroyTree(node1);
  }
  {
    auto node1 = ae::createTreeNode<int>(1, nullptr);
    auto node2 = ae::createTreeNode<int>(2, node1);
    auto node3 = ae::createTreeNode<int>(3, node2);
    auto node4 = ae::createTreeNode<int>(4, node3);
    auto node5 = ae::createTreeNode<int>(5, node4);
    EXPECT_EQ(ae::getLastCommonParent(node1, node5, node4), node3);
    ae::destroyTree(node1);
  }
  {
    auto node1 = ae::createTreeNode<int>(1, nullptr);
    auto node2 = ae::createTreeNode<int>(2, node1);
    auto node3 = ae::createTreeNode<int>(3, node2);
    auto node4 = ae::createTreeNode<int>(4, node3);
    auto node5 = ae::createTreeNode<int>(5, node4);
    auto node6 = ae::createTreeNode<int>(6, nullptr);
    EXPECT_EQ(ae::getLastCommonParent(node1, node5, node6), nullptr);
    ae::destroyTree(node1);
  }
  {
    EXPECT_EQ(ae::getLastCommonParent<int>(nullptr, nullptr, nullptr), nullptr);
  }
}
