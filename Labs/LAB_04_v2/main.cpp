#include <iostream>
#include <queue>
#include "MyQueue/MyQueue.h"
#include "MyList/MyList.h"
#include <list>

#include <iostream>

int main() {
//  std::queue<int> q;
  MyQueue<int> q;

  q.push(1);
  q.push(2);
  q.push(3);

  std::cout << q.size() << std::endl;

  q.pop();
  std::cout << q.back() << std::endl;
  std::cout << q.front() << std::endl;

}