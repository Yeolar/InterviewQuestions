/*
 * Copyright (C) 2017, Yeolar
 */

#include <sstream>

namespace ae {

template <class T>
struct ListNode {
  T value;
  ListNode* next;
};

template <class T>
ListNode<T>* createListNode(const T& value, ListNode<T>* next) {
  ListNode<T>* node = new ListNode<T>();
  node->value = value;
  node->next = next;
  return node;
}

template <class T>
void destroyList(ListNode<T>* node) {
  if (node != nullptr) {
    destroyList(node->next);
    delete node;
    node = nullptr;
  }
}

template <class T>
void printList(ListNode<T>* node, std::stringstream& out) {
  if (node != nullptr) {
    out << node->value << " ";
    printList(node->next, out);
  }
}

} // namespace ae
