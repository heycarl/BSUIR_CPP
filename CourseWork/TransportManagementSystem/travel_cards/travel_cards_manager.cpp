//
// Created by Alexandr on 11/6/2022.
//

#include <fstream>

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
void travel_cards_manager::save_db(const std::string& db)
{
	std::ofstream ofs(db);
	if (!ofs.is_open())
		return ;
	boost::archive::text_oarchive oa(ofs);
	oa & travel_cards;
	ofs.close();
}
void travel_cards_manager::load_db(const std::string& db)
{
	std::ifstream ifs(db);
	if (!ifs.is_open())
		return;
	boost::archive::text_iarchive ia(ifs);
	ia & travel_cards;
	ifs.close();
}
