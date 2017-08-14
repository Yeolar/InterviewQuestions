/*
 * Copyright (C) 2017, Yeolar
 */

#include <gtest/gtest.h>

namespace ae {

void printContinuousSequence(int small, int big, std::stringstream& out) {
  for (int i = small; i <= big; i++) {
    out << i << " ";
  }
}

void findContinuousSequence(int sum, std::stringstream& out) {
  if (sum < 3) return;
  int small = 1;
  int big = 2;
  int mid = (sum + 1) / 2;
  int currentSum = small + big;
  while (small < mid) {
    if (currentSum == sum) {
      printContinuousSequence(small, big, out);
    }
    while (sum < currentSum && small < mid) {
      currentSum -= small;
      small++;
      if (currentSum == sum) {
        printContinuousSequence(small, big, out);
      }
    }
    big++;
    currentSum += big;
  }
}

} // namespace ae

TEST(findContinuousSequence, all) {
  std::stringstream out;
  {
    ae::findContinuousSequence(1, out);
    EXPECT_STREQ(out.str().c_str(), "");
    out.str("");
  }
  {
    ae::findContinuousSequence(3, out);
    EXPECT_STREQ(out.str().c_str(), "1 2 ");
    out.str("");
  }
  {
    ae::findContinuousSequence(4, out);
    EXPECT_STREQ(out.str().c_str(), "");
    out.str("");
  }
  {
    ae::findContinuousSequence(9, out);
    EXPECT_STREQ(out.str().c_str(), "2 3 4 4 5 ");
    out.str("");
  }
  {
    ae::findContinuousSequence(15, out);
    EXPECT_STREQ(out.str().c_str(), "1 2 3 4 5 4 5 6 7 8 ");
    out.str("");
  }
  {
    ae::findContinuousSequence(100, out);
    EXPECT_STREQ(out.str().c_str(), "9 10 11 12 13 14 15 16 18 19 20 21 22 ");
    out.str("");
  }
}
