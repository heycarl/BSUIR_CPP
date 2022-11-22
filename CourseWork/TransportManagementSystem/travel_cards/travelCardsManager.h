//
// Created by Alexandr on 11/6/2022.
//

#ifndef TRAVELCARDSMANAGER_H_
#define TRAVELCARDSMANAGER_H_

#include <iostream>

#include "travelCard.h"
#include "../vehicle/vehicle.h"

class travelCardsManager {
public:
    static bool validator(vehicle_type, travelCard);
};

#endif //TRAVELCARDSMANAGER_H_
