//
// Created by Alexandr on 11/6/2022.
//

#ifndef _PERSON_H_
#define _PERSON_H_

#include <iostream>

#include "date.h"

class person {
 private:
  uint8_t uid;
  std::string first_name;
  std::string middle_name;
  std::string last_name;
  date date_of_birth;
 public:
    virtual std::string serialize();
	std::string get_first_last_name();
};

#endif //_PERSON_H_
