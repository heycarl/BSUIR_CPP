//
// Created by Alexandr on 11/6/2022.
//

#ifndef STOP_H_
#define STOP_H_

#include <iostream>
#include <list>
#include <sstream>
#include <map>

#include "uid_generator.h"

class bus_stop {
private:
	uint8_t uid;
	std::string name;
	double latitude;
	double longitude;
	std::string get_options_string();
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
	std::map<stop_options, std::string> options_and_names = {
			{stop_options::coffee_machine, "Coffe Machine"},
			{stop_options::rain_cover, "Rain cover"},
			{stop_options::usb_charger, "USB Charger"}
	};
	std::list<stop_options> get_options() const;
	void set_options(std::list<stop_options> stop_options);
	std::list<std::string> serialize_options();
	std::string view_existing_options();
	std::string serialize_stop();
private:
	std::list<stop_options> options;
};

#endif //STOP_H_
