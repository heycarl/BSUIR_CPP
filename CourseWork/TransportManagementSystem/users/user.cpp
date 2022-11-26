//
// Created by Alexandr on 11/26/2022.
//

#include "user.h"
user::user (const std::string& login, const std::string& password)
	: login (login), password (password)
{}
bool user::validate_credentials (std::string validating_login, std::string validating_password)
{
  if (login == validating_login && password == validating_password)
	return true;
  return false;
}
user::user ()
{
  std::cout << "Enter username: ";
  std::cin >> login;

  std::cout << "Enter password: ";
  std::cin >> password;
}
