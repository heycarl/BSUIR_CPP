//
// Created by Alexandr on 10/17/2022.
//

#ifndef LABS_LAB_04_MYQUEUE_MYQUEUE_H_
#define LABS_LAB_04_MYQUEUE_MYQUEUE_H_

#include "../MyList/MyList.h"

template<typename T>
class MyQueue {
 private:
  MyList<T> m_data;
 public:
  MyQueue() = default;
  ~MyQueue() = default;
  void push(T arg_element);
  void pop();
  T &back();
  T &front();
  std::size_t size();
  bool empty();
};
template<typename T>
void MyQueue<T>::push(T arg_element) {
  m_data.push_back(arg_element);
}
template<typename T>
void MyQueue<T>::pop() {
  return m_data.pop_front();
}
template<typename T>
std::size_t MyQueue<T>::size() {
  return m_data.size();
}
template<typename T>
bool MyQueue<T>::empty() {
  return m_data.empty();
}
template<typename T>
T &MyQueue<T>::back() {
  return m_data.back();
}
template<typename T>
T &MyQueue<T>::front() {
  return m_data.front();
}

#endif //LABS_LAB_04_MYQUEUE_MYQUEUE_H_
