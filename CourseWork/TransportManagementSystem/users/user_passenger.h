//
// Created by Alexandr on 11/26/2022.
//

#ifndef _USER_PASSENGER_H_
#define _USER_PASSENGER_H_

#include "user.h"
#include "passenger.h"

#include "core.h"

class user_passenger : public user, public passenger {
private:
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive& archive, const unsigned int version)
	{
		archive & boost::serialization::base_object<user>(*this);
		archive & boost::serialization::base_object<passenger>(*this);
	}
public:
	user_passenger() = default;
	user_passenger(std::string f_name, std::string l_name, std::string dob, std::string login, std::string password);
	void buy_trips();
	void view_remaining_trips();
	void enter_bus();
	void get_arrival_time();
};

#endif //_USER_PASSENGER_H_
