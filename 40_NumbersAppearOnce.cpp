/*
 * Copyright (C) 2017, Yeolar
 */

#include <vector>
#include <stddef.h>
#include <gtest/gtest.h>

namespace ae {

int findFirstBit1(int num) {
  int index = 0;
  while ((num & 1) == 0 && index < (int)sizeof(int) * 8) {
    num = num >> 1;
    index++;
  }
  return index;
}

bool isBit1(int num, int index) {
  return (num >> index) & 1;
}

void findNumsAppearOnce(const std::vector<int>& data, int& num1, int& num2) {
  if (data.size() < 2) return;
  int mix = 0;
  for (size_t i = 0; i < data.size(); i++) {
    mix ^= data[i];
  }
  int indexOf1 = findFirstBit1(mix);
  num1 = num2 = 0;
  for (size_t i = 0; i < data.size(); i++) {
    if (isBit1(data[i], indexOf1)) {
      num1 ^= data[i];
    } else {
      num2 ^= data[i];
    }
  }
}

} // namespace ae

TEST(findNumsAppearOnce, all) {
  {
    std::vector<int> data = { 2, 4, 3, 6, 3, 2, 5, 5 };
    int num1, num2;
    ae::findNumsAppearOnce(data, num1, num2);
    EXPECT_EQ(num1, 6);
    EXPECT_EQ(num2, 4);
  }
  {
    std::vector<int> data = { 4, 6 };
    int num1, num2;
    ae::findNumsAppearOnce(data, num1, num2);
    EXPECT_EQ(num1, 6);
    EXPECT_EQ(num2, 4);
  }
  {
    std::vector<int> data = { 4, 6, 1, 1, 1, 1 };
    int num1, num2;
    ae::findNumsAppearOnce(data, num1, num2);
    EXPECT_EQ(num1, 6);
    EXPECT_EQ(num2, 4);
  }
}
