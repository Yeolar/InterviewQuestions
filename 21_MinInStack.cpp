/*
 * Copyright (C) 2017, Yeolar
 */

#include <stack>
#include <stddef.h>
#include <gtest/gtest.h>

namespace ae {

template <class T>
class Stack {
public:
  Stack() {}
  virtual ~Stack() {}

  T& top() {
    return data_.top();
  }
  const T& top() const {
    return data_.top();
  }

  T& min() {
    return min_.top();
  }
  const T& min() const {
    return min_.top();
  }

  void push(const T& value) {
    data_.push(value);
    if (min_.empty() || min_.top() > value) {
      min_.push(value);
    } else {
      min_.push(min_.top());
    }
  }
  void pop() {
    data_.pop();
    min_.pop();
  }

  bool empty() const {
    return data_.empty();
  }
  size_t size() const {
    return data_.size();
  }

private:
  std::stack<T> data_;
  std::stack<T> min_;
};

} // namespace ae

TEST(Stack, all) {
  ae::Stack<int> stack;
  stack.push(3);
  EXPECT_EQ(stack.min(), 3);
  stack.push(4);
  EXPECT_EQ(stack.min(), 3);
  stack.push(2);
  EXPECT_EQ(stack.min(), 2);
  stack.push(3);
  EXPECT_EQ(stack.min(), 2);
  stack.pop();
  EXPECT_EQ(stack.min(), 2);
  stack.pop();
  EXPECT_EQ(stack.min(), 3);
  stack.pop();
  EXPECT_EQ(stack.min(), 3);
  stack.push(0);
  EXPECT_EQ(stack.min(), 0);
}
