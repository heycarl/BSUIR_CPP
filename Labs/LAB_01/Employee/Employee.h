#pragma once

#include <string>

#include "../Date/Date.h"

class Employee {
 public:
  enum etype {
    labman,
    secretary,
    manager,
    st_prep_kaf
  };
 public:
  Employee(int arg_uid, float arg_rate, std::string arg_e_date, etype arg_e_type);
  Employee(int arg_uid, etype arg_e_type);

  void PutEmploy(int arg_uid, float arg_rate, std::string arg_e_date, etype arg_e_type);
  std::string GetEmployee();

  ~Employee() = default;

 private:
  std::string SerializeEType();

 private:
  int m_UID;
  float m_rate;
  Date m_employment_date;
  etype m_emp_type;
};