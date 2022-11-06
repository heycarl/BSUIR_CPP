//
// Created by Alexandr on 11/6/2022.
//

#ifndef _DATE_H_
#define _DATE_H_

#include <iostream>

class date {
 public:
  uint8_t year = 0;
  uint8_t month= 0;
  uint8_t day = 0;

  std::string serialize();
  std::string serialize(std::string text);

};

#endif //_DATE_H_
