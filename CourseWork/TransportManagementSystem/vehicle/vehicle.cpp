//
// Created by Alexandr on 11/6/2022.
//

#include "vehicle.h"

#include <utility>
#include <algorithm>

std::map<vehicle::vehicle_type, std::string> vehicle::vehicle_type_string = {
		{ bus, "Bus" },
		{ e_bus, "Electro-bus" },
		{ tram, "Tram" }
};

bool vehicle::validate_card(travel_card& card)
{
	return travel_cards_manager::validator(card);
}

vehicle::vehicle(std::string registration_mark, vehicle::vehicle_type type, uint8_t capacity)
		:uid(uidGenerator::generate()), registration_mark(std::move(registration_mark)), type(type),
		 capacity(capacity) { }

int vehicle::get_travel_distance()
{
	return 999; // infinite travel distance for non-fuel vehicles
}
std::string vehicle::serialize_vehicle_type(vehicle::vehicle_type t)
{
	if (vehicle_type_string.find(t)==vehicle_type_string.end())
		return "Unknown";
	return vehicle_type_string[t];
}
vehicle::vehicle_type vehicle::parse_vehicle_type(std::string t)
{
	for (auto vt : vehicle_type_string) {
		if (vt.second==t)
			return vt.first;
	}
	throw std::runtime_error("No such vehicle type");
}
UID vehicle::get_uid() const
{
	return uid;
}
const std::string& vehicle::get_registration_mark() const
{
	return registration_mark;
}
vehicle::vehicle_type vehicle::get_type() const
{
	return type;
}
uint8_t vehicle::get_capacity() const
{
	return capacity;
}
std::string vehicle::view_existing_types()
{
	std::stringstream ss;
	for (auto i = vehicle::vehicle_type_string.begin();;) {
		ss << i->second;
		if (++i==vehicle::vehicle_type_string.end())
			break;
		ss << ", ";
	}
	return ss.str();
}
std::string vehicle::serialize_ui()
{
	std::stringstream ss;
	ss << "[" << serialize_vehicle_type(type) << "-" << +uid << "]" << std::endl
	   << "Registration mark: " << registration_mark << std::endl
	   << "Passeneger capacity: " << +capacity;

	return ss.str();
}
