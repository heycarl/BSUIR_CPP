//
// Created by Alexandr on 11/6/2022.
//

#include <exception>

#include "travel_cards_manager.h"

bool travelCardsManager::validator (travel_card c)
{
  if (c.get_remaining_trips () > 0)
	{
	  c.decrement_trips ();
	  return true;
	}
  return false;
}
travelCardsManager::user& travelCardsManager::signup_user ()
{

  std::string uname;
  std::string passwd;

  std::cout << "Enter username: ";
  std::cin >> uname;

  std::cout << "Enter password: ";
  std::cin >> passwd;

  user new_user = {
	  passenger (),
	  uname,
	  passwd
  };
  users.push_front (new_user);
  return new_user;
}
travelCardsManager::user& travelCardsManager::find_user (std::string uname)
{
  for (auto& u : users)
	{
	  if (u.login == uname)
		return u;
	}
  throw std::exception ();
}
travelCardsManager::user& travelCardsManager::signin_user ()
{
  std::string uname;

  std::cout << "Enter username: ";
  std::cin >> uname;

  try
	{
	  user& u = find_user (uname);
	  std::string passwd;
	  while (passwd != u.password_hash)
		{
		  std::cout << "Enter password: ";
		  std::cin >> passwd;
		}
	  return u;
	}
  catch (std::exception)
	{
	  throw std::exception ();
	}
}
