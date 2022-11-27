//
// Created by Alexandr on 11/26/2022.
//

#ifndef _USER_PASSENGER_H_
#define _USER_PASSENGER_H_

#include "user.h"
#include "passenger.h"

#include "travel_cards_manager.h"
#include "route.h"

class user_passenger : public user{
 private:
  passenger me;
 public:
  using user::user;
  void buy_trips();
  void view_remaining_trips();
  void enter_bus();
  void get_arrival_time();
};

#endif //_USER_PASSENGER_H_
