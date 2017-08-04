/*
 * Copyright (C) 2017, Yeolar
 *
 * 二进制表示中1的个数
 */

#include <stddef.h>
#include <gtest/gtest.h>

namespace ae {

size_t numberOf1_v1(int n) {
  size_t count = 0;
  unsigned int flag = 1;
  while (flag) {
    if (n & flag) {
      count++;
    }
    flag = flag << 1;
  }
  return count;
}

size_t numberOf1_v2(int n) {
  size_t count = 0;
  while (n) {
    count++;
    n = (n - 1) & n;
  }
  return count;
}

} // namespace ae

TEST(numberOf1, all) {
  EXPECT_EQ(ae::numberOf1_v1(0), 0);
  EXPECT_EQ(ae::numberOf1_v2(0), 0);
  EXPECT_EQ(ae::numberOf1_v1(1), 1);
  EXPECT_EQ(ae::numberOf1_v2(1), 1);
  EXPECT_EQ(ae::numberOf1_v1(10), 2);
  EXPECT_EQ(ae::numberOf1_v2(10), 2);
  EXPECT_EQ(ae::numberOf1_v1(0x7FFFFFFF), 31);
  EXPECT_EQ(ae::numberOf1_v2(0x7FFFFFFF), 31);
  EXPECT_EQ(ae::numberOf1_v1(0xFFFFFFFF), 32);
  EXPECT_EQ(ae::numberOf1_v2(0xFFFFFFFF), 32);
  EXPECT_EQ(ae::numberOf1_v1(0x80000000), 1);
  EXPECT_EQ(ae::numberOf1_v2(0x80000000), 1);
}
