//
// Created by Alexandr on 11/26/2022.
//

#include "user.h"
user::user (std::string login, std::string password)
	: login (std::move (login)), password (std::move (password))
{}
bool user::validate_credentials (std::string validating_login, std::string validating_password)
{
  if (login == validating_login && password == validating_password)
	return true;
  return false;
}
user::user ()
{
//  std::cout << "Enter login for new user: ";
//  std::cin >> login;
//
//  std::cout << "Enter password: ";
//  std::cin >> password;
}
