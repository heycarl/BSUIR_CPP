//
// Created by Alexandr on 11/6/2022.
//
#include <sstream>

#include "driver.h"
std::string driver::serialize_license ()
{
  std::stringstream ss;
  ss << "License for " << vehicle::serialize_vehicle_type (license_type) << std::endl
	 << " valid until " << license_expiration.serialize ();
  return ss.str ();
}
driver::driver(const date& license_expiration, vehicle::vehicle_type license_type)
		:license_expiration(license_expiration), license_type(license_type) { }
