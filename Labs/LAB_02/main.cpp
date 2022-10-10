#include <iostream>

#include "String/String.h"

int main() {
  auto l_string1 = String();
  l_string1 = (char *) "String 1";
  auto l_string2 = String((char *) "String 2");
  auto l_string3 = String((char *) "String 3");

  std::cout << "GetString: " << l_string2.GetString() << std::endl;
  l_string2 = (char *) "New String 2";
  std::cout << "Changed string: " << l_string2.GetString() << std::endl;

  std::cout << "Get char on index: " << l_string2[2] << std::endl;

  std::cout << "Get string slice: " << l_string2(0, 6) << std::endl;

  std::cout << "Sum of strings: " << (l_string2 + l_string1).GetString() << std::endl;

  l_string2 += l_string3;
  std::cout << "Sum-equals:  " << l_string2.GetString() << std::endl;

  l_string1.Append(l_string1);
  std::cout << "Append: " << l_string1.GetString() << std::endl;

  std::cout << "Equals: " << (l_string2 == l_string1) << std::endl;
  std::cout << "Not equals: " << (l_string2 != l_string1) << std::endl;
  return 0;
}
