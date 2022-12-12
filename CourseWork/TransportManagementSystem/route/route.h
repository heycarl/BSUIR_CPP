//
// Created by Alexandr on 11/6/2022.
//

#ifndef ROUTE_H_
#define ROUTE_H_

#include <iostream>
#include <list>
#include <boost/serialization/serialization.hpp>

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
		template<class Archive>
		void serialize(Archive& archive, const unsigned int version)
		{
			archive & bus_stop & arrival_time & need_to_stop;
		}
	};
	struct route_info {
		std::string src;
		std::string dst;
		template<class Archive>
		void serialize(Archive& archive, const unsigned int version)
		{
			archive & src & dst;
		}
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
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive& archive, const unsigned int version)
	{
		archive & uid & route_info & stop_list & route_driver & vehicle;
	}
public:
	route() = default;
	route(UID vehicle, UID route_driver, std::string src, std::string dst);
	std::string serialize_route();
	std::string serialize_full_route();
	void delete_stop(uint8_t id);
	void add_stop(UID u, time_t arrival_time, bool need_to_stop);
	bool check_arrival_time(UID bus_stop_uid, time_t& arrival_time);

//	std::string view_driver();
};

#endif //ROUTE_H_
