//
// Created by Alexandr on 11/26/2022.
//

#ifndef _USER_ADMIN_H_
#define _USER_ADMIN_H_

#include "user.h"

#include "core.h"

class user_admin : public user {
 public:
  using user::user;
  void create_driver();
  void view_drivers();
  void modify_driver(); // todo
  void create_vehicle();
  void view_vehicles();
  void create_bus_stop();
  void view_bus_stops();
  void modify_bus_stop();
  void create_route();
  void route_serialize_stats();
  void route_serialize_information();
};

#endif //_USER_ADMIN_H_
