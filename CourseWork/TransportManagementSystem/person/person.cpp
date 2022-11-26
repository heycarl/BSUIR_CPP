//
// Created by Alexandr on 11/6/2022.
//
#include <sstream>

#include "person.h"
std::string person::serialize ()
{
  std::stringstream ss;
  ss << "Name: " << first_name
	 << " " << middle_name
	 << " " << last_name << std::endl
	 << "Date of birth: "
	 << date_of_birth.serialize () << std::endl;
  return ss.str ();
}
std::string person::get_first_last_name ()
{
  std::stringstream ss;
  ss << first_name << " "
	 << last_name << " "
	 << middle_name << std::endl;
  return ss.str ();
}
