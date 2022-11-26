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
