//
// Created by Alexandr on 11/22/2022.
//

#ifndef TRANSPORTMANAGEMENTSYSTEM_BUS_H
#define TRANSPORTMANAGEMENTSYSTEM_BUS_H

#include "vehicle.h"

class bus : public vehicle {
private:
    uint8_t fuel_bank_size;
    uint8_t current_bank_size;
    double fuel_consumption;
public:
    bus(uint8_t uid, const std::string &registrationMark, uint8_t capacity, uint8_t fuelBankSize,
        uint8_t currentBankSize, double fuelConsumption);

    int get_remaining_travel_distance() override;
};


#endif //TRANSPORTMANAGEMENTSYSTEM_BUS_H
