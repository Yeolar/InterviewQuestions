/*
 * Copyright (C) 2017, Yeolar
 */

#include <stdexcept>
#include <vector>
#include <gtest/gtest.h>

namespace ae {

long long findGreatestSumOfSubArray(const std::vector<int>& numbers) {
  if (numbers.empty()) {
    throw std::invalid_argument("Empty array");
  }
  long long sum = 0;
  long long result = (int)0x80000000;  // INT_MIN
  for (size_t i = 0; i < numbers.size(); i++) {
    if (sum <= 0) {
      sum = numbers[i];
    } else {
      sum += numbers[i];
    }
    if (sum > result) {
      result = sum;
    }
  }
  return result;
}

} // namespace ae

TEST(findGreatestSumOfSubArray, all) {
  {
    std::vector<int> numbers = { 1, -2, 3, 10, -4, 7, 2, -5 };
    EXPECT_EQ(ae::findGreatestSumOfSubArray(numbers), 18);
  }
  {
    std::vector<int> numbers = { -2, -8, -1, -5, -9 };
    EXPECT_EQ(ae::findGreatestSumOfSubArray(numbers), -1);
  }
  {
    std::vector<int> numbers = { 2, 8, 1, 5, 9 };
    EXPECT_EQ(ae::findGreatestSumOfSubArray(numbers), 25);
  }
  {
    std::vector<int> numbers = {};
    EXPECT_THROW(ae::findGreatestSumOfSubArray(numbers), std::invalid_argument);
  }
}
