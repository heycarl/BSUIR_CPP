//
// Created by Alexandr on 11/6/2022.
//

#include <sstream>
#include <algorithm>

#include "route.h"
#include "core.h"

std::string route::serialize_route()
{
	std::stringstream ss;
	ss << "[Route-" << +uid << "] \"" << route_info.src << " -> " << route_info.dst << "\"";
	return ss.str();
}
std::string route::serialize_full_route()
{
	std::stringstream ss;
	ss << serialize_route();
	for (auto o : stop_list) {
		auto& bus_stop = core::bsm.find_bus_stop(o.bus_stop);
		ss << bus_stop.get_uid()
		   << bus_stop.get_name() << " | "
		   << o.arrival_time << " | "
		   << (!(o.need_to_stop) ? "Bypassed |\n" : "");
	}
	return ss.str();
}

void route::delete_stop(uint8_t id)
{
	for (auto s : stop_list) {
		stop_list.erase(std::find_if(stop_list.begin(), stop_list.end(),
				[&](stop const& s) { return s.bus_stop==id; }));
	}
}
void route::add_stop(UID u, time_t arrival_time, bool need_to_stop)
{
	stop_list.push_front({
			u,
			arrival_time,
			need_to_stop
	});
}
UID route::get_route_driver() const
{
	return route_driver;
}
void route::set_route_driver(UID driver)
{
	route::route_driver = driver;
}
UID route::get_vehicle() const
{
	return vehicle;
}
void route::set_vehicle(UID veh)
{
	route::vehicle = veh;
}
UID route::get_uid() const
{
	return uid;
}
route::route(UID vehicle, UID route_driver, std::string src, std::string dst)
		:uid(uidGenerator::generate()), route_info({
		src, dst
}), route_driver(route_driver), vehicle(vehicle)
{
}
bool route::check_arrival_time(UID bus_stop_uid, time_t& arrival_time)
{
	for (stop& stop : stop_list) {
		if (stop.bus_stop==bus_stop_uid) {
			arrival_time = stop.arrival_time;
			return true;
		}
	}
	return false;
}
