//
// Created by Alexandr on 11/27/2022.
//

#ifndef TRANSPORTMANAGEMENTSYSTEM_ROUTES_MANAGER_H
#define TRANSPORTMANAGEMENTSYSTEM_ROUTES_MANAGER_H

#include <iostream>
#include <list>

#include "route.h"

class routes_manager {
private:
	std::list<route> l_routes;
public:
	route& add_route();
	route& find_route(UID);
	std::string serialize_all_routes_path();
};

#endif //TRANSPORTMANAGEMENTSYSTEM_ROUTES_MANAGER_H
