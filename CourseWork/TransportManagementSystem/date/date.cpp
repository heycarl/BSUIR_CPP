//
// Created by Alexandr on 11/6/2022.
//
#include <sstream>
#include <iomanip>

#include "date.h"

void date::set_date(uint8_t y, uint8_t m, uint8_t d)
{
	year = y;
	month = m;
	day = d;
}
std::string date::serialize() const
{
	std::stringstream ss;
	ss << +day << "." << +month << "." << +year;
	return ss.str();
}
date::date(uint8_t year, uint8_t month, uint8_t day)
		:year(year), month(month), day(day) { }

bool date::date_parser(std::string& s, std::tm date)
{
	std::tm t;
	std::stringstream ss;
	ss << s;
	ss >> std::get_time(&t, "%d.%b.%Y");
	if (ss.fail())
		return false;
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
