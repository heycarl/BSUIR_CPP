//
// Created by Alexandr on 11/27/2022.
//

#include "bus_stops_manager.h"

bus_stop& bus_stops_manager::find_bus_stop(UID uid_to_find)
{
	for (auto& s : l_bus_stops) {
		if (s.get_uid()==uid_to_find)
			return s;
	}
	throw std::runtime_error("No such bus stop");
}
bus_stop& bus_stops_manager::add_bus_stop(std::string stop_name, double lat, double lon)
{
	auto new_stop = bus_stop(stop_name, lat, lon);
	l_bus_stops.push_front(new_stop);
	return l_bus_stops.front();
}
std::string bus_stops_manager::serialize_all_bus_stops()
{
	std::stringstream ss;
	for (auto& stop : l_bus_stops) {
		ss << stop.serialize_stop();
	}
	return ss.str();
}
