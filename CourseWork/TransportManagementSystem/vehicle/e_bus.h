//
// Created by Alexandr on 11/22/2022.
//

#ifndef TRANSPORTMANAGEMENTSYSTEM_E_BUS_H
#define TRANSPORTMANAGEMENTSYSTEM_E_BUS_H

#include "vehicle.h"

class e_bus : public vehicle {
private:
	double battery_consumption;
public:
	e_bus(const std::string& registrationMark, uint8_t capacity,
			double batteryConsumption);
	int get_travel_distance() override;
};

#endif //TRANSPORTMANAGEMENTSYSTEM_E_BUS_H
