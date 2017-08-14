/*
 * Copyright (C) 2017, Yeolar
 */

#include <gtest/gtest.h>

namespace ae {

char findFirstNotRepeatingChar(const char* str) {
  if (str == nullptr) return '\0';
  unsigned int hashTable[256];
  for (int i = 0; i < 256; i++) {
    hashTable[i] = 0;
  }
  const char* p = str;
  while (*p != '\0') {
    hashTable[(int)*p++]++;
  }
  p = str;
  while (*p != '\0') {
    if (hashTable[(int)*p] == 1) return *p;
    p++;
  }
  return '\0';
}

} // namespace ae

TEST(findFirstNotRepeatingChar, all) {
  EXPECT_EQ(ae::findFirstNotRepeatingChar("google"), 'l');
  EXPECT_EQ(ae::findFirstNotRepeatingChar("aabccdbd"), '\0');
  EXPECT_EQ(ae::findFirstNotRepeatingChar("abcdefg"), 'a');
  EXPECT_EQ(ae::findFirstNotRepeatingChar(nullptr), '\0');
}
