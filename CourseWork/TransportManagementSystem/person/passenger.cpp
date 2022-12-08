//
// Created by Alexandr on 11/6/2022.
//
#include <sstream>

#include "passenger.h"
std::string passenger::serialize_ui()
{
	std::stringstream ss;
	ss << "Passenger" << person::serialize_ui();
	return person::serialize_ui();
}
UID passenger::get_card() const
{
	return card;
}
passenger::passenger(std::string f_name, std::string l_name, std::string dob)
		:person(f_name, l_name, dob)
{
	core::tcm.create_if_not_exists(get_uid());
	card = get_uid();
}
//user_admin::user_admin(const std::string& login, const std::string& password)
//		:user(login, password) { }
//passenger::passenger() {
//	core::tcm.create_if_not_exists(get_uid());
//	card = get_uid();
//}
