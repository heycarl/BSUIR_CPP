//
// Created by Alexandr on 11/6/2022.
//

#ifndef TRANSPORTMANAGEMENTSYSTEM_VEHICLE_H_
#define TRANSPORTMANAGEMENTSYSTEM_VEHICLE_H_

#include <iostream>
#include <map>
#include <sstream>

#include "travel_card.h"
#include "travel_cards_manager.h"
#include "uid_generator.h"

class vehicle {
public:
	enum vehicle_type {
		bus,
		e_bus,
		tram
	};
	static std::map<vehicle_type, std::string> vehicle_type_string;
private:
	UID uid;
	std::string registration_mark;
	vehicle_type type;
	uint8_t capacity;
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive& archive, const unsigned int version)
	{
		archive & uid & registration_mark & type & capacity;
	}
public:
	vehicle() = default;
	UID get_uid() const;
	const std::string& get_registration_mark() const;
	vehicle_type get_type() const;
	uint8_t get_capacity() const;
	vehicle(std::string registration_mark, vehicle::vehicle_type type, uint8_t capacity);
	bool validate_card(travel_card&);
	virtual int get_travel_distance();
	virtual std::string serialize_ui();
public:
	static std::string serialize_vehicle_type(vehicle_type);
	static vehicle_type parse_vehicle_type(std::string);
	static std::string view_existing_types();
};

#endif //TRANSPORTMANAGEMENTSYSTEM_VEHICLE_H_
