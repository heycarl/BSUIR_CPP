//
// Created by Alexandr on 11/6/2022.
//

#ifndef TRANSPORTMANAGEMENTSYSTEM_TRANSPORT_TRANSPORT_H_
#define TRANSPORTMANAGEMENTSYSTEM_TRANSPORT_TRANSPORT_H_

#include <iostream>

class transport {
 public:
  enum transport_type {
    bus,
    e_bus,
    tram
  };
 private:
  std::string uid;
  transport_type type;
 public:
  bool validate_card();
};

#endif //TRANSPORTMANAGEMENTSYSTEM_TRANSPORT_TRANSPORT_H_
