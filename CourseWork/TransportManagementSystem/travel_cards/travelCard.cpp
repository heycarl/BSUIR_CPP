//
// Created by Alexandr on 11/6/2022.
//

#include "travelCard.h"
uint8_t travelCard::get_remaining_trips () const
{
  return remaining_trips;
}
void travelCard::set_remaining_trips (uint8_t remaining_trips)
{
  travelCard::remaining_trips = remaining_trips;
}
travelCard::travelCard (uint8_t holder_uid)
{
  uid = holder_uid
}
void travelCard::decrement_trips ()
{
  if (remaining_trips > 0)
    remaining_trips--;
}
