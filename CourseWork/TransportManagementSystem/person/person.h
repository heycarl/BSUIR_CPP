//
// Created by Alexandr on 11/6/2022.
//

#ifndef _PERSON_H_
#define _PERSON_H_

#include <iostream>

#include "date.h"
#include "uid_generator.h"

class person {
private:
	UID uid;
private:
	std::string first_name;
	std::string last_name;
	date date_of_birth;
public:
	person();
	virtual std::string serialize_ui();
	std::string get_first_last_name();
	UID get_uid() const;
};

#endif //_PERSON_H_
