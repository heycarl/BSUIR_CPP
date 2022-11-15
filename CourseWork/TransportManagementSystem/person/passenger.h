//
// Created by Alexandr on 11/6/2022.
//

#ifndef _PASSENGER_H_
#define _PASSENGER_H_

#include <iostream>

#include "./person.h"
#include "../travel_cards/travelCard.h"

class passenger : public person {
 private:
  travelCard card;
 public:
};

#endif //_PASSENGER_H_
