//
// Created by Alexandr on 11/6/2022.
//

#ifndef ROUTE_H_
#define ROUTE_H_

#include <iostream>
#include <list>

#include "bus_stop.h"
#include "driver.h"

class route {
 private:
  struct stop {
    bus_stop bus_stop;
    time_t arrival_time = 0;
    bool need_to_stop = false;
  };
  std::list<stop> route;
  driver route_driver;
 public:
  const driver &get_route_driver () const;
  void set_route_driver (const driver &route_driver);
 public:
  std::string serialize_route();
  void delete_stop(int id);
  void delete_stop(std::string name);
  void delete_stop();
  void add_stop(int id);
  void add_stop(std::string name);
  void add_stop();

  std::string view_driver();
};

#endif //ROUTE_H_
