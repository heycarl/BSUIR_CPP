#include <iostream>
#include <queue>
#include "MyQueue/MyQueue.h"

int main() {
//  std::queue<int> qq;
//  qq.push_back(2);
//  qq.push_back(4);
//  std::cout << qq.front() << std::endl;
//  std::cout << "m_size " << qq.m_size() << std::endl;
//
//  qq.pop();
//  qq.pop();
//  std::cout << "size2 " << qq.m_size() << std::endl;
//  std::cout << qq.empty() << std::endl;
//  try {
//    qq.pop();
//  } catch (...) {
//    std::cout << "cpp is strage" << std::endl;
//  }
//  std::cout << qq.empty() << std::endl;
//  std::cout << qq.front() << std::endl;

//  std::cout << qq.m_size() << std::endl;
  MyQueue<int> q;
  q.push(1);
  q.push(2);
  q.push(3);

  std::cout << q.back() << std::endl;
  q.pop();
  q.pop();
  std::cout << q.size() << std::endl;
  std::cout << q.empty() << std::endl;
  q.pop();
  std::cout << q.empty() << std::endl;
}