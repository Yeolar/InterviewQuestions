/*
 * Copyright (C) 2017, Yeolar
 */

#include <gtest/gtest.h>

namespace ae {

bool findInMatrix(int* matrix, int rows, int columns, int number) {
  if (matrix != nullptr && rows > 0 && columns > 0) {
    int row = 0;
    int col = columns - 1;
    while (row < rows && col >= 0) {
      int value = matrix[row * columns + col];
      if (value == number) {
        return true;
      } else if (value > number) {
        col--;
      } else {
        row++;
      }
    }
  }
  return false;
}

} // namespace ae

TEST(findInMatrix, all) {
  int matrix[][4] = {
    {1, 2, 8, 9},
    {2, 4, 9, 12},
    {4, 7, 10, 13},
    {6, 8, 11, 15}
  };
  EXPECT_TRUE(ae::findInMatrix((int*)matrix, 4, 4, 7));
  EXPECT_FALSE(ae::findInMatrix((int*)matrix, 4, 4, 5));
  EXPECT_TRUE(ae::findInMatrix((int*)matrix, 4, 4, 1));
  EXPECT_TRUE(ae::findInMatrix((int*)matrix, 4, 4, 15));
  EXPECT_FALSE(ae::findInMatrix((int*)matrix, 4, 4, 0));
  EXPECT_FALSE(ae::findInMatrix((int*)matrix, 4, 4, 16));
  EXPECT_FALSE(ae::findInMatrix(nullptr, 0, 0, 16));
}
