//
// Created by Alexandr on 12/2/2022.
//

#ifndef TRANSPORTMANAGEMENTSYSTEM_DRIVERS_MANAGER_H
#define TRANSPORTMANAGEMENTSYSTEM_DRIVERS_MANAGER_H

#include "driver.h"
#include "manager.h"

class drivers_manager : public manager {
private:
	std::list<driver> l_drivers;
public:
	driver& find_driver(UID);
	driver& add_driver(std::string fisrt_name, std::string last_name, std::string dob,
			std::string v_type, std::string exp_date);
	std::string serialize_all_drivers();

	bool check_if_driver_exists(UID);
	void save_db(const std::string&) override;
	void load_db(const std::string&) override;
};

#endif //TRANSPORTMANAGEMENTSYSTEM_DRIVERS_MANAGER_H
