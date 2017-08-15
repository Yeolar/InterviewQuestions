/*
 * Copyright (C) 2017, Yeolar
 */

#include <gtest/gtest.h>
#include "List.h"

namespace ae {

template <class T>
size_t getListLength(ListNode<T>* list) {
  size_t n = 0;
  while (list != nullptr) {
    n++;
    list = list->next;
  }
  return n;
}

template <class T>
ListNode<T>* findFirstCommonNode(ListNode<T>* list1, ListNode<T>* list2) {
  size_t n1 = getListLength(list1);
  size_t n2 = getListLength(list2);
  size_t m;
  ListNode<T>* node1;
  ListNode<T>* node2;
  if (n1 > n2) {
    node1 = list1;
    node2 = list2;
    m = n1 - n2;
  } else {
    node1 = list2;
    node2 = list1;
    m = n2 - n1;
  }
  for (size_t i = 0; i < m; i++) {
    node1 = node1->next;
  }
  while (node1 != nullptr && node2 != nullptr && node1 != node2) {
    node1 = node1->next;
    node2 = node2->next;
  }
  return node1;
}

} // namespace ae

TEST(findFirstCommonNode, all) {
  {
    auto node7 = ae::createListNode<int>(7, nullptr);
    auto node6 = ae::createListNode<int>(6, node7);
    auto node5 = ae::createListNode<int>(5, node6);
    auto node4 = ae::createListNode<int>(4, node5);
    auto node3 = ae::createListNode<int>(3, node6);
    auto node2 = ae::createListNode<int>(2, node3);
    auto node1 = ae::createListNode<int>(1, node2);
    EXPECT_EQ(ae::findFirstCommonNode(node1, node4), node6);
    node3->next = nullptr;
    ae::destroyList(node1);
    ae::destroyList(node4);
  }
  {
    auto node7 = ae::createListNode<int>(7, nullptr);
    auto node6 = ae::createListNode<int>(6, node7);
    auto node5 = ae::createListNode<int>(5, node6);
    auto node4 = ae::createListNode<int>(4, nullptr);
    auto node3 = ae::createListNode<int>(3, node4);
    auto node2 = ae::createListNode<int>(2, node3);
    auto node1 = ae::createListNode<int>(1, node2);
    EXPECT_EQ(ae::findFirstCommonNode(node1, node5), nullptr);
    ae::destroyList(node1);
    ae::destroyList(node5);
  }
  {
    auto node7 = ae::createListNode<int>(7, nullptr);
    auto node6 = ae::createListNode<int>(6, node7);
    auto node5 = ae::createListNode<int>(5, node6);
    auto node4 = ae::createListNode<int>(4, node7);
    auto node3 = ae::createListNode<int>(3, node4);
    auto node2 = ae::createListNode<int>(2, node3);
    auto node1 = ae::createListNode<int>(1, node2);
    EXPECT_EQ(ae::findFirstCommonNode(node1, node5), node7);
    node4->next = nullptr;
    ae::destroyList(node1);
    ae::destroyList(node5);
  }
  {
    auto node5 = ae::createListNode<int>(5, nullptr);
    auto node4 = ae::createListNode<int>(4, node5);
    auto node3 = ae::createListNode<int>(3, node4);
    auto node2 = ae::createListNode<int>(2, node3);
    auto node1 = ae::createListNode<int>(1, node2);
    EXPECT_EQ(ae::findFirstCommonNode(node1, node1), node1);
    ae::destroyList(node1);
  }
  {
    auto node5 = ae::createListNode<int>(5, nullptr);
    auto node4 = ae::createListNode<int>(4, node5);
    auto node3 = ae::createListNode<int>(3, node4);
    auto node2 = ae::createListNode<int>(2, node3);
    auto node1 = ae::createListNode<int>(1, node2);
    EXPECT_EQ(ae::findFirstCommonNode<int>(nullptr, node1), nullptr);
    ae::destroyList(node1);
  }
  {
    EXPECT_EQ(ae::findFirstCommonNode<int>(nullptr, nullptr), nullptr);
  }
}
