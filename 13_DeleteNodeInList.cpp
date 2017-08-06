/*
 * Copyright (C) 2017, Yeolar
 *
 * 在O(1)时间删除链表结点
 */

#include <gtest/gtest.h>
#include "List.h"

namespace ae {

template <class T>
void deleteListNode(ListNode<T>** list, ListNode<T>* node) {
  if (list == nullptr || node == nullptr) {
    return;
  }
  // 要删除的结点不是尾结点
  if (node->next != nullptr) {
    ListNode<T>* next = node->next;
    node->value = next->value;
    node->next = next->next;
    delete next;
    next = nullptr;
  }
  // 链表只有一个结点
  else if (node == *list) {
    delete node;
    node = nullptr;
    *list = nullptr;
  }
  // 链表中有多个结点
  else {
    ListNode<T>* it = *list;
    while (it->next != node) {
      it = it->next;
    }
    it->next = nullptr;
    delete node;
    node = nullptr;
  }
}

} // namespace ae

TEST(deleteListNode, all) {
  std::stringstream out;
  {
    auto node5 = ae::createListNode<int>(5, nullptr);
    auto node4 = ae::createListNode<int>(4, node5);
    auto node3 = ae::createListNode<int>(3, node4);
    auto node2 = ae::createListNode<int>(2, node3);
    auto node1 = ae::createListNode<int>(1, node2);
    ae::deleteListNode(&node1, node3);
    ae::printList(node1, out);
    EXPECT_STREQ(out.str().c_str(), "1 2 4 5 ");
    out.str("");
    ae::destroyList(node1);
  }
  {
    auto node5 = ae::createListNode<int>(5, nullptr);
    auto node4 = ae::createListNode<int>(4, node5);
    auto node3 = ae::createListNode<int>(3, node4);
    auto node2 = ae::createListNode<int>(2, node3);
    auto node1 = ae::createListNode<int>(1, node2);
    ae::deleteListNode(&node1, node5);
    ae::printList(node1, out);
    EXPECT_STREQ(out.str().c_str(), "1 2 3 4 ");
    out.str("");
    ae::destroyList(node1);
  }
  {
    auto node5 = ae::createListNode<int>(5, nullptr);
    auto node4 = ae::createListNode<int>(4, node5);
    auto node3 = ae::createListNode<int>(3, node4);
    auto node2 = ae::createListNode<int>(2, node3);
    auto node1 = ae::createListNode<int>(1, node2);
    ae::deleteListNode(&node1, node1);
    ae::printList(node1, out);
    EXPECT_STREQ(out.str().c_str(), "2 3 4 5 ");
    out.str("");
    ae::destroyList(node1);
  }
  {
    auto node1 = ae::createListNode<int>(1, nullptr);
    ae::deleteListNode(&node1, node1);
    ae::printList(node1, out);
    EXPECT_STREQ(out.str().c_str(), "");
    out.str("");
    ae::destroyList(node1);
  }
  {
    ae::deleteListNode<int>(nullptr, nullptr);
  }
}
