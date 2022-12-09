//
// Created by Alexandr on 11/6/2022.
//

#ifndef _DATE_H_
#define _DATE_H_

#include <iostream>
#include <ctime>
#include <boost/serialization/serialization.hpp>

class date {
public:
	uint8_t year = 0;
	uint8_t month = 0;
	uint8_t day = 0;
	date(uint8_t year, uint8_t month, uint8_t day);
	date(std::string);
	date() = default;

	std::string serialize_ui() const;

	void set_date(uint8_t d, uint8_t m, uint8_t y);
	void set_date(std::tm);
	void set_date(std::string);

	static bool date_parser(std::string&, std::tm);
private:
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive& archive, const unsigned int version)
	{
		archive & year & month & day;
	}
};

#endif //_DATE_H_
