/*
 * Copyright (C) 2017, Yeolar
 */

#include <list>
#include <sstream>
#include <stack>
#include <gtest/gtest.h>

namespace ae {

template <class Iter>
void printListReverse_v1(Iter it, const Iter& end, std::stringstream& out) {
  std::stack<Iter> nodes;
  while (it != end) {
    nodes.push(it++);
  }
  while (!nodes.empty()) {
    it = nodes.top();
    out << *it << " ";
    nodes.pop();
  }
}

template <class Iter>
void printListReverse_v2(Iter it, const Iter& end, std::stringstream& out) {
  if (it != end) {
    printListReverse_v2(std::next(it, 1), end, out);
    out << *it << " ";
  }
}

} // namespace ae

TEST(printListReverse, all) {
  std::stringstream out;

  std::list<int> list1 = { 1, 2, 3, 4, 5 };
  ae::printListReverse_v1(list1.begin(), list1.end(), out);
  EXPECT_STREQ(out.str().c_str(), "5 4 3 2 1 ");
  out.str("");
  ae::printListReverse_v2(list1.begin(), list1.end(), out);
  EXPECT_STREQ(out.str().c_str(), "5 4 3 2 1 ");
  out.str("");

  std::list<int> list2 = { 1 };
  ae::printListReverse_v1(list2.begin(), list2.end(), out);
  EXPECT_STREQ(out.str().c_str(), "1 ");
  out.str("");
  ae::printListReverse_v2(list2.begin(), list2.end(), out);
  EXPECT_STREQ(out.str().c_str(), "1 ");
  out.str("");

  std::list<int> list3 = {};
  ae::printListReverse_v1(list3.begin(), list3.end(), out);
  EXPECT_STREQ(out.str().c_str(), "");
  out.str("");
  ae::printListReverse_v2(list3.begin(), list3.end(), out);
  EXPECT_STREQ(out.str().c_str(), "");
  out.str("");
}
