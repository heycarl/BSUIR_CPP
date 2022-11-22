//
// Created by Alexandr on 11/22/2022.
//

#ifndef TRANSPORTMANAGEMENTSYSTEM_E_BUS_H
#define TRANSPORTMANAGEMENTSYSTEM_E_BUS_H

#include "vehicle.h"

class e_bus : public vehicle{
private:
    double battery_charge;
    double battery_consumption;
public:
    e_bus(uint8_t uid, const std::string &registrationMark, uint8_t capacity, double batteryCharge,
          double batteryConsumption);
    int get_remaining_travel_distance() override;
};


#endif //TRANSPORTMANAGEMENTSYSTEM_E_BUS_H
