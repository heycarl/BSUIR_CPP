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
void user::ask_credentials(std::string req, std::string& resp_1, std::string& resp_2)
{
	std::cout << req;
	std::cin >> resp_1;
	std::cin >> resp_2;
}

