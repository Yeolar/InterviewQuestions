/*
 * Copyright (C) 2017, Yeolar
 *
 * 求base的exponent次方
 */

#include <float.h>
#include <stdexcept>
#include <gtest/gtest.h>

#define POWER_V1 0

namespace ae {

#if POWER_V1

double powerWithUnsignedExponent(double base, unsigned int exponent) {
  double result = 1.0;
  for (auto i = 0u; i < exponent; i++) {
    result *= base;
  }
  return result;
}

#else

double powerWithUnsignedExponent(double base, unsigned int exponent) {
  if (exponent == 0) return 1;
  if (exponent == 1) return base;

  double result = powerWithUnsignedExponent(base, exponent >> 1);
  result *= result;
  if ((exponent & 0x1) == 1) {
    result *= base;
  }
  return result;
}

#endif

double power(double base, int exponent) {
  if (base > -FLT_MIN && base < FLT_MIN && exponent < 0)
    throw std::invalid_argument("Invalid arguments");

  int absExponent = exponent > 0 ? exponent : -exponent;
  double result = powerWithUnsignedExponent(base, absExponent);
  if (exponent < 0) {
    result = 1.0 / result;
  }
  return result;
}

} // namespace ae

TEST(power, all) {
  EXPECT_DOUBLE_EQ(ae::power(2, 3), 8);
  EXPECT_DOUBLE_EQ(ae::power(-2, 3), -8);
  EXPECT_DOUBLE_EQ(ae::power(2, -3), 0.125);
  EXPECT_DOUBLE_EQ(ae::power(2, 0), 1);
  EXPECT_DOUBLE_EQ(ae::power(0, 0), 1);
  EXPECT_DOUBLE_EQ(ae::power(0, 4), 0);
  EXPECT_THROW(ae::power(0, -4), std::invalid_argument);
}
