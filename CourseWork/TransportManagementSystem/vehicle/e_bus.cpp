//
// Created by Alexandr on 11/22/2022.
//

#include "e_bus.h"

e_bus::e_bus(const std::string& registrationMark, uint8_t capacity, double batteryConsumption = 0.1)
		:vehicle(registrationMark, vehicle_type::e_bus,
		capacity),
		 battery_consumption(batteryConsumption) { }

int e_bus::get_travel_distance()
{
	return static_cast<int>(100/battery_consumption); // 100 - max charge percent
}
