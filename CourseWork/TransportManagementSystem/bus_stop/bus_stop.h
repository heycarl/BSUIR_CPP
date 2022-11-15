//
// Created by Alexandr on 11/6/2022.
//

#ifndef STOP_H_
#define STOP_H_

#include <iostream>
#include <list>

class bus_stop {
 private:
  uint8_t uid;
  std::string name;
  double latitude;
  double longitude;
 public:
  uint8_t get_uid () const;
  void set_uid (uint8_t uid);
  const std::string &get_name () const;
  void set_name (const std::string &name);
  double get_latitude () const;
  void set_latitude (double d);
  double get_longitude () const;
  void set_longitude (double d);
 public:
  enum stop_options {
    rain_cover,
    usb_charger,
    coffee_machine
  };
  std::list<stop_options> get_options () const;
  void set_options (std::list<stop_options> stop_options);
  std::list<std::string> serialize_options();
 private:
    std::list<stop_options> options;
};

#endif //STOP_H_
