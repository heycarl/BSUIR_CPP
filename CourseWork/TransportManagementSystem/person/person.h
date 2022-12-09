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
	std::string first_name;
	std::string last_name;
	date date_of_birth;
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive& archive, const unsigned int version)
	{
		archive & first_name & last_name & date_of_birth;
	}
public:
	person(std::string fisrt_name, std::string last_name, std::string dob);
	person() = default;
	virtual std::string serialize_ui();
	std::string get_first_last_name();
	UID get_uid() const;
	static void ask_names_dob(std::string req, std::string& f_name, std::string& last_name, std::string& dob);
};

#endif //_PERSON_H_
