//
// Created by Alexandr on 11/26/2022.
//

#include "user_passenger.h"
void user_passenger::buy_trips()
{
	travel_card& c = core::tcm.find_travel_card(get_card());
	std::cout << "How many trips you want to buy? ";
	int req_trips;
	std::cin >> req_trips;
	c.set_remaining_trips(c.get_remaining_trips()+req_trips);
}
void user_passenger::view_remaining_trips()
{
	travel_card& c = core::tcm.find_travel_card(get_card());
	std::cout << "You have " << +c.get_remaining_trips() << " remaining trips for your "
			  << +c.get_uid() << " travel card";
}
user_passenger::user_passenger(std::string f_name, std::string l_name, std::string dob, std::string login,
		std::string password)
		:passenger(f_name, l_name, dob), user(login, password) { }
void user_passenger::enter_bus()
{
	// todo
}
void user_passenger::get_arrival_time()
{
	// todo
}
