//
// Created by Alexandr on 11/6/2022.
//

#include "vehicle.h"

#include <utility>

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
	switch (t) {
	case bus:
		return "BUS";
	case e_bus:
		return "Electronic-Bus";
	case tram:
		return "Tram";
	}
	return "Unknown";
}
