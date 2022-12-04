//
// Created by Alexandr on 11/6/2022.
//
#include <sstream>

#include "person.h"
std::string person::serialize()
{
	std::stringstream ss;
	ss << "[Driver-" << +uid << "]" << std::endl
	   << "Name: " << first_name
	   << " " << last_name << std::endl
	   << "Date of birth: "
	   << date_of_birth.serialize() << std::endl;
	return ss.str();
}
std::string person::get_first_last_name()
{
	std::stringstream ss;
	ss << first_name << " "
	   << last_name << std::endl;
	return ss.str();
}
person::person()
{
	uid = uidGenerator::generate();
	std::cout << "Enter fisrt name: ";
	std::cin >> first_name;
	std::cout << "Enter last name: ";
	std::cin >> last_name;
	std::cout << "Enter date of birth in \"dd.mm.yy\" notation: ";
	std::string date_string;
	std::cin >> date_string;
	date_of_birth.set_date(date_string);

}
UID person::get_uid() const
{
	return uid;
}
