//
// Created by Alexandr on 12/2/2022.
//

#include "drivers_manager.h"
#include "date.h"

#include <sstream>

driver& drivers_manager::find_driver(UID uid_to_find)
{
	for (auto& d : l_drivers) {
		if (d.get_uid()==uid_to_find)
			return d;
	}
	throw std::runtime_error("No such driver");
}
driver& drivers_manager::add_driver(std::string vehicle_type, std::string exp_date)
{

	date lic_exp_date = date(exp_date);
	l_drivers.push_front(driver(exp_date, vehicle::parse_vehicle_type(vehicle_type)));
	return l_drivers.front();
}
std::string drivers_manager::serialize_all_drivers()
{
	if (l_drivers.empty()) {
		return "empty drivers list";
	}
	std::stringstream ss;
	ss << "--------------------------\n";
	for (auto& driver : l_drivers) {
		ss << driver.serialize_ui();
	}
	ss << "--------------------------\n";
	return ss.str();
}
bool drivers_manager::check_if_driver_exists(UID uid_to_find)
{
	for (auto& d : l_drivers) {
		if (d.get_uid()==uid_to_find)
			return true;
	}
	return false;
}
