/*
 * Copyright (C) 2017, Yeolar
 */

#include <vector>
#include <gtest/gtest.h>

namespace ae {

int partition(std::vector<int>& data, int begin, int end) {
  if (data.empty() || begin < 0 || end >= (int)data.size()) {
    throw std::invalid_argument("Invalid args");
  }
  int i = (begin + end) / 2;
  std::swap(data[i], data[end]);
  int small = begin - 1;
  for (i = begin; i < end; i++) {
    if (data[i] < data[end]) {
      small++;
      if (small != i) {
        std::swap(data[i], data[small]);
      }
    }
  }
  small++;
  std::swap(data[small], data[end]);
  return small;
}

bool checkMoreThanHalf(const std::vector<int>& numbers, int number) {
  size_t times = 0;
  for (size_t i = 0; i < numbers.size(); i++) {
    if (numbers[i] == number) {
      times++;
    }
  }
  return times * 2 > numbers.size();
}

int moreThanHalfNum_v1(std::vector<int>& numbers) {
  if (numbers.empty()) {
    throw std::invalid_argument("Invalid numbers");
  }
  int mid = numbers.size() / 2;
  int begin = 0;
  int end = numbers.size() - 1;
  int i = partition(numbers, begin, end);
  while (i != mid) {
    if (i > mid) {
      end = i - 1;
      i = partition(numbers, begin, end);
    } else {
      begin = i + 1;
      i = partition(numbers, begin, end);
    }
  }
  int result = numbers[mid];
  if (checkMoreThanHalf(numbers, result)) {
    return result;
  }
  return 0;
}

int moreThanHalfNum_v2(const std::vector<int>& numbers) {
  if (numbers.empty()) {
    throw std::invalid_argument("Invalid numbers");
  }
  int result = numbers[0];
  size_t times = 1;
  for (size_t i = 1; i < numbers.size(); i++) {
    if (times == 0) {
      result = numbers[i];
      times = 1;
    } else if (numbers[i] == result) {
      times++;
    } else {
      times--;
    }
  }
  if (checkMoreThanHalf(numbers, result)) {
    return result;
  }
  return 0;
}

} // namespace ae

TEST(moreThanHalfNum, all) {
  {
    std::vector<int> numbers = { 1, 2, 3, 2, 2, 2, 5, 4, 2 };
    EXPECT_EQ(ae::moreThanHalfNum_v2(numbers), 2);
    EXPECT_EQ(ae::moreThanHalfNum_v1(numbers), 2);
  }
  {
    std::vector<int> numbers = { 1, 2, 3, 2, 4, 2, 5, 2, 3 };
    EXPECT_EQ(ae::moreThanHalfNum_v2(numbers), 0);
    EXPECT_EQ(ae::moreThanHalfNum_v1(numbers), 0);
  }
  {
    std::vector<int> numbers = { 2, 2, 2, 2, 2, 1, 3, 4, 5 };
    EXPECT_EQ(ae::moreThanHalfNum_v2(numbers), 2);
    EXPECT_EQ(ae::moreThanHalfNum_v1(numbers), 2);
  }
  {
    std::vector<int> numbers = { 1, 3, 4, 5, 2, 2, 2, 2, 2 };
    EXPECT_EQ(ae::moreThanHalfNum_v2(numbers), 2);
    EXPECT_EQ(ae::moreThanHalfNum_v1(numbers), 2);
  }
  {
    std::vector<int> numbers = { 1 };
    EXPECT_EQ(ae::moreThanHalfNum_v2(numbers), 1);
    EXPECT_EQ(ae::moreThanHalfNum_v1(numbers), 1);
  }
  {
    std::vector<int> numbers = {};
    EXPECT_THROW(ae::moreThanHalfNum_v2(numbers), std::invalid_argument);
    EXPECT_THROW(ae::moreThanHalfNum_v1(numbers), std::invalid_argument);
  }
}
