//
// Created by Alexandr on 11/22/2022.
//

#ifndef TRANSPORTMANAGEMENTSYSTEM_TRAM_H
#define TRANSPORTMANAGEMENTSYSTEM_TRAM_H

#include "vehicle.h"

class tram : public vehicle {
public:
    tram(uint8_t uid, const std::string &registrationMark, uint8_t capacity);
};


#endif //TRANSPORTMANAGEMENTSYSTEM_TRAM_H
