//
// Created by Alexandr on 11/6/2022.
//

#ifndef TRANSPORTMANAGEMENTSYSTEM_VEHICLE_H_
#define TRANSPORTMANAGEMENTSYSTEM_VEHICLE_H_

#include <iostream>

#include "../travel_cards/travelCardsManager.h"
#include "../travel_cards/travelCard.h"

class vehicle {
public:
    enum vehicle_type {
        bus,
        e_bus,
        tram
    };
private:
    uint8_t uid;
    std::string registration_mark;
    vehicle_type type;
    uint8_t capacity;
public:
    vehicle(uint8_t uid, std::string registrationMark, vehicle_type type, uint8_t capacity);

    bool validate_card(travelCard);
    virtual int get_remaining_travel_distance();
};

#endif //TRANSPORTMANAGEMENTSYSTEM_VEHICLE_H_
