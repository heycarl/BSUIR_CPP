//
// Created by Alexandr on 11/6/2022.
//

#ifndef _PASSENGER_H_
#define _PASSENGER_H_

#include <iostream>

#include "person.h"
#include "uid_generator.h"

class passenger : public person {
 public:
  UID get_uid () const;
  void set_uid (UID u);
  UID get_card () const;
  void set_card (UID c);
 private:
  UID uid;
  UID card;
 public:
  passenger();
  std::string serialize() override;
};

#endif //_PASSENGER_H_
