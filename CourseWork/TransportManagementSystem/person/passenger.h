//
// Created by Alexandr on 11/6/2022.
//

#ifndef _PASSENGER_H_
#define _PASSENGER_H_

#include <iostream>

#include "person.h"
#include "travel_card.h"
#include "uid_generator.h"

class passenger : public person {
 private:
  UID uid;
  travel_card card;
 public:
  passenger();
  std::string serialize() override;
};

#endif //_PASSENGER_H_
