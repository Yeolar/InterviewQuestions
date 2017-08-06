/*
 * Copyright (C) 2017, Yeolar
 *
 * 链表中倒数第k个结点
 */

#include <list>
#include <stddef.h>
#include <gtest/gtest.h>

namespace ae {

template <class T>
typename std::list<T>::const_iterator
findKthFromEnd(const std::list<T>& list, unsigned int k) {
  if (list.empty() || k == 0) return list.end();
  auto it1 = list.begin();
  auto it2 = list.begin();
  for (unsigned int i = 0; i < k; i++) {
    if (it1 != list.end()) {
      std::advance(it1, 1);
    } else {
      return list.end();
    }
  }
  while (it1 != list.end()) {
    std::advance(it1, 1);
    std::advance(it2, 1);
  }
  return it2;
}

} // namespace ae

TEST(findKthFromEnd, all) {
  std::list<int> list1 = { 1, 2, 3, 4, 5 };
  auto it1 = ae::findKthFromEnd(list1, 2);
  EXPECT_EQ(*it1, 4);
  std::list<int> list2 = { 1, 2, 3, 4, 5 };
  auto it2 = ae::findKthFromEnd(list2, 1);
  EXPECT_EQ(*it2, 5);
  std::list<int> list3 = { 1, 2, 3, 4, 5 };
  auto it3 = ae::findKthFromEnd(list3, 5);
  EXPECT_EQ(*it3, 1);
  std::list<int> list4 = {};
  auto it4 = ae::findKthFromEnd(list4, 100);
  EXPECT_EQ(it4, list4.end());
  std::list<int> list5 = { 1, 2, 3, 4, 5 };
  auto it5 = ae::findKthFromEnd(list5, 6);
  EXPECT_EQ(it5, list5.end());
  std::list<int> list6 = { 1, 2, 3, 4, 5 };
  auto it6 = ae::findKthFromEnd(list6, 0);
  EXPECT_EQ(it6, list6.end());
}
