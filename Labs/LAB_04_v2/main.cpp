#include <iostream>
#include "MyQueue/MyQueue.h"

int main() {
  MyQueue<std::string> q;

  q.push("Sasha");
  q.push("Petya");
  q.push("Andrew");
  q.print();


  std::cout << q.size() << std::endl;

  q.pop();
  std::cout << q.back() << std::endl;
  std::cout << q.front() << std::endl;

  q.push("Alligator");
  q.print();

}