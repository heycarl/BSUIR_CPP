//
// Created by Alexandr on 11/26/2022.
//

#include "user_admin.h"
void user_admin::create_bus_stop()
{
	std::string stop_name;
	std::cout << "Enter bus stop name: ";
	std::cin >> stop_name;
	double lat, lon;
	std::cout << "Enter latitude: ";
	std::cin >> lat;
	std::cout << "Enter longitude: ";
	std::cin >> lon;
	core::bsm.add_bus_stop(stop_name, lat, lon);
}
void user_admin::view_bus_stops()
{
	std::cout << core::bsm.serialize_all_bus_stops() << std::endl;
}
