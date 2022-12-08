//
// Created by Alexandr on 11/6/2022.
//

#include "travel_card.h"
uint8_t travel_card::get_remaining_trips () const
{
  return remaining_trips;
}
void travel_card::set_remaining_trips (uint8_t remaining_trips)
{
  travel_card::remaining_trips = remaining_trips;
}
travel_card::travel_card (UID holder_uid)
{
  uid = holder_uid;
}
void travel_card::decrement_trips ()
{
  if (remaining_trips > 0)
    remaining_trips--;
}
UID travel_card::get_uid () const
{
  return uid;
}
void travel_card::set_uid (UID u)
{
  travel_card::uid = u;
}
travel_card::travel_card()
{
	uid = 0;
	remaining_trips = 0;
}
