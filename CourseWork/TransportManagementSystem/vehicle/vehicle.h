//
// Created by Alexandr on 11/6/2022.
//

#ifndef TRANSPORTMANAGEMENTSYSTEM_VEHICLE_H_
#define TRANSPORTMANAGEMENTSYSTEM_VEHICLE_H_

#include <iostream>

class vehicle {
 public:
  enum vehicle_type {
    bus,
    e_bus,
    tram
  };
 private:
  std::string uid;
  vehicle_type type;
 public:
  bool validate_card();
};

#endif //TRANSPORTMANAGEMENTSYSTEM_VEHICLE_H_
