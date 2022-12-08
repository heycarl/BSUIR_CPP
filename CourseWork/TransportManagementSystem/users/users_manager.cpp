//
// Created by Alexandr on 11/26/2022.
//

#include <algorithm>
#include "users_manager.h"
user_passenger& users_manager::sign_up_passenger()
{
	std::string login;
	std::string password;
	ask_credentials("Enter new passenger's username and password:\n", login, password);
	l_passengers.push_front(user_passenger());
	return l_passengers.front();
}

user_admin& users_manager::sign_up_admin()
{
	std::string login;
	std::string password;
	ask_credentials("Enter new admins's username and password:\n", login, password);
	l_admins.push_front(user_admin(login, password));
	return l_admins.front();
}
user_passenger& users_manager::sign_in_passenger()
{
	std::string login;
	std::string password;
	ask_credentials("Enter passengers's username and password:\n", login, password);

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
	std::string password;
	ask_credentials("Enter admin's username and password:\n", login, password);

	for (auto& u_a : l_admins) {
		if (u_a.validate_credentials(login, password))
			return u_a;
	}
	throw std::runtime_error("No such admin found");
}
void users_manager::save_db(const std::string& db)
{
	std::ofstream ofs(db);
	if (!ofs.is_open())
		return;
	boost::archive::text_oarchive oa(ofs);
	oa & l_admins;
	ofs.close();
}
void users_manager::load_db(const std::string& db)
{
	std::ifstream ifs(db);
	if (!ifs.is_open())
		return;
	boost::archive::text_iarchive ia(ifs);
	ia & l_admins;
	ifs.close();
}
void users_manager::ask_credentials(std::string req, std::string& resp_1, std::string& resp_2)
{
	std::cout << req;
	std::cin >> resp_1;
	std::cin >> resp_2;
}
