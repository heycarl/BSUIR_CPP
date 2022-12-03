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

bool vehicle::validate_card(travel_card card)
{
	return travel_cards_manager::validator(card);
}

vehicle::vehicle(uint8_t uid, std::string registrationMark, vehicle::vehicle_type type, uint8_t capacity)
		:uid(
		uid), registration_mark(std::move(registrationMark)), type(type), capacity(capacity) { }

int vehicle::get_remaining_travel_distance()
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
		if (t.find(t.find(vt.second)))
			return vt.first;
	}
	throw std::runtime_error("No such vehicle type");
}
