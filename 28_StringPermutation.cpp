/*
 * Copyright (C) 2017, Yeolar
 */

#include <gtest/gtest.h>

namespace ae {

void permutation(char* str, char* begin, std::stringstream& out) {
  if (*begin == '\0') {
    out << str << " ";
  } else {
    for (char* p = begin; *p != '\0'; p++) {
      std::swap(*begin, *p);
      permutation(str, begin + 1, out);
      std::swap(*begin, *p);
    }
  }
}

void permutation(char* str, std::stringstream& out) {
  if (str == nullptr) return;
  permutation(str, str, out);
}

} // namespace ae

TEST(permutation, all) {
  std::stringstream out;
  {
    char str[] = "";
    ae::permutation(str, out);
    EXPECT_STREQ(out.str().c_str(), " ");
    out.str("");
  }
  {
    char str[] = "a";
    ae::permutation(str, out);
    EXPECT_STREQ(out.str().c_str(), "a ");
    out.str("");
  }
  {
    char str[] = "ab";
    ae::permutation(str, out);
    EXPECT_STREQ(out.str().c_str(), "ab ba ");
    out.str("");
  }
  {
    char str[] = "abc";
    ae::permutation(str, out);
    EXPECT_STREQ(out.str().c_str(), "abc acb bac bca cba cab ");
    out.str("");
  }
}
