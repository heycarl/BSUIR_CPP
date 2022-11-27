//
// Created by Alexandr on 11/6/2022.
//

#include <exception>

#include "travel_cards_manager.h"

bool travel_cards_manager::validator (travel_card c)
{
  if (c.get_remaining_trips () > 0)
	{
	  c.decrement_trips ();
	  return true;
	}
  return false;
}
travel_card& travel_cards_manager::find_travel_card (UID uid_to_find)
{
  for (auto& c : travel_cards)
	{
	  if (c.get_uid () == uid_to_find)
		return c;
	}
  throw std::runtime_error ("No such card found");
}
void travel_cards_manager::create_if_not_exists (UID u)
{
  try
	{
	  find_travel_card (u);
	}
  catch (std::exception)
	{
	  travel_cards.push_front (travel_card (u));
	}
}
