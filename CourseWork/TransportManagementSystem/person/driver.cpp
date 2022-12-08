//
// Created by Alexandr on 11/6/2022.
//
#include <sstream>

#include "driver.h"
std::string driver::serialize_license()
{
	std::stringstream ss;
	ss << "License for " << vehicle::serialize_vehicle_type(license_type) << std::endl
	   << " valid until " << license_expiration.serialize_ui();
	return ss.str();
}
driver::driver(std::string fisrt_name, std::string last_name, std::string dob, vehicle::vehicle_type v_type,
		date lic_exp)
		:person(fisrt_name, last_name, dob), license_type(v_type), license_expiration(lic_exp) { }
