//
// Created by Alexandr on 11/6/2022.
//

#ifndef ROUTE_H_
#define ROUTE_H_

#include <iostream>
#include <list>

#include "bus_stop.h"
#include "uid_generator.h"
class route {
private:
	UID uid;
public:
	UID get_uid() const;
private:
	struct stop {
		UID bus_stop;
		time_t arrival_time = 0;
		bool need_to_stop = true;
	};
	struct route_info {
		std::string src;
		std::string dst;
	} route_info;
	std::list<stop> stop_list;
public:
	UID get_route_driver() const;
	void set_route_driver(UID driver);
	UID get_vehicle() const;
	void set_vehicle(UID veh);
private:
	UID route_driver;
	UID vehicle;
public:
	route(UID vehicle, UID route_driver, std::string src, std::string dst);
	std::string serialize_route();
	std::string serialize_full_route();
	void delete_stop(uint8_t id);
	void add_stop(UID u, time_t arrival_time, bool need_to_stop);

//	std::string view_driver();
};

#endif //ROUTE_H_
