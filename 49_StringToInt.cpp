/*
 * Copyright (C) 2017, Yeolar
 */

#include <stdexcept>
#include <gtest/gtest.h>

namespace ae {

int strToInt(const char* str) {
  if (str == nullptr || *str == '\0') {
    throw std::invalid_argument("Empty string");
  }
  bool negative = false;
  if (*str == '+') {
    str++;
  } else if (*str == '-') {
    str++;
    negative = true;
  }
  if (*str == '\0') {
    throw std::invalid_argument("Invalid string");
  }
  long long num = 0;
  while (*str != '\0') {
    if (*str >= '0' && *str <= '9') {
      num = num * 10 + *str - '0';
      if ((num > 0x7FFFFFFF && !negative) ||
          (num > 0x80000000 && negative)) {
        throw std::overflow_error("Too long string");
      }
      str++;
    } else {
      throw std::invalid_argument("Invalid string");
    }
  }
  return negative ? -num : num;
}

} // namespace ae

TEST(strToInt, all) {
  EXPECT_THROW(ae::strToInt(nullptr), std::invalid_argument);
  EXPECT_THROW(ae::strToInt(""), std::invalid_argument);
  EXPECT_EQ(ae::strToInt("123"), 123);
  EXPECT_EQ(ae::strToInt("+123"), 123);
  EXPECT_EQ(ae::strToInt("-123"), -123);
  EXPECT_THROW(ae::strToInt("1a33"), std::invalid_argument);
  EXPECT_EQ(ae::strToInt("+0"), 0);
  EXPECT_EQ(ae::strToInt("-0"), 0);
  EXPECT_EQ(ae::strToInt("+2147483647"), 2147483647);
  EXPECT_EQ(ae::strToInt("-2147483647"), -2147483647);
  EXPECT_THROW(ae::strToInt("+2147483648"), std::overflow_error);
  EXPECT_EQ(ae::strToInt("-2147483648"), -2147483648);
  EXPECT_THROW(ae::strToInt("+2147483649"), std::overflow_error);
  EXPECT_THROW(ae::strToInt("-2147483649"), std::overflow_error);
  EXPECT_THROW(ae::strToInt("+"), std::invalid_argument);
  EXPECT_THROW(ae::strToInt("-"), std::invalid_argument);
}
