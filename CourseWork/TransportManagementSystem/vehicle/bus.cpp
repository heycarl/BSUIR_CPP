//
// Created by Alexandr on 11/22/2022.
//

#include "bus.h"

int bus::get_travel_distance()
{
	return static_cast<int>(fuel_bank_size/fuel_consumption);
}

bus::bus(std::string registration_mark, uint8_t capacity,
		uint8_t fuel_bank_size, double fuel_consumption = 0.5)
		:vehicle(registration_mark,
		vehicle_type::bus,
		capacity),
		 fuel_consumption(fuel_consumption),
		 fuel_bank_size(fuel_bank_size) { }
std::string bus::serialize_ui()
{
	std::stringstream ss;
	ss << vehicle::serialize_ui() << std::endl
	   << "Travel distance: " << get_travel_distance();
	return ss.str();
}
