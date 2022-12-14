//
// Created by Alexandr on 11/6/2022.
//

#include "bus_stop.h"

#include <utility>

UID bus_stop::get_uid() const
{
	return uid;
}
void bus_stop::set_uid(UID u)
{
	bus_stop::uid = u;
}
const std::string& bus_stop::get_name() const
{
	return name;
}
void bus_stop::set_name(const std::string& n)
{
	bus_stop::name = n;
}
void bus_stop::set_options(std::list<stop_options> stop_options)
{
	bus_stop::options = std::move(stop_options);
}
std::string bus_stop::get_coords() const
{
	std::stringstream ss;
	ss << "Coordinates: " << longitude << " " << latitude;
	return ss.str();
}
void bus_stop::set_coords(double lon, double lat)
{
	longitude = lon;
	latitude = lat;
}
bus_stop::bus_stop(const std::string& name, double latitude, double longitude)
		:uid(uid_generator::generate()), name(name), latitude(latitude), longitude(longitude) { }
std::string bus_stop::serialize_ui()
{
	std::stringstream ss;
	ss << "[Bus-stop-" << +get_uid() << "]" << std::endl
	   << "Name: " << get_name() << std::endl
	   << "Coordinates: " << get_coords() << std::endl
	   << "Options: " << get_options_string() << std::endl;
	return ss.str();
}
std::string bus_stop::get_options_string()
{
	if (options.empty())
		return "";
	std::stringstream ss;
	for (auto& option : options) {
		ss << options_and_names[option] << (option==options.back() ? "" : ", ");
	}
	return ss.str();
}
std::string bus_stop::view_existing_options()
{
	std::stringstream ss;
	for (auto o : options_and_names) {
		ss << "[" << o.first << "] " << o.second << std::endl;
	}
	return ss.str();
}
