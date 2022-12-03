//
// Created by Alexandr on 11/22/2022.
//

#include "tram.h"

tram::tram(std::string registration_mark, uint8_t capacity) :vehicle(registration_mark,
		vehicle_type::tram, capacity) {}