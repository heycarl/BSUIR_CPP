#include <iostream>

#include "String/String.h"

int main() {
  auto l_string1 = String();
  auto l_string2 = String((char *) "Hello World");
  auto l_string3 = String((char *) "Huinia");

  std::cout << l_string2.GetString() << std::endl;
  l_string2 = (char *) "Huinia";
  std::cout << l_string2.GetString() << std::endl;
  std::cout << l_string2[2] << std::endl;
  std::cout << l_string2(0, 6) << std::endl;
  l_string1 = (char *) " Labi";
  std::cout << (l_string2 + l_string1).GetString() << std::endl;
//  l_string2 += l_string3;
  std::cout << (l_string2 == l_string1) << std::endl;
  std::cout << (l_string2 != l_string1) << std::endl;
}
