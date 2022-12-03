//
// Created by Alexandr on 11/22/2022.
//

#include "tram.h"

tram::tram(uint8_t uid, const std::string &registrationMark, uint8_t capacity) :vehicle(registrationMark,
		vehicle_type::tram, capacity) {}
