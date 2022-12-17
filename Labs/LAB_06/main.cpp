#include <iostream>
#include "MyList.h"
#include "Monoblock.h"

int main() {
  MyList<Monoblock> list;
  list.push_front(Monoblock(12));
  list.push_front(Monoblock(8));
  list.push_front(Monoblock(40));
  for (const auto& m: list) {
    std::cout << m.GetScreenSize() << std::endl;
  }

  const auto& a = list.front();
  std::cout << a.GetScreenSize();
}