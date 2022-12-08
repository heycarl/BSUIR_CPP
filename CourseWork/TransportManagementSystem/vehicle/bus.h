//
// Created by Alexandr on 11/22/2022.
//

#ifndef TRANSPORTMANAGEMENTSYSTEM_BUS_H
#define TRANSPORTMANAGEMENTSYSTEM_BUS_H

#include "vehicle.h"
#include <boost/serialization/serialization.hpp>

class bus : public vehicle {
private:
	uint8_t fuel_bank_size;
	double fuel_consumption;
public:
	bus() = default;
	bus(std::string, uint8_t, uint8_t, double);

	int get_travel_distance() override;
	std::string serialize_ui() override;
};

#endif //TRANSPORTMANAGEMENTSYSTEM_BUS_H
