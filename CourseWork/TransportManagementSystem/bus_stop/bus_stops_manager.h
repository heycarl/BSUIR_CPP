//
// Created by Alexandr on 11/27/2022.
//

#ifndef TRANSPORTMANAGEMENTSYSTEM_BUS_STOPS_MANAGER_H
#define TRANSPORTMANAGEMENTSYSTEM_BUS_STOPS_MANAGER_H

#include <iostream>
#include <list>
#include <sstream>

#include "bus_stop.h"
#include "uid_generator.h"

class bus_stops_manager {
private:
	std::list<bus_stop> l_bus_stops;
public:
	bus_stop& find_bus_stop(UID);
	bus_stop& add_bus_stop(std::string, double, double);
	std::string serialize_all_bus_stops();
	std::string serialize_all_bus_stops_names();
};

#endif //TRANSPORTMANAGEMENTSYSTEM_BUS_STOPS_MANAGER_H
