/*
 * Copyright (C) 2017, Yeolar
 */

#include <vector>
#include <gtest/gtest.h>

namespace ae {

template <class T>
int getFirstK(const std::vector<T>& data, T k, int begin, int end) {
  if (begin > end) return -1;
  int mid = (begin + end) / 2;
  if (data[mid] == k) {
    if (mid == 0 || (mid > 0 && data[mid - 1] != k)) {
      return mid;
    } else {
      end = mid - 1;
    }
  } else if (data[mid] < k) {
    begin = mid + 1;
  } else {
    end = mid - 1;
  }
  return getFirstK(data, k, begin, end);
}

template <class T>
int getLastK(const std::vector<T>& data, T k, int begin, int end) {
  if (begin > end) return -1;
  int len = data.size();
  int mid = (begin + end) / 2;
  if (data[mid] == k) {
    if (mid == len - 1 || (mid < len - 1 && data[mid + 1] != k)) {
      return mid;
    } else {
      begin = mid + 1;
    }
  } else if (data[mid] < k) {
    begin = mid + 1;
  } else {
    end = mid - 1;
  }
  return getLastK(data, k, begin, end);
}

template <class T>
int getNumberOfK(const std::vector<T>& data, T k) {
  if (!data.empty()) {
    int first = getFirstK(data, k, 0, data.size() - 1);
    int last = getLastK(data, k, 0, data.size() - 1);
    if (first > -1 && last > -1) {
      return last - first + 1;
    }
  }
  return 0;
}

} // namespace ae

TEST(getNumberOfK, all) {
  std::vector<int> data1 = { 1, 2, 3, 3, 3, 3, 4, 5 };
  EXPECT_EQ(ae::getNumberOfK(data1, 3), 4);
  std::vector<int> data2 = { 3, 3, 3, 3, 4, 5 };
  EXPECT_EQ(ae::getNumberOfK(data2, 3), 4);
  std::vector<int> data3 = { 1, 2, 3, 3, 3, 3 };
  EXPECT_EQ(ae::getNumberOfK(data3, 3), 4);
  std::vector<int> data4 = { 1, 3, 3, 3, 3, 4, 5 };
  EXPECT_EQ(ae::getNumberOfK(data4, 2), 0);
  std::vector<int> data5 = { 1, 3, 3, 3, 3, 4, 5 };
  EXPECT_EQ(ae::getNumberOfK(data5, 0), 0);
  std::vector<int> data6 = { 1, 3, 3, 3, 3, 4, 5 };
  EXPECT_EQ(ae::getNumberOfK(data6, 6), 0);
  std::vector<int> data7 = { 3, 3, 3, 3 };
  EXPECT_EQ(ae::getNumberOfK(data7, 3), 4);
  std::vector<int> data8 = { 3, 3, 3, 3 };
  EXPECT_EQ(ae::getNumberOfK(data8, 4), 0);
  std::vector<int> data9 = { 3 };
  EXPECT_EQ(ae::getNumberOfK(data9, 3), 1);
  std::vector<int> data10 = { 3 };
  EXPECT_EQ(ae::getNumberOfK(data10, 4), 0);
  std::vector<int> data11 = {};
  EXPECT_EQ(ae::getNumberOfK(data11, 0), 0);
}
