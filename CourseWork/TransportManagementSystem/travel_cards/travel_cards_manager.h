//
// Created by Alexandr on 11/6/2022.
//

#ifndef TRAVELCARDSMANAGER_H_
#define TRAVELCARDSMANAGER_H_

#include <iostream>
#include <list>

#include "travel_card.h"
#include "passenger.h"

class travelCardsManager {
 private:
  std::list<travel_card> travel_cards;
  struct user {
	  passenger passenger;
	  std::string login;
	  std::string password_hash;
  };
  std::list<user> users;
 private:
  user& find_user(std::string uname);
 public:
  static bool validator (travel_card);
  user& signup_user();
  user& signin_user();
};

#endif //TRAVELCARDSMANAGER_H_
