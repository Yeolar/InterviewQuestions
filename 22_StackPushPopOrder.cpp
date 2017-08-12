/*
 * Copyright (C) 2017, Yeolar
 */

#include <stack>
#include <vector>
#include <gtest/gtest.h>

namespace ae {

template <class T>
bool isPopOrder(const std::vector<T>& pushed, const std::vector<T>& poped) {
  if (pushed.empty() || poped.empty()) return false;
  std::stack<T> stack;
  auto pushIt = pushed.begin();
  auto popIt = poped.begin();
  while (popIt != poped.end()) {
    while (stack.empty() || stack.top() != *popIt) {
      if (pushIt == pushed.end()) break;
      stack.push(*pushIt);
      pushIt++;
    }
    if (stack.top() != *popIt) break;
    stack.pop();
    popIt++;
  }
  return (stack.empty() && popIt == poped.end());
}

} // namespace ae

TEST(isPopOrder, all) {
  {
    std::vector<int> pushed = { 1, 2, 3, 4, 5 };
    std::vector<int> poped = { 4, 5, 3, 2, 1 };
    EXPECT_TRUE(ae::isPopOrder(pushed, poped));
  }
  {
    std::vector<int> pushed = { 1, 2, 3, 4, 5 };
    std::vector<int> poped = { 3, 5, 4, 2, 1 };
    EXPECT_TRUE(ae::isPopOrder(pushed, poped));
  }
  {
    std::vector<int> pushed = { 1, 2, 3, 4, 5 };
    std::vector<int> poped = { 4, 3, 5, 1, 2 };
    EXPECT_FALSE(ae::isPopOrder(pushed, poped));
  }
  {
    std::vector<int> pushed = { 1, 2, 3, 4, 5 };
    std::vector<int> poped = { 3, 5, 4, 1, 2 };
    EXPECT_FALSE(ae::isPopOrder(pushed, poped));
  }
  {
    std::vector<int> pushed = { 1 };
    std::vector<int> poped = { 2 };
    EXPECT_FALSE(ae::isPopOrder(pushed, poped));
  }
  {
    std::vector<int> pushed = { 1 };
    std::vector<int> poped = { 1 };
    EXPECT_TRUE(ae::isPopOrder(pushed, poped));
  }
  {
    std::vector<int> pushed = {};
    std::vector<int> poped = {};
    EXPECT_FALSE(ae::isPopOrder(pushed, poped));
  }
}
