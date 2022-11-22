//
// Created by Alexandr on 11/22/2022.
//

#include "e_bus.h"

e_bus::e_bus(uint8_t uid, const std::string &registrationMark, uint8_t capacity,
             double batteryCharge, double batteryConsumption) : vehicle(uid, registrationMark, vehicle_type::e_bus, capacity),
                                                                battery_charge(batteryCharge),
                                                                battery_consumption(batteryConsumption) {}

int e_bus::get_remaining_travel_distance() {
    return static_cast<int>(battery_charge / battery_consumption);
}
