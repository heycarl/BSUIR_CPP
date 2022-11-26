//
// Created by Alexandr on 11/6/2022.
//
#include <sstream>

#include "passenger.h"
passenger::passenger ()
	: uid (uidGenerator::generate ()), card (uid)
{}
std::string passenger::serialize ()
{
	std::stringstream ss;
	ss << "Passenger" << person::serialize();
  return person::serialize ();
}
