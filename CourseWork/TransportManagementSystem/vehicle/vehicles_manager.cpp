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
	if (l_buses.empty()) {
		return "empty buses list";
	}
	std::stringstream ss;
	ss << "--------------------------\n";
	for (auto& bus : l_buses) {
		ss << bus.serialize_ui() << std::endl;
	}
	ss << "--------------------------\n";
	return ss.str();
}
e_bus& vehicles_manager::find_e_bus(UID uid_to_find)
{
	for (auto& e_bus : l_e_buses) {
		if (e_bus.get_uid()==uid_to_find)
			return e_bus;
	}
	throw std::runtime_error("No such e-bus");
}
e_bus& vehicles_manager::add_e_bus(std::string registration_mark, uint8_t capacity, double battery_consumption)
{
	auto new_e_bus = e_bus(registration_mark, capacity, battery_consumption);
	l_e_buses.push_front(new_e_bus);
	return l_e_buses.front();
}
std::string vehicles_manager::serialize_all_e_buses()
{
	if (l_e_buses.empty()) {
		return "empty e_buses list";
	}
	std::stringstream ss;
	ss << "--------------------------\n";
	for (auto& e_bus : l_e_buses) {
		ss << e_bus.serialize_ui() << std::endl;
	}
	ss << "--------------------------\n";
	return ss.str();
}
tram& vehicles_manager::find_tram(UID uid_to_find)
{
	for (auto& tram : l_trams) {
		if (tram.get_uid()==uid_to_find)
			return tram;
	}
	throw std::runtime_error("No such tram");
}
tram& vehicles_manager::add_tram(std::string registration_mark, uint8_t capacity)
{
	auto new_tram = tram(registration_mark, capacity);
	l_trams.push_front(new_tram);
	return l_trams.front();
}
std::string vehicles_manager::serialize_all_trams()
{
	if (l_trams.empty()) {
		return "empty trams list";
	}
	std::stringstream ss;
	ss << "--------------------------\n";
	for (auto& tram : l_trams) {
		ss << tram.serialize_ui() << std::endl;
	}
	ss << "--------------------------\n";
	return ss.str();
}
bool vehicles_manager::check_if_vehicle_exists(UID uid_to_find)
{
	for (auto& bus : l_buses) {
		if (bus.get_uid()==uid_to_find)
			return true;
	}
	for (auto& e_bus : l_e_buses) {
		if (e_bus.get_uid()==uid_to_find)
			return true;
	}
	for (auto& tram : l_trams) {
		if (tram.get_uid()==uid_to_find)
			return true;
	}
	return false;
}
vehicle::vehicle_type vehicles_manager::get_vehicle_type(UID)
{
	for (auto& bus : l_buses) {
		if (bus.get_uid()==uid_to_find)
			return vehicle::bus;
	}
	for (auto& e_bus : l_e_buses) {
		if (e_bus.get_uid()==uid_to_find)
			return vehicle::e_bus;
	}
	for (auto& tram : l_trams) {
		if (tram.get_uid()==uid_to_find)
			return vehicle::tram;
	}
	return false;
}

void vehicles_manager::save_db(const std::string& db)
{
	std::ofstream ofs(db);
	if (!ofs.is_open())
		return;
	boost::archive::text_oarchive oa(ofs);
	oa & l_buses & l_e_buses & l_trams;
	ofs.close();
}
void vehicles_manager::load_db(const std::string& db)
{
	std::ifstream ifs(db);
	if (!ifs.is_open())
		return;
	boost::archive::text_iarchive ia(ifs);
	ia & l_buses & l_e_buses & l_trams;
	ifs.close();
}