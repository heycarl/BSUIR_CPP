//
// Created by Alexandr on 11/6/2022.
//

#ifndef _PERSON_H_
#define _PERSON_H_

#include <iostream>

#include "../date/date.h"

class person {
 private:
  uint8_t uid;
  std::string first_name;
  std::string middle_name;
  std::string last_name;
  date date_of_birth;
 public:
  std::string serialize();
};

#endif //_PERSON_H_
