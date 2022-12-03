//
// Created by Alexandr on 12/2/2022.
//

#ifndef TRANSPORTMANAGEMENTSYSTEM_DRIVERS_MANAGER_H
#define TRANSPORTMANAGEMENTSYSTEM_DRIVERS_MANAGER_H

#include "driver.h"

class drivers_manager {
private:
	std::list<driver> l_drivers;
public:
	driver& find_driver(UID);
	driver& add_driver(std::string, std::string);
	std::string serialize_all_drivers();
};

#endif //TRANSPORTMANAGEMENTSYSTEM_DRIVERS_MANAGER_H
