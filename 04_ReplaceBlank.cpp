/*
 * Copyright (C) 2017, Yeolar
 */

#include <stdexcept>
#include <gtest/gtest.h>

namespace ae {

char* replaceBlank(char* string, size_t capacity) {
  if (string == nullptr || capacity == 0) {
    throw std::invalid_argument("Invalid args");
  }
  size_t length = 0;
  size_t numBlank = 0;
  char* p = string;
  while (*p != '\0') {
    length++;
    if (*p == ' ') {
      numBlank++;
    }
    p++;
  }
  size_t newLength = length + numBlank * 2;
  if (newLength > capacity) {
    throw std::overflow_error("Not enough buffer");
  }
  char* sp = string + length;
  char* tp = string + newLength;
  while (sp >= string && tp > sp) {
    if (*sp == ' ') {
      *tp-- = '0';
      *tp-- = '2';
      *tp-- = '%';
    } else {
      *tp-- = *sp;
    }
    sp--;
  }
  return string;
}

} // namespace ae

TEST(replaceBlank, all) {
  char string1[100] = "hello world";
  EXPECT_STREQ(ae::replaceBlank(string1, 100), "hello%20world");
  char string2[100] = " helloworld";
  EXPECT_STREQ(ae::replaceBlank(string2, 100), "%20helloworld");
  char string3[100] = "helloworld ";
  EXPECT_STREQ(ae::replaceBlank(string3, 100), "helloworld%20");
  char string4[100] = "hello  world";
  EXPECT_STREQ(ae::replaceBlank(string4, 100), "hello%20%20world");
  EXPECT_THROW(ae::replaceBlank(nullptr, 0), std::invalid_argument);
  char string5[100] = "";
  EXPECT_STREQ(ae::replaceBlank(string5, 100), "");
  char string6[100] = " ";
  EXPECT_STREQ(ae::replaceBlank(string6, 100), "%20");
  char string7[100] = "helloworld";
  EXPECT_STREQ(ae::replaceBlank(string7, 100), "helloworld");
  char string8[100] = "   ";
  EXPECT_STREQ(ae::replaceBlank(string8, 100), "%20%20%20");
  char string9[12] = "hello world";
  EXPECT_THROW(ae::replaceBlank(string9, 12), std::overflow_error);
}
