/*
 * Copyright (C) 2017, Yeolar
 *
 * 重建二叉树
 */

#include <stdexcept>
#include <vector>
#include <gtest/gtest.h>
#include "BinaryTree.h"

namespace ae {

template <class T, class Iter>
BinaryTreeNode<T>* constructTree(Iter preorderBegin,
                                 Iter preorderEnd,
                                 Iter inorderBegin,
                                 Iter inorderEnd) {
  if (preorderBegin == preorderEnd || inorderBegin == inorderEnd) {
    throw std::invalid_argument("Empty iterator input");
  }
  T value = *preorderBegin;
  BinaryTreeNode<T>* root = createTreeNode<T>(value, nullptr, nullptr);
  if (preorderEnd - preorderBegin == 1) {
    if (inorderEnd - inorderBegin == 1 && *preorderBegin == *inorderBegin) {
      return root;
    } else {
      throw std::invalid_argument("Invalid input");
    }
  }
  Iter inorderRoot = inorderBegin;
  while (inorderRoot < inorderEnd && *inorderRoot != value) {
    inorderRoot++;
  }
  if (inorderRoot == inorderEnd) {
    throw std::invalid_argument("Invalid input");
  }
  // preorder: M L L L R R R
  //  inorder: L L L M R R R
  Iter preorderRight = preorderBegin + 1 + (inorderRoot - inorderBegin);
  if (inorderRoot > inorderBegin) {
    root->left = constructTree<T>(preorderBegin + 1,
                                  preorderRight,
                                  inorderBegin,
                                  inorderRoot);
  }
  if (preorderRight < preorderEnd) {
    root->right = constructTree<T>(preorderRight,
                                   preorderEnd,
                                   inorderRoot + 1,
                                   inorderEnd);
  }
  return root;
}

} // namespace ae

TEST(constructTree, all) {
  std::stringstream out;
  {
    std::vector<int> preorder = {1, 2, 4, 7, 3, 5, 6, 8};
    std::vector<int> inorder = {4, 7, 2, 1, 5, 3, 8, 6};
    auto tree = ae::constructTree<int>(
        preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
    ae::printTree(tree, out);
    ae::destroyTree(tree);
    EXPECT_STREQ(out.str().c_str(), "1 2 4 7 3 5 6 8 ");
    out.str("");
  }
  {
    std::vector<int> preorder = {1, 2, 3, 4, 5};
    std::vector<int> inorder = {5, 4, 3, 2, 1};
    auto tree = ae::constructTree<int>(
        preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
    ae::printTree(tree, out);
    ae::destroyTree(tree);
    EXPECT_STREQ(out.str().c_str(), "1 2 3 4 5 ");
    out.str("");
  }
  {
    std::vector<int> preorder = {1, 2, 3, 4, 5};
    std::vector<int> inorder = {1, 2, 3, 4, 5};
    auto tree = ae::constructTree<int>(
        preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
    ae::printTree(tree, out);
    ae::destroyTree(tree);
    EXPECT_STREQ(out.str().c_str(), "1 2 3 4 5 ");
    out.str("");
  }
  {
    std::vector<int> preorder = {1};
    std::vector<int> inorder = {1};
    auto tree = ae::constructTree<int>(
        preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
    ae::printTree(tree, out);
    ae::destroyTree(tree);
    EXPECT_STREQ(out.str().c_str(), "1 ");
    out.str("");
  }
  {
    std::vector<int> preorder = {1, 2, 4, 5, 3, 6, 7};
    std::vector<int> inorder = {4, 2, 5, 1, 6, 3, 7};
    auto tree = ae::constructTree<int>(
        preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
    ae::printTree(tree, out);
    ae::destroyTree(tree);
    EXPECT_STREQ(out.str().c_str(), "1 2 4 5 3 6 7 ");
    out.str("");
  }
  {
    std::vector<int> preorder = {};
    std::vector<int> inorder = {};
    EXPECT_THROW(ae::constructTree<int>(
        preorder.begin(), preorder.end(), inorder.begin(), inorder.end()),
        std::invalid_argument);
  }
  {
    std::vector<int> preorder = {1, 2, 4, 5, 3, 6, 7};
    std::vector<int> inorder = {4, 2, 8, 1, 6, 3, 7};
    EXPECT_THROW(ae::constructTree<int>(
        preorder.begin(), preorder.end(), inorder.begin(), inorder.end()),
        std::invalid_argument);
  }
}
