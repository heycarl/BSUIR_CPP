//
// Created by Alexandr on 11/6/2022.
//

#ifndef STOP_H_
#define STOP_H_

#include <iostream>
#include <list>
#include <sstream>

#include "uid_generator.h"

class bus_stop {
private:
	uint8_t uid;
	std::string name;
	double latitude;
	double longitude;
public:
	bus_stop(const std::string& name, double latitude, double longitude);
	UID get_uid() const;
	void set_uid(uint8_t u);
	const std::string& get_name() const;
	void set_name(const std::string& n);
	std::string get_coords() const;
	void set_coords(double, double);
public:
	enum stop_options {
		rain_cover,
		usb_charger,
		coffee_machine
	};
	std::list<stop_options> get_options() const;
	void set_options(std::list<stop_options> stop_options);
	std::list<std::string> serialize_options();
private:
	std::list<stop_options> options;
};

#endif //STOP_H_
