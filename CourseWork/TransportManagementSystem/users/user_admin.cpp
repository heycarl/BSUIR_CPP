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
	std::cout << "Enter license vehicle type ( " << vehicle::view_existing_types() << " ): ";
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
void user_admin::create_vehicle()
{
	std::cout << "Enter new vehicle type (" << vehicle::view_existing_types() << "): ";
	std::string new_vehicle_type;
	std::cin >> new_vehicle_type;

	auto new_type = vehicle::parse_vehicle_type(new_vehicle_type);

	std::string registration_mark;
	std::cout << "Enter registration mark: ";
	std::cin >> registration_mark;
	int capacity;
	std::cout << "Enter passenger capacity: ";
	std::cin >> capacity;
	double consumption;

	switch (new_type) {
	case vehicle::bus: {
		int bank_size;

		std::cout << "Enter fuel bank size: ";
		std::cin >> bank_size;
		std::cout << "Enter fuel consumption: ";
		std::cin >> consumption;
		core::vm.add_bus(registration_mark, capacity, bank_size, consumption);
		break;
	}
	case vehicle::e_bus: {
		std::cout << "Enter fuel consumption: ";
		std::cin >> consumption;
		core::vm.add_e_bus(registration_mark, capacity, consumption);
		break;
	}
	case vehicle::tram: {
		core::vm.add_tram(registration_mark, capacity);
		break;
	}
	default:
		throw std::runtime_error("No such vehicle type");
	}
}
void user_admin::view_vehicles()
{
	std::cout << "Enter vehicle type to view (" << vehicle::view_existing_types() << ", All ): ";
	std::string new_vehicle_type;
	std::cin >> new_vehicle_type;
	if (new_vehicle_type=="All") {
		std::cout << core::vm.serialize_all_buses() << std::endl;
		std::cout << core::vm.serialize_all_e_buses() << std::endl;
		std::cout << core::vm.serialize_all_trams() << std::endl;
		return;
	}

	switch (vehicle::parse_vehicle_type(new_vehicle_type)) {
	case vehicle::bus: {
		std::cout << core::vm.serialize_all_buses() << std::endl;
		break;
	}
	case vehicle::e_bus: {
		std::cout << core::vm.serialize_all_e_buses() << std::endl;
		break;
	}
	case vehicle::tram: {
		std::cout << core::vm.serialize_all_trams() << std::endl;
		break;
	}
	default:
		throw std::runtime_error("No such vehicle type");
	}
}
