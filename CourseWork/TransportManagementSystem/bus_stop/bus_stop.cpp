//
// Created by Alexandr on 11/6/2022.
//

#include "bus_stop.h"

#include <utility>
uint8_t bus_stop::get_uid () const
{
  return uid;
}
void bus_stop::set_uid (uint8_t uid)
{
  bus_stop::uid = uid;
}
const std::string &bus_stop::get_name () const
{
  return name;
}
void bus_stop::set_name (const std::string &name)
{
  bus_stop::name = name;
}
double bus_stop::get_latitude () const
{
  return latitude;
}
void bus_stop::set_latitude (double d)
{
  bus_stop::latitude = d;
}
double bus_stop::get_longitude () const
{
  return longitude;
}
void bus_stop::set_longitude (double d)
{
  bus_stop::longitude = d;
}
std::list<bus_stop::stop_options> bus_stop::get_options () const
{
  return options;
}
void bus_stop::set_options (std::list<stop_options> stop_options)
{
  bus_stop::options = std::move(stop_options);
}
std::list<std::string> bus_stop::serialize_options ()
{
  std::list<std::string> out;
  for (auto o : bus_stop::options)
    {
      switch (o)
        {
          case rain_cover:out.emplace_back("Rain cover");
          case usb_charger:out.emplace_back("USB charger");
          case coffee_machine:out.emplace_back("Coffee machine");
        }
    }
	return out;
}
