/*
 * Copyright (C) 2017, Yeolar
 */

#include <vector>
#include <gtest/gtest.h>

namespace ae {

int partition(std::vector<int>& data, int begin, int end) {
  if (data.empty() || begin < 0 || end >= (int)data.size()) {
    throw std::invalid_argument("Invalid args");
  }
  int i = (begin + end) / 2;
  std::swap(data[i], data[end]);
  int small = begin - 1;
  for (i = begin; i < end; i++) {
    if (data[i] < data[end]) {
      small++;
      if (small != i) {
        std::swap(data[i], data[small]);
      }
    }
  }
  small++;
  std::swap(data[small], data[end]);
  return small;
}

void getKLeastNumbers_v1(std::vector<int>& numbers, int k, std::vector<int>& out) {
  if (numbers.empty() || k <= 0 || k > (int)numbers.size()) return;
  int begin = 0;
  int end = numbers.size() - 1;
  int i = partition(numbers, begin, end);
  while (i != k - 1) {
    if (i > k - 1) {
      end = i - 1;
      i = partition(numbers, begin, end);
    } else {
      begin = i + 1;
      i = partition(numbers, begin, end);
    }
  }
  for (int j = 0; j < k; j++) {
    out.push_back(numbers[j]);
  }
}

void getKLeastNumbers_v2(const std::vector<int>& numbers, int k,
                         std::multiset<int, std::greater<int>>& out) {
  if (numbers.empty() || k <= 0 || k > (int)numbers.size()) return;
  for (size_t i = 0; i < numbers.size(); i++) {
    if ((int)out.size() < k) {
      out.insert(numbers[i]);
    } else {
      auto it = out.begin();
      if (numbers[i] < *it) {
        out.erase(it);
        out.insert(numbers[i]);
      }
    }
  }
}

} // namespace ae

TEST(getKLeastNumbers_v1, all) {
  {
    std::vector<int> numbers = { 4, 5, 1, 6, 2, 7, 3, 8 };
    std::vector<int> out1;
    std::multiset<int, std::greater<int>> out2;
    ae::getKLeastNumbers_v2(numbers, 4, out2);
    ae::getKLeastNumbers_v1(numbers, 4, out1);
    EXPECT_EQ(out1.size(), 4);
    EXPECT_EQ(out2.size(), 4);
    for (auto& i : out1) {
      printf("%d ", i);
    }
    printf("\n");
    for (auto& i : out2) {
      printf("%d ", i);
    }
    printf("\n");
  }
  {
    std::vector<int> numbers = { 4, 5, 1, 6, 2, 7, 3, 8 };
    std::vector<int> out1;
    std::multiset<int, std::greater<int>> out2;
    ae::getKLeastNumbers_v2(numbers, 8, out2);
    ae::getKLeastNumbers_v1(numbers, 8, out1);
    EXPECT_EQ(out1.size(), 8);
    EXPECT_EQ(out2.size(), 8);
    for (auto& i : out1) {
      printf("%d ", i);
    }
    printf("\n");
    for (auto& i : out2) {
      printf("%d ", i);
    }
    printf("\n");
  }
  {
    std::vector<int> numbers = { 4, 5, 1, 6, 2, 7, 3, 8 };
    std::vector<int> out1;
    std::multiset<int, std::greater<int>> out2;
    ae::getKLeastNumbers_v2(numbers, 1, out2);
    ae::getKLeastNumbers_v1(numbers, 1, out1);
    EXPECT_EQ(out1.size(), 1);
    EXPECT_EQ(out2.size(), 1);
    for (auto& i : out1) {
      printf("%d ", i);
    }
    printf("\n");
    for (auto& i : out2) {
      printf("%d ", i);
    }
    printf("\n");
  }
  {
    std::vector<int> numbers = { 4, 5, 1, 6, 2, 7, 3, 8 };
    std::vector<int> out1;
    std::multiset<int, std::greater<int>> out2;
    ae::getKLeastNumbers_v2(numbers, 0, out2);
    ae::getKLeastNumbers_v1(numbers, 0, out1);
    EXPECT_EQ(out1.size(), 0);
    EXPECT_EQ(out2.size(), 0);
  }
  {
    std::vector<int> numbers = { 4, 5, 1, 6, 2, 7, 2, 8 };
    std::vector<int> out1;
    std::multiset<int, std::greater<int>> out2;
    ae::getKLeastNumbers_v2(numbers, 2, out2);
    ae::getKLeastNumbers_v1(numbers, 2, out1);
    EXPECT_EQ(out1.size(), 2);
    EXPECT_EQ(out2.size(), 2);
    for (auto& i : out1) {
      printf("%d ", i);
    }
    printf("\n");
    for (auto& i : out2) {
      printf("%d ", i);
    }
    printf("\n");
  }
}
