/*
 * Copyright (C) 2017, Yeolar
 */

#include <sstream>
#include <vector>

namespace ae {

template <class T>
struct TreeNode {
  T value;
  std::vector<TreeNode*> children;
};

template <class T>
TreeNode<T>* createTreeNode(const T& value, TreeNode<T>* parent) {
  TreeNode<T>* node = new TreeNode<T>();
  node->value = value;
  if (parent) {
    parent->children.push_back(node);
  }
  return node;
}

template <class T>
void destroyTree(TreeNode<T>* node) {
  if (node != nullptr) {
    for (auto it = node->children.begin(); it != node->children.end(); it++) {
      destroyTree(*it);
    }
    delete node;
    node = nullptr;
  }
}

template <class T>
void printTree(TreeNode<T>* node, std::stringstream& out) {
  if (node != nullptr) {
    out << node->value << " ";
    for (auto it = node->children.begin(); it != node->children.end(); it++) {
      printTree(*it, out);
    }
  }
}

} // namespace ae
