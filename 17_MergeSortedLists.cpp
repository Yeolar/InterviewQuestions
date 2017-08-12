/*
 * Copyright (C) 2017, Yeolar
 *
 * 合并两个排序的链表
 */

#include <gtest/gtest.h>
#include "List.h"

namespace ae {

template <class T>
ListNode<T>* mergeList_v1(ListNode<T>* list1, ListNode<T>* list2) {
  if (list1 == nullptr) return list2;
  if (list2 == nullptr) return list1;
  ListNode<T>* mergedList = nullptr;
  if (list1->value < list2->value) {
    mergedList = list1;
    mergedList->next = mergeList_v1(list1->next, list2);
  } else {
    mergedList = list2;
    mergedList->next = mergeList_v1(list1, list2->next);
  }
  return mergedList;
}

template <class T>
ListNode<T>* mergeList_v2(ListNode<T>* list1, ListNode<T>* list2) {
  if (list1 == nullptr) return list2;
  if (list2 == nullptr) return list1;
  ListNode<T>* mergedList = nullptr;
  if (list1->value < list2->value) {
    mergedList = list1;
    list1 = list1->next;
  } else {
    mergedList = list2;
    list2 = list2->next;
  }
  ListNode<T>* list = mergedList;
  while (list1 && list2) {
    if (list1->value < list2->value) {
      list->next = list1;
      list1 = list1->next;
    } else {
      list->next = list2;
      list2 = list2->next;
    }
    list = list->next;
  }
  if (list1) {
    list->next = list1;
  }
  if (list2) {
    list->next = list2;
  }
  return mergedList;
}

} // namespace ae

TEST(mergeList, all) {
  std::stringstream out;
  {
    auto node6 = ae::createListNode<int>(6, nullptr);
    auto node4 = ae::createListNode(4, node6);
    auto node2 = ae::createListNode(2, node4);
    auto node5 = ae::createListNode<int>(5, nullptr);
    auto node3 = ae::createListNode(3, node5);
    auto node1 = ae::createListNode(1, node3);
    auto list = ae::mergeList_v1(node1, node2);
    ae::printList(list, out);
    EXPECT_STREQ(out.str().c_str(), "1 2 3 4 5 6 ");
    out.str("");
  }
  {
    auto node6 = ae::createListNode<int>(6, nullptr);
    auto node4 = ae::createListNode(4, node6);
    auto node2 = ae::createListNode(2, node4);
    auto node5 = ae::createListNode<int>(5, nullptr);
    auto node3 = ae::createListNode(3, node5);
    auto node1 = ae::createListNode(1, node3);
    auto list = ae::mergeList_v2(node1, node2);
    ae::printList(list, out);
    EXPECT_STREQ(out.str().c_str(), "1 2 3 4 5 6 ");
    out.str("");
  }
  {
    auto node6 = ae::createListNode<int>(5, nullptr);
    auto node4 = ae::createListNode(3, node6);
    auto node2 = ae::createListNode(1, node4);
    auto node5 = ae::createListNode<int>(5, nullptr);
    auto node3 = ae::createListNode(3, node5);
    auto node1 = ae::createListNode(1, node3);
    auto list = ae::mergeList_v1(node1, node2);
    ae::printList(list, out);
    EXPECT_STREQ(out.str().c_str(), "1 1 3 3 5 5 ");
    out.str("");
  }
  {
    auto node6 = ae::createListNode<int>(5, nullptr);
    auto node4 = ae::createListNode(3, node6);
    auto node2 = ae::createListNode(1, node4);
    auto node5 = ae::createListNode<int>(5, nullptr);
    auto node3 = ae::createListNode(3, node5);
    auto node1 = ae::createListNode(1, node3);
    auto list = ae::mergeList_v2(node1, node2);
    ae::printList(list, out);
    EXPECT_STREQ(out.str().c_str(), "1 1 3 3 5 5 ");
    out.str("");
  }
  {
    auto node1 = ae::createListNode<int>(1, nullptr);
    auto node2 = ae::createListNode<int>(2, nullptr);
    auto list = ae::mergeList_v1(node1, node2);
    ae::printList(list, out);
    EXPECT_STREQ(out.str().c_str(), "1 2 ");
    out.str("");
  }
  {
    auto node1 = ae::createListNode<int>(1, nullptr);
    auto node2 = ae::createListNode<int>(2, nullptr);
    auto list = ae::mergeList_v2(node1, node2);
    ae::printList(list, out);
    EXPECT_STREQ(out.str().c_str(), "1 2 ");
    out.str("");
  }
  {
    auto node5 = ae::createListNode<int>(5, nullptr);
    auto node3 = ae::createListNode(3, node5);
    auto node1 = ae::createListNode(1, node3);
    auto list = ae::mergeList_v1<int>(node1, nullptr);
    ae::printList(list, out);
    EXPECT_STREQ(out.str().c_str(), "1 3 5 ");
    out.str("");
  }
  {
    auto node5 = ae::createListNode<int>(5, nullptr);
    auto node3 = ae::createListNode(3, node5);
    auto node1 = ae::createListNode(1, node3);
    auto list = ae::mergeList_v2<int>(node1, nullptr);
    ae::printList(list, out);
    EXPECT_STREQ(out.str().c_str(), "1 3 5 ");
    out.str("");
  }
  {
    auto list = ae::mergeList_v1<int>(nullptr, nullptr);
    ae::printList(list, out);
    EXPECT_STREQ(out.str().c_str(), "");
    out.str("");
  }
  {
    auto list = ae::mergeList_v2<int>(nullptr, nullptr);
    ae::printList(list, out);
    EXPECT_STREQ(out.str().c_str(), "");
    out.str("");
  }
}
