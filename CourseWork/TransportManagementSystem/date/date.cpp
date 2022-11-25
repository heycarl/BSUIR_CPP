//
// Created by Alexandr on 11/6/2022.
//
#include <sstream>

#include "date.h"

void date::set_date (uint8_t y, uint8_t m, uint8_t d)
{
  year = y;
  month = m;
  day = d;
}
std::string date::serialize () const
{
  std::stringstream ss;
  ss << day << "." << month << "." << year;
  return ss.str();
}
