//
// Created by Alexandr on 11/6/2022.
//

#ifndef TRAVEL_CARD_H_
#define TRAVEL_CARD_H_

#include <iostream>
#include <boost/serialization/serialization.hpp>

//#include "uid_generator.h"
#include "uid_generator.h"

class travel_card {
private:
	UID uid;
	uint8_t remaining_trips;
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive& archive, const unsigned int version)
	{
		archive & uid;
		archive & remaining_trips;
	}
public:
	travel_card();
	~travel_card() = default;
	explicit travel_card(UID);
	uint8_t get_remaining_trips() const;
	void set_remaining_trips(uint8_t remaining_trips);
	void decrement_trips();
	UID get_uid() const;
	void set_uid(UID u);

};
#endif //TRAVEL_CARD_H_
