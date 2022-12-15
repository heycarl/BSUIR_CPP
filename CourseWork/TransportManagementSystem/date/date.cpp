//
// Created by Alexandr on 11/6/2022.
//
#include <sstream>
#include <iomanip>

#include "date.h"

void date::set_date(uint16_t y, uint8_t m, uint8_t d)
{
	year = y;
	month = m;
	day = d;
}
std::string date::serialize_ui() const
{
	std::stringstream ss;
	ss << +year << "." << +month << "." << +day;
	return ss.str();
}
date::date(uint16_t year, uint8_t month, uint8_t day)
		:year(year), month(month), day(day) { }

bool date::date_parser(std::string& s, tm& date)
{
	try {
		boost::gregorian::date d(boost::gregorian::from_simple_string(s));
		date.tm_mday = d.day();
		date.tm_mon = d.month();
		date.tm_year = d.year();
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		return false;
	}
	return true;
}
date::date(std::string s)
{
	set_date(s);
}
void date::set_date(std::tm t)
{
	day = t.tm_mday;
	month = t.tm_mon;
	year = t.tm_year;
}
void date::set_date(std::string s)
{
	std::tm t;
	if (date_parser(s, t))
		set_date(t);
}
