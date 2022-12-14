//
// Created by Alexandr on 11/6/2022.
//
#include <sstream>

#include "person.h"
std::string person::serialize_ui()
{
	std::stringstream ss;
	ss << "[Person-" << +uid << "]" << std::endl
	   << "Name: " << first_name
	   << " " << last_name << std::endl
	   << "Date of birth: "
	   << date_of_birth.serialize_ui() << std::endl;
	return ss.str();
}
std::string person::get_first_last_name()
{
	std::stringstream ss;
	ss << first_name << " "
	   << last_name << std::endl;
	return ss.str();
}
UID person::get_uid() const
{
	return uid;
}
person::person(std::string first_name, std::string last_name, std::string date_string)
		:first_name(first_name), last_name(last_name),
		 date_of_birth(date_string) {
	uid = uid_generator::generate();
}
void person::ask_names_dob(std::string req, std::string& f_name, std::string& last_name, std::string& dob)
{
	std::cout << req;
	std::cin >> f_name;
	std::cin >> last_name;
	std::cin >> dob;
};