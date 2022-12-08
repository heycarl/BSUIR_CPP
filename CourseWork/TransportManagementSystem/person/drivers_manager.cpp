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
driver& drivers_manager::add_driver(std::string fisrt_name, std::string last_name, std::string dob,
		std::string v_type, std::string exp_date)
{

	date lic_exp_date = date(exp_date);
	l_drivers.push_front(driver(fisrt_name, last_name, dob, vehicle::parse_vehicle_type(v_type), lic_exp_date));
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
void drivers_manager::save_db(const std::string& db)
{
	std::ofstream ofs(db);
	if (!ofs.is_open())
		return;
	boost::archive::text_oarchive oa(ofs);
	oa & l_drivers;
	ofs.close();
}
void drivers_manager::load_db(const std::string& db)
{
	std::ifstream ifs(db);
	if (!ifs.is_open())
		return;
	boost::archive::text_iarchive ia(ifs);
	ia & l_drivers;
	ifs.close();
}
