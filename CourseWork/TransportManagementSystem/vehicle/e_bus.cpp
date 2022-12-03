//
// Created by Alexandr on 11/22/2022.
//

#include "e_bus.h"

e_bus::e_bus(std::string registration_mark, uint8_t capacity, double battery_consumption = 0.1)
		:vehicle(registration_mark, vehicle_type::e_bus,
		capacity),
		 battery_consumption(battery_consumption) { }

int e_bus::get_travel_distance()
{
	return static_cast<int>(100/battery_consumption); // 100 - max charge percent
}
