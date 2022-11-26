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
UID passenger::get_uid () const
{
  return uid;
}
void passenger::set_uid (UID u)
{
  passenger::uid = u;
}
UID passenger::get_card () const
{
  return card;
}
void passenger::set_card (UID c)
{
  passenger::card = c;
}
