//
// Created by Alexandr on 11/6/2022.
//

#include "route.h"
const driver &route::get_route_driver () const
{
  return route_driver;
}
void route::set_route_driver (const driver &route_driver)
{
  route::route_driver = route_driver;
}
