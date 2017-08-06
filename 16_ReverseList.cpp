/*
 * Copyright (C) 2017, Yeolar
 *
 * 反转链表
 */

#include <gtest/gtest.h>
#include "List.h"

namespace ae {

template <class T>
ListNode<T>* reverseList(ListNode<T>* list) {
  ListNode<T>* node = list;
  ListNode<T>* prev = nullptr;
  while (node != nullptr) {
    ListNode<T>* next = node->next;
    node->next = prev;
    prev = node;
    node = next;
  }
  return prev;
}

} // namespace ae

TEST(reverseList, all) {
  std::stringstream out;
  {
    auto node5 = ae::createListNode<int>(5, nullptr);
    auto node4 = ae::createListNode(4, node5);
    auto node3 = ae::createListNode(3, node4);
    auto node2 = ae::createListNode(2, node3);
    auto node1 = ae::createListNode(1, node2);
    auto list = ae::reverseList(node1);
    ae::printList(list, out);
    EXPECT_STREQ(out.str().c_str(), "5 4 3 2 1 ");
    out.str("");
  }
  {
    auto node1 = ae::createListNode<int>(1, nullptr);
    auto list = ae::reverseList(node1);
    ae::printList(list, out);
    EXPECT_STREQ(out.str().c_str(), "1 ");
    out.str("");
  }
  {
    auto list = ae::reverseList<int>(nullptr);
    ae::printList(list, out);
    EXPECT_STREQ(out.str().c_str(), "");
    out.str("");
  }
}
