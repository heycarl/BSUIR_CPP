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
	if (l_bus_stops.empty()) {
		return "empty stop list";
	}
	std::stringstream ss;
	ss << "--------------------------\n";
	for (auto& stop : l_bus_stops) {
		ss << stop.serialize_ui();
	}
	ss << "--------------------------\n";
	return ss.str();
}
std::string bus_stops_manager::serialize_all_bus_stops_names()
{
	std::stringstream ss;
	ss << "[ ";
	for (auto& stop : l_bus_stops) {
		ss << +stop.get_uid() << " "
		   << stop.get_name() << " | ";
	}
	ss << " ]" << std::endl;
	return ss.str();
}
void bus_stops_manager::save_db(const std::string& db)
{
	std::ofstream ofs(db);
	if (!ofs.is_open())
		return;
	boost::archive::text_oarchive oa(ofs);
	oa & l_bus_stops;
	ofs.close();
}
void bus_stops_manager::load_db(const std::string& db)
{
	std::ifstream ifs(db);
	if (!ifs.is_open())
		return;
	boost::archive::text_iarchive ia(ifs);
	ia & l_bus_stops;
	ifs.close();
}
