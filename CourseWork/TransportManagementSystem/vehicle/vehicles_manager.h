//
// Created by Alexandr on 12/3/2022.
//

#ifndef TRANSPORTMANAGEMENTSYSTEM_VEHICLES_MANAGER_H
#define TRANSPORTMANAGEMENTSYSTEM_VEHICLES_MANAGER_H

#include "bus.h"
#include "e_bus.h"
#include "tram.h"

#include <iostream>

class vehicles_manager {
private:
	std::list<bus> l_buses;
	std::list<e_bus> l_e_buses;
	std::list<tram> l_trams;
public:
	bus& find_bus(UID);
	bus& add_bus(std::string, uint8_t, uint8_t, double);
	std::string serialize_all_buses();
};

#endif //TRANSPORTMANAGEMENTSYSTEM_VEHICLES_MANAGER_H
