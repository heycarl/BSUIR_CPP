//
// Created by Alexandr on 11/6/2022.
//

#include <sstream>
#include <algorithm>

#include "route.h"

const driver& route::get_route_driver () const
{
  return route_driver;
}
void route::set_route_driver (const driver& driver)
{
  route::route_driver = driver;
}
std::string route::serialize_route ()
{
  std::stringstream ss;
  ss << "Route goes from " << route_info.point_1_name << " to " << route_info.point_2_name << ".\n";
  for (auto o : route)
	{
	  ss << o.bus_stop.get_name () << " | "
		 << o.arrival_time << " | "
		 << (!(o.need_to_stop) ? "Bypassed |\n" : "");
	}
  return ss.str ();
}
void route::delete_stop (uint8_t id)
{
  for (auto s : route)
	{
	  route.erase (std::find_if (route.begin (), route.end (),
								 [&] (stop const& s)
								 { return s.bus_stop.get_uid () == id; }));
//	  if (s.bus_stop.get_uid () == id)
//		route.erase (std::find (route.begin(), route.end(), s));
	}
}
