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
  void create_vehicle();
  void create_bus_stop();
  void view_bus_stops();
  void create_route();
  void route_serialize_stats();
  void route_serialize_information();
};

#endif //_USER_ADMIN_H_
