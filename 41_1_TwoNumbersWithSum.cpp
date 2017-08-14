/*
 * Copyright (C) 2017, Yeolar
 */

#include <vector>
#include <gtest/gtest.h>

namespace ae {

bool findNumbersWithSum(const std::vector<int>& data, int sum,
                        int& num1, int& num2) {
  if (data.size() < 2) return false;
  int first = 0;
  int second = data.size() - 1;
  while (first < second) {
    long long currentSum = data[first] + data[second];
    if (currentSum == sum) {
      num1 = data[first];
      num2 = data[second];
      return true;
    } else if (currentSum < sum) {
      first++;
    } else {
      second--;
    }
  }
  return false;
}

} // namespace ae

TEST(findNumbersWithSum, all) {
  {
    std::vector<int> data = { 1, 2, 4, 7, 11, 15 };
    int num1, num2;
    EXPECT_TRUE(ae::findNumbersWithSum(data, 15, num1, num2));
  }
  {
    std::vector<int> data = { 1, 2, 4, 7, 11, 16 };
    int num1, num2;
    EXPECT_TRUE(ae::findNumbersWithSum(data, 17, num1, num2));
  }
  {
    std::vector<int> data = { 1, 2, 4, 7, 11, 16 };
    int num1, num2;
    EXPECT_FALSE(ae::findNumbersWithSum(data, 10, num1, num2));
  }
  {
    std::vector<int> data = {};
    int num1, num2;
    EXPECT_FALSE(ae::findNumbersWithSum(data, 0, num1, num2));
  }
}
