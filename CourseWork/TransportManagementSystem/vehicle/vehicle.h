//
// Created by Alexandr on 11/6/2022.
//

#ifndef TRANSPORTMANAGEMENTSYSTEM_VEHICLE_H_
#define TRANSPORTMANAGEMENTSYSTEM_VEHICLE_H_

#include <iostream>
#include <map>

#include "travel_card.h"
#include "travel_cards_manager.h"

class vehicle {
public:
    enum vehicle_type {
        bus,
        e_bus,
        tram
    };
	static std::map<vehicle_type, std::string> vehicle_type_string;
private:
    uint8_t uid;
    std::string registration_mark;
    vehicle_type type;
    uint8_t capacity;
public:
    vehicle(uint8_t uid, std::string registrationMark, vehicle_type v_type, uint8_t capacity);

    bool validate_card(travel_card);
    virtual int get_remaining_travel_distance();
	static std::string serialize_vehicle_type(vehicle_type);
	static vehicle_type parse_vehicle_type(std::string);
};

#endif //TRANSPORTMANAGEMENTSYSTEM_VEHICLE_H_
