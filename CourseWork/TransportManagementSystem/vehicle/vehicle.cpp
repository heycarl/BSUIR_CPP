//
// Created by Alexandr on 11/6/2022.
//

#include "vehicle.h"

#include <utility>

bool vehicle::validate_card(travelCard card) {
    return travelCardsManager::validator(card);
}

vehicle::vehicle(uint8_t uid, std::string registrationMark, vehicle::vehicle_type type, uint8_t capacity) : uid(
        uid), registration_mark(std::move(registrationMark)), type(type), capacity(capacity) {}

int vehicle::get_remaining_travel_distance() {
    return 999; // infinite travel distance for non-fuel vehicles
}
