//
// Created by Alexandr on 11/6/2022.
//

#ifndef TRAVELCARDSMANAGER_H_
#define TRAVELCARDSMANAGER_H_

#include <iostream>
#include <list>

#include "travel_card.h"
#include "passenger.h"

class travel_cards_manager {
 private:
  std::list<travel_card> travel_cards;
 private:
  travel_card& find_travel_card(UID);
 public:
  void create_if_not_exists(UID);
  static bool validator (travel_card);
};

#endif //TRAVELCARDSMANAGER_H_
