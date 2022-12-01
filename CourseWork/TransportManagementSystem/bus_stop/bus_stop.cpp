//
// Created by Alexandr on 11/6/2022.
//

#include "bus_stop.h"

#include <utility>
uint8_t bus_stop::get_uid() const
{
	return uid;
}
void bus_stop::set_uid(uint8_t u)
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
std::list<bus_stop::stop_options> bus_stop::get_options() const
{
	return options;
}
void bus_stop::set_options(std::list<stop_options> stop_options)
{
	bus_stop::options = std::move(stop_options);
}
std::list<std::string> bus_stop::serialize_options()
{
	std::list<std::string> out;
	for (auto o : bus_stop::options) {
		switch (o) {
		case rain_cover:
			out.emplace_back("Rain cover");
		case usb_charger:
			out.emplace_back("USB charger");
		case coffee_machine:
			out.emplace_back("Coffee machine");
		}
	}
	return out;
}
std::string bus_stop::get_coords() const
{
	std::stringstream ss;
	ss << "Coordinates: " << longitude << " " << latitude << std::endl;
	return ss.str();
}
void bus_stop::set_coords(double lon, double lat)
{
	longitude = lon;
	latitude = lat;
}
bus_stop::bus_stop(const std::string& name, double latitude, double longitude)
		:uid(uidGenerator::generate()), name(name), latitude(latitude), longitude(longitude) { }
std::string bus_stop::serialize_stop()
{
	std::stringstream ss;
	ss << "-- " << get_name() << " --" << std::endl
	   << "UID: " << get_uid() << std::endl
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
		ss << option << (option==options.front() ? "" : ", ");
	}
	ss << std::endl;
	return ss.str();
}
