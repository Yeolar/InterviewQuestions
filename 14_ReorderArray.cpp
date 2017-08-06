/*
 * Copyright (C) 2017, Yeolar
 *
 * 调整数组顺序使奇数位于偶数前面
 */

#include <sstream>
#include <vector>
#include <gtest/gtest.h>

namespace ae {

template <class T>
void reorderOddEven(std::vector<T>& array) {
  if (array.empty()) return;
  auto it1 = array.begin();
  auto it2 = array.end() - 1;
  while (it1 < it2) {
    while (it1 < it2 && (*it1 % 2) != 0) it1++;
    while (it1 < it2 && (*it2 % 2) == 0) it2--;
    if (it1 < it2) {
      std::swap(*it1, *it2);
    }
  }
}

template <class T>
void printArray(const std::vector<T>& array, std::stringstream& out) {
  for (size_t i = 0; i < array.size(); i++) {
    out << array[i] << " ";
  }
}

} // namespace ae

TEST(reorderOddEven, all) {
  std::stringstream out;
  std::vector<int> numbers1 = { 1, 2, 3, 4, 5, 6, 7 };
  ae::reorderOddEven(numbers1);
  ae::printArray(numbers1, out);
  EXPECT_STREQ(out.str().c_str(), "1 7 3 5 4 6 2 ");
  out.str("");
  std::vector<int> numbers2 = { 2, 4, 6, 1, 3, 5, 7 };
  ae::reorderOddEven(numbers2);
  ae::printArray(numbers2, out);
  EXPECT_STREQ(out.str().c_str(), "7 5 3 1 6 4 2 ");
  out.str("");
  std::vector<int> numbers3 = { 1, 3, 5, 7, 2, 4, 6 };
  ae::reorderOddEven(numbers3);
  ae::printArray(numbers3, out);
  EXPECT_STREQ(out.str().c_str(), "1 3 5 7 2 4 6 ");
  out.str("");
  std::vector<int> numbers4 = { 1 };
  ae::reorderOddEven(numbers4);
  ae::printArray(numbers4, out);
  EXPECT_STREQ(out.str().c_str(), "1 ");
  out.str("");
  std::vector<int> numbers5 = { 2 };
  ae::reorderOddEven(numbers5);
  ae::printArray(numbers5, out);
  EXPECT_STREQ(out.str().c_str(), "2 ");
  out.str("");
  std::vector<int> numbers6 = {};
  ae::reorderOddEven(numbers6);
  ae::printArray(numbers6, out);
  EXPECT_STREQ(out.str().c_str(), "");
  out.str("");
}
