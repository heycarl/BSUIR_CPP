//
// Created by Alexandr on 11/26/2022.
//

#ifndef _USER_H_
#define _USER_H_

#include <iostream>
#include <boost/serialization/serialization.hpp>

class user {
private:
	std::string login;
	std::string password;
private:
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive& archive, const unsigned int version)
	{
		archive & login & password;
	}
public:
	user(std::string login, std::string password);
	user();
	bool validate_credentials(std::string, std::string);
};

#endif //_USER_H_
