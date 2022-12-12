//
// Created by Alexandr on 11/26/2022.
//

#ifndef _USER_H_
#define _USER_H_

#include <iostream>
#include <boost/serialization/serialization.hpp>
#include <cryptopp/base64.h>
#include <cryptopp/sha.h>

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
	std::string get_hash(std::string source_str);
public:
	user(std::string login, std::string password);
	user() = default;
	bool validate_credentials(std::string, std::string);
	static void ask_credentials(std::string, std::string&, std::string&);
};

#endif //_USER_H_
