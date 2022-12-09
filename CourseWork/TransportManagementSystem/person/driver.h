//
// Created by Alexandr on 11/6/2022.
//

#ifndef DRIVER_H_
#define DRIVER_H_

#include <iostream>
#include <boost/serialization/base_object.hpp>

#include "person.h"
#include "date.h"
#include "vehicle.h"

class driver : public person {
private:
	date license_expiration;
	vehicle::vehicle_type license_type = vehicle::vehicle_type::bus; // default license
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive& archive, const unsigned int version)
	{
		archive & boost::serialization::base_object<person>(*this);
		archive & license_expiration & license_type;
	}
public:
	driver() = default;
	driver(std::string fisrt_name, std::string last_name, std::string dob, vehicle::vehicle_type v_type, date lic_exp);
	std::string serialize_ui() override
	{
		return person::serialize_ui()+serialize_license();
	};
	std::string serialize_license();
};

#endif //DRIVER_H_
