//
// Created by Alexandr on 11/6/2022.
//
#include <sstream>

#include "passenger.h"
std::string passenger::serialize ()
{
	std::stringstream ss;
	ss << "Passenger" << person::serialize();
  return person::serialize ();
}
UID passenger::get_card () const
{
  return card;
}
passenger::passenger() {
	core::tcm.create_if_not_exists(get_uid());
	card = get_uid();
}
