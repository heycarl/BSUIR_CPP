#pragma once

#include <string>

class Date {
 public:
  Date() = default;
//  std::string GetCurrentDate();
  void SetDate(std::string arg_date);
  std::string GetDate();

  bool operator==(Date arg_date);
  ~Date() = default;
 private:
  std::string m_date;
};