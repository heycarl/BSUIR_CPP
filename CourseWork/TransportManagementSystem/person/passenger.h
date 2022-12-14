//
// Created by Alexandr on 11/6/2022.
//

#ifndef _PASSENGER_H_
#define _PASSENGER_H_

#include <iostream>

#include "person.h"
#include "uid_generator.h"

#include "core.h"

class passenger : public person {
public:
	passenger() = default;
	passenger(std::string f_name, std::string l_name, std::string dob);
private:
	UID card;
public:
	std::string serialize_ui() override;
	UID get_card();
};

#endif //_PASSENGER_H_
