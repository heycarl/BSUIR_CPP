//
// Created by Alexandr on 11/26/2022.
//

#ifndef _USER_H_
#define _USER_H_

#include <iostream>

class user {
 private:
  std::string login;
  std::string password;
 public:
  user (std::string login, std::string password);
  user ();
  bool validate_credentials(std::string, std::string);
};

#endif //_USER_H_
