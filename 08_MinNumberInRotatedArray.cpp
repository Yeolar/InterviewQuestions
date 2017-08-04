/*
 * Copyright (C) 2017, Yeolar
 *
 * 找出旋转数组的最小数字
 */

#include <stdexcept>
#include <vector>
#include <gtest/gtest.h>

namespace ae {

template <class T>
int minInOrder(const std::vector<T>& array, int i, int j) {
  T result = array[i];
  for (int k = i + 1; k <= j; k++) {
    if (result > array[k]) {
      result = array[k];
    }
  }
  return result;
}

template <class T>
int min(const std::vector<T>& array) {
  if (array.empty()) {
    throw std::invalid_argument("Empty array");
  }
  int i = 0;
  int j = array.size() - 1;
  int m = i;
  while (array[i] >= array[j]) {
    // 如果index1和index2指向相邻的两个数，
    // 则index1指向第一个递增子数组的最后一个数字，
    // index2指向第二个子数组的第一个数字，也就是数组中的最小数字
    if (j - i == 1) {
      m = j;
      break;
    }
    m = (i + j) / 2;
    // 如果下标为index1、index2和indexMid指向的三个数字相等，
    // 则只能顺序查找
    if (array[i] == array[j] && array[m] == array[i]) {
      return minInOrder(array, i, j);
    }
    // 缩小查找范围
    if (array[m] >= array[i]) {
      i = m;
    } else if (array[m] <= array[j]) {
      j = m;
    }
  }
  return array[m];
}

} // namespace ae

TEST(min, all) {
  std::vector<int> array1 = { 3, 4, 5, 1, 2 };
  EXPECT_EQ(ae::min(array1), 1);
  std::vector<int> array2 = { 3, 4, 5, 1, 1, 2 };
  EXPECT_EQ(ae::min(array2), 1);
  std::vector<int> array3 = { 3, 4, 5, 1, 2, 2 };
  EXPECT_EQ(ae::min(array3), 1);
  std::vector<int> array4 = { 1, 0, 1, 1, 1 };
  EXPECT_EQ(ae::min(array4), 0);
  std::vector<int> array5 = { 1, 2, 3, 4, 5 };
  EXPECT_EQ(ae::min(array5), 1);
  std::vector<int> array6 = { 2 };
  EXPECT_EQ(ae::min(array6), 2);
  std::vector<int> array7;
  EXPECT_THROW(ae::min(array7), std::invalid_argument);
}
