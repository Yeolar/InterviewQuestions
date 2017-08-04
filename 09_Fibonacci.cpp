/*
 * Copyright (C) 2017, Yeolar
 *
 * Fibonacci
 */

#include <stdexcept>
#include <utility>
#include <vector>
#include <gtest/gtest.h>

namespace ae {

unsigned long long fibonacci_v1(unsigned int n) {
  if (n == 0) return 0;
  if (n == 1) return 1;
  return fibonacci_v1(n - 1) + fibonacci_v1(n - 2);
}

unsigned long long fibonacci_v2(unsigned int n) {
  if (n == 0) return 0;
  if (n == 1) return 1;
  unsigned long long k = 0;
  unsigned long long k_1 = 1;
  unsigned long long k_2 = 0;
  for (unsigned int i = 2; i <= n; i++) {
    k = k_1 + k_2;
    k_2 = k_1;
    k_1 = k;
  }
  return k;
}

struct Matrix {
  unsigned long long v00{0};
  unsigned long long v01{0};
  unsigned long long v10{0};
  unsigned long long v11{0};
};

Matrix operator* (const Matrix& matrix1, const Matrix& matrix2) {
  Matrix matrix;
  matrix.v00 = matrix1.v00 * matrix2.v00 + matrix1.v01 * matrix2.v10;
  matrix.v01 = matrix1.v00 * matrix2.v01 + matrix1.v01 * matrix2.v11;
  matrix.v10 = matrix1.v10 * matrix2.v00 + matrix1.v11 * matrix2.v10;
  matrix.v11 = matrix1.v10 * matrix2.v01 + matrix1.v11 * matrix2.v11;
  return matrix;
}

Matrix power(const Matrix& matrix, unsigned int n) {
  if (n == 0) {
    throw std::invalid_argument("Power of 0");
  }
  if (n == 1) return matrix;
  Matrix result;
  if (n % 2 == 0) {
    result = power(matrix, n / 2);
    return result * result;
  } else {
    result = power(matrix, (n - 1) / 2);
    return result * result * matrix;
  }
}

unsigned long long fibonacci_v3(unsigned int n) {
  if (n == 0) return 0;
  if (n == 1) return 1;
  Matrix matrix;
  matrix.v00 = 1;
  matrix.v01 = 1;
  matrix.v10 = 1;
  matrix.v11 = 0;
  return power(matrix, n - 1).v00;
}

} // namespace ae

TEST(fibonacci, all) {
  std::vector<std::pair<unsigned int, unsigned long long>> array = {
    {0, 0}, {1, 1}, {2, 1}, {3, 2}, {4, 3}, {5, 5}, {6, 8}, {7, 13},
    {8, 21}, {9, 34}, {40, 102334155},
  };
  for (auto it = array.begin(); it != array.end(); it++) {
    EXPECT_EQ(ae::fibonacci_v1(it->first), it->second);
    EXPECT_EQ(ae::fibonacci_v2(it->first), it->second);
    EXPECT_EQ(ae::fibonacci_v3(it->first), it->second);
  }
}
