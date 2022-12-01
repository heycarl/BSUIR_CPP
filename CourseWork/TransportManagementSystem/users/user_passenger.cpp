//
// Created by Alexandr on 11/26/2022.
//

#include "user_passenger.h"
void user_passenger::buy_trips()
{
	travel_card& c = core::tcm.find_travel_card(me.get_card());
	std::cout << "How many trips you want to buy? ";
	int req_trips;
	std::cin >> req_trips;
	c.set_remaining_trips(c.get_remaining_trips() + req_trips);
}
void user_passenger::view_remaining_trips()
{
	travel_card& c = core::tcm.find_travel_card(me.get_card());
	std::cout << "You have " << +c.get_remaining_trips() << " remaining trips for your "
	<< +c.get_uid() << " travel card";
}
