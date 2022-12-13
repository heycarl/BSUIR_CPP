//
// Created by Alexandr on 11/27/2022.
//

#ifndef TRANSPORTMANAGEMENTSYSTEM_ROUTES_MANAGER_H
#define TRANSPORTMANAGEMENTSYSTEM_ROUTES_MANAGER_H

#include <iostream>
#include <list>

#include "route.h"
#include "manager.h"

class routes_manager : public manager{
private:
	std::list<route> l_routes;
public:
	route& add_route(UID vehicle, UID driver, std::string src_point, std::string dst_point);
	route& find_route(UID);
	std::list<route> get_routes_with_stop(UID stop_id);
	std::string serialize_all_routes_path();
	std::string serialize_all_routes_stats();
	void save_db(const std::string &) override;
	void load_db(const std::string &) override;
};

#endif //TRANSPORTMANAGEMENTSYSTEM_ROUTES_MANAGER_H
