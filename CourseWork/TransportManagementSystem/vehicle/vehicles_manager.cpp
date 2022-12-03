//
// Created by Alexandr on 12/3/2022.
//

#include "vehicles_manager.h"
bus& vehicles_manager::find_bus(UID uid_to_find)
{
	for (auto& b : l_buses) {
		if (b.get_uid()==uid_to_find)
			return b;
	}
	throw std::runtime_error("No such bus");
}
bus& vehicles_manager::add_bus(std::string registration_mark, uint8_t capacity, uint8_t fuel_bank_size,
		double fuel_consumption)
{
	auto new_bus = bus(registration_mark, capacity, fuel_bank_size, fuel_consumption);
	l_buses.push_front(new_bus);
	return l_buses.front();
}
std::string vehicles_manager::serialize_all_buses()
{
	std::stringstream ss;
	ss << "--------------------------\n";
	for (auto& bus : l_buses) {
		ss << bus.serialize() << std::endl;
	}
	ss << "--------------------------\n";
	return ss.str();
}
