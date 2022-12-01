//
// Created by Alexandr on 11/6/2022.
//

#ifndef ROUTE_H_
#define ROUTE_H_

#include <iostream>
#include <list>

#include "bus_stop.h"
#include "uid_generator.h"
class route {
 private:
  struct stop {
    bus_stop bus_stop;
    time_t arrival_time = 0;
    bool need_to_stop = true;
  };
  struct route_info {
	  std::string point_1_name;
	  std::string point_2_name;
  };
  std::list<stop> route;
  route_info route_info;
  UID route_driver;
 public:
  std::string serialize_route();
  void delete_stop(uint8_t id);
  void add_stop();

  std::string view_driver();
};

#endif //ROUTE_H_
