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
			  << +c.get_uid() << " travel card" << std::endl;
}
user_passenger::user_passenger(std::string f_name, std::string l_name, std::string dob, std::string login,
		std::string password)
		:passenger(f_name, l_name, dob), user(login, password) { }
void user_passenger::enter_bus()
{
	std::cout << "Enter bus stop id, where you are: ";
	std::cout << core::bsm.serialize_all_bus_stops_names();
	int stop_id;
	std::cin >> stop_id;

	auto routes_with_stop = core::rm.get_routes_with_stop(stop_id);
	if (routes_with_stop.empty()) {
		std::cout << "Stop is not used by routes" << std::endl;
		return;
	}
	for (auto& route: routes_with_stop) {
		std::cout << route.serialize_route() << std::endl;
	}
	std::cout << "Enter route, you want to enter: ";
	int route_id;
	std::cin >> route_id;
	vehicle& route_vehicle = core::vm.get_vehicle_by_id(core::rm.find_route(route_id).get_vehicle());
	if (route_vehicle.validate_card(core::tcm.find_travel_card(get_card()))){
		core::rm.find_route(route_id).increment_popularity();
	} else {
		throw std::runtime_error("Travel card cannot be validated");
	}
}
void user_passenger::get_arrival_time()
{
	std::cout << "Enter bus stop id, where you are: ";
	std::cout << core::bsm.serialize_all_bus_stops_names();
	int stop_id;
	std::cin >> stop_id;
	auto routes_with_stop = core::rm.get_routes_with_stop(stop_id);
	if (routes_with_stop.empty()) {
		std::cout << "Stop is not used by routes" << std::endl;
		return;
	}

	std::time_t arrival_time;
	std::cout << "[Bus-stop-" << stop_id << "]" << std::endl;
	for (auto& route: routes_with_stop) {
		if (route.check_arrival_time(stop_id, arrival_time)){
			std::cout << route.serialize_route() << " at " << arrival_time << std::endl;
		}
	}
}
