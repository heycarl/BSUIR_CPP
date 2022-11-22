//
// Created by Alexandr on 11/22/2022.
//

#include "bus.h"

int bus::get_remaining_travel_distance() {
    return static_cast<int>(current_bank_size / fuel_consumption);
}

bus::bus(uint8_t uid, const std::string &registrationMark, uint8_t capacity,
         uint8_t fuelBankSize, uint8_t currentBankSize, double fuelConsumption) : vehicle(uid, registrationMark, vehicle_type::bus,
                                                                                          capacity),
                                                                                  fuel_bank_size(fuelBankSize),
                                                                                  current_bank_size(currentBankSize),
                                                                                  fuel_consumption(fuelConsumption) {}
