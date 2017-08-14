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

char* reverseSentence(char* str) {
  if (str == nullptr) return nullptr;
  char* begin = str;
  char* end = str + strlen(str) - 1;
  reverse(begin, end);
  end = str;
  while (*begin != '\0') {
    if (*begin == ' ') {
      begin++;
      end++;
    } else if (*end == ' ' || *end == '\0') {
      end--;
      reverse(begin, end);
      end++;
      begin = end;
    } else {
      end++;
    }
  }
  return str;
}

} // namespace ae

TEST(reverseSentence, all) {
  {
    char str[] = "I am a student.";
    EXPECT_STREQ(ae::reverseSentence(str), "student. a am I");
  }
  {
    char str[] = "Wonderful";
    EXPECT_STREQ(ae::reverseSentence(str), "Wonderful");
  }
  {
    char str[] = "   ";
    EXPECT_STREQ(ae::reverseSentence(str), "   ");
  }
  {
    char str[] = "";
    EXPECT_STREQ(ae::reverseSentence(str), "");
  }
  {
    EXPECT_STREQ(ae::reverseSentence(nullptr), nullptr);
  }
}
