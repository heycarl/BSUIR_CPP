//
// Created by Alexandr on 11/6/2022.
//

#ifndef _DRIVER_H_
#define _DRIVER_H_

#include <iostream>

#include "./person.h"
#include "../date/date.h"

class driver : public person {
 private:
  date license_expiration;
 public:
  std::string serialize() {
    return person::serialize() += license_expiration.serialize("Driver license:");
  };
};

#endif //_DRIVER_H_
