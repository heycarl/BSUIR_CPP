//
// Created by Alexandr on 11/6/2022.
//

#ifndef TRAVEL_CARD_H_
#define TRAVEL_CARD_H_

#include <iostream>

#include "uid_generator.h"

class travel_card {
 private:
  UID uid;
  uint8_t remaining_trips;
 public:
  travel_card(UID holder_uid);
  uint8_t get_remaining_trips () const;
  void set_remaining_trips (uint8_t remaining_trips);
  void decrement_trips();
 public:

};

#endif //TRAVEL_CARD_H_
