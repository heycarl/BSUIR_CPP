//
// Created by Alexandr on 11/26/2022.
//
#include <string>

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
void user_admin::modify_bus_stop()
{
	std::cout << core::bsm.serialize_all_bus_stops_names();
	int stop_id;
	std::cout << "Enter stop's UID to modify: ";
	std::cin >> stop_id;
	auto& stop = core::bsm.find_bus_stop(stop_id);
	std::cout << "What field you want to modify?\n1. Name\n2.Coordinates\n3. Options\n: ";
	int ch_index;
	std::cin >> ch_index;
	switch (ch_index) {
	case 1: {
		std::string new_name;
		std::cout << "Enter new name: ";
		std::cin >> new_name;
		stop.set_name(new_name);
		break;
	}
	case 2: {
		std::cout << "Enter new coordinates: ";
		double lat, lon;
		std::cin >> lat;
		std::cin >> lon;
		stop.set_coords(lat, lon);
		break;
	}
	case 3: {
		std::cout << "There are few avaliable stop options: \n" << stop.view_existing_options() << std::endl
				  << "Enter options indexes (with space separator): " << std::endl;
		std::string user_options;
		std::cin.sync();
		std::getline(std::cin, user_options);
		std::stringstream ss(user_options);
		std::string option;

		std::list<bus_stop::stop_options> new_options;
		while (std::getline(ss, option, ' ')) {
			new_options.push_back((bus_stop::stop_options)stoi(option));
		}
		stop.set_options(new_options);
		break;
	}
	default: {
		std::cout << "Invalid menu option!";
		break;
	}
	}
}
void user_admin::create_driver()
{
	std::string vehicle_type;
	std::cout << "Enter license vehicle type ( "
			  << ([]() -> std::string {
				std::stringstream ss;
				for (auto i = vehicle::vehicle_type_string.begin();;) {
					ss << i->second;
					if (++i==vehicle::vehicle_type_string.end())
						break;
					ss << ", ";
				}
				return ss.str();
			  }).operator()()
			  << " ): ";
	std::cin >> vehicle_type;

	std::string exp_date;
	std::cout << "Enter license expiration date in \"dd.mm.yy\" notation: ";
	std::cin >> exp_date;
	core::dm.add_driver(vehicle_type, exp_date);
}
void user_admin::view_drivers()
{
	std::cout << core::dm.serialize_all_drivers();
}