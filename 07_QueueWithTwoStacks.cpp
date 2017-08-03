/*
 * Copyright (C) 2017, Yeolar
 *
 * 使用两个栈实现队列
 */

#include <stack>
#include <stdexcept>
#include <gtest/gtest.h>

namespace ae {

template <class T>
class Queue {
public:
  Queue() {}
  ~Queue() {}

  void push(const T& value) {
    stack1_.push(value);
  }

  T pop() {
    if (stack2_.empty()) {
      while (!stack1_.empty()) {
        stack2_.push(stack1_.top());
        stack1_.pop();
      }
    }
    if (stack2_.empty()) {
      throw std::out_of_range("Empty queue");
    }
    T value = stack2_.top();
    stack2_.pop();
    return value;
  }

private:
  std::stack<T> stack1_;
  std::stack<T> stack2_;
};

} // namespace ae

TEST(Queue, all) {
  ae::Queue<int> queue;
  queue.push(1);
  queue.push(2);
  queue.push(3);
  EXPECT_EQ(queue.pop(), 1);
  EXPECT_EQ(queue.pop(), 2);
  queue.push(4);
  EXPECT_EQ(queue.pop(), 3);
  queue.push(5);
  EXPECT_EQ(queue.pop(), 4);
  EXPECT_EQ(queue.pop(), 5);
}
