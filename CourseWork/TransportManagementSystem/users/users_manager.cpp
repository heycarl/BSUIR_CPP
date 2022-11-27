//
// Created by Alexandr on 11/26/2022.
//

#include <algorithm>
#include "users_manager.h"
user_passenger& users_manager::sign_up_passenger()
{
	l_passengers.push_front(user_passenger());
	return l_passengers.front();
}

user_admin& users_manager::sign_up_admin()
{
	l_admins.push_front(user_admin());
	return l_admins.front();
}
user_passenger& users_manager::sign_in_passenger()
{
	std::string login;
	std::cout << "Enter username: ";
	std::string password;
	std::cin >> login;

	std::cout << "Enter password: ";
	std::cin >> password;
	for (auto& u_p : l_passengers) {
		if (u_p.validate_credentials(login, password))
			return u_p;
	}

	auto uu = std::find_if(l_passengers.begin(), l_passengers.end(), [&](user_passenger& p) {
	  return p.validate_credentials(login, password);
	});
	if (uu==l_passengers.end())
		throw std::runtime_error("No such passenger found");
	else {
		return *uu;
	}
}
user_admin& users_manager::sign_in_admin()
{
	std::string login;
	std::cout << "Enter username: ";
	std::string password;
	std::cin >> login;

	std::cout << "Enter password: ";
	std::cin >> password;
	for (auto& u_a : l_admins) {
		if (u_a.validate_credentials(login, password))
			return u_a;
	}
	throw std::runtime_error("No such admin found");
}
