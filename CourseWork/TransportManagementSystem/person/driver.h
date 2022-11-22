//
// Created by Alexandr on 11/6/2022.
//

#ifndef DRIVER_H_
#define DRIVER_H_

#include <iostream>

#include "person.h"
#include "date.h"
#include "vehicle.h"

class driver : public person {
 private:
  date license_expiration;
  vehicle::vehicle_type license_type = vehicle::vehicle_type::bus; // default license
 private:
  std::string serialize_license();
 public:
  std::string serialize() {
    return person::serialize() += serialize_license();
  };
};

#endif //DRIVER_H_
