/*
 * Copyright (C) 2017, Yeolar
 */

#include <string.h>
#include <utility>
#include <gtest/gtest.h>

namespace ae {

void reverse(char* begin, char* end) {
  if (begin == nullptr || end == nullptr) return;
  while (begin < end) {
    std::swap(*begin, *end);
    begin++;
    end--;
  }
}

char* rotateLeftOfString(char* str, int n) {
  if (str != nullptr) {
    int len = strlen(str);
    if (n > 0 && len > 0 && n < len) {
      char* firstBegin = str;
      char* firstEnd = str + n - 1;
      char* secondBegin = str + n;
      char* secondEnd = str + len - 1;
      reverse(firstBegin, firstEnd);
      reverse(secondBegin, secondEnd);
      reverse(firstBegin, secondEnd);
    }
  }
  return str;
}

} // namespace ae

TEST(rotateLeftOfString, all) {
  {
    char str[] = "abcdefg";
    EXPECT_STREQ(ae::rotateLeftOfString(str, 2), "cdefgab");
  }
  {
    char str[] = "abcdefg";
    EXPECT_STREQ(ae::rotateLeftOfString(str, 1), "bcdefga");
  }
  {
    char str[] = "abcdefg";
    EXPECT_STREQ(ae::rotateLeftOfString(str, 6), "gabcdef");
  }
  {
    EXPECT_STREQ(ae::rotateLeftOfString(nullptr, 6), nullptr);
  }
  {
    char str[] = "abcdefg";
    EXPECT_STREQ(ae::rotateLeftOfString(str, 0), "abcdefg");
  }
  {
    char str[] = "abcdefg";
    EXPECT_STREQ(ae::rotateLeftOfString(str, 7), "abcdefg");
  }
}
