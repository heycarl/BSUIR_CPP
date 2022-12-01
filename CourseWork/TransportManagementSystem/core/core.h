//
// Created by Alexandr on 11/27/2022.
//

#ifndef TRANSPORTMANAGEMENTSYSTEM_CORE_H
#define TRANSPORTMANAGEMENTSYSTEM_CORE_H

#include "travel_cards_manager.h"
#include "routes_manager.h"
#include "bus_stops_manager.h"

class core {
public:
	static travel_cards_manager tcm;
	static routes_manager rm;
	static bus_stops_manager bsm;
};
#endif //TRANSPORTMANAGEMENTSYSTEM_CORE_H
