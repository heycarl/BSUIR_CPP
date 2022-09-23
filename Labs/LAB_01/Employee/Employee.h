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
  [[maybe_unused]] Employee(Employee const &arg_source_employee);

  Employee *operator+(float arg_bonus);
  int operator&(const Employee &arg_employee) const;

  void PutEmployee(int arg_uid, float arg_rate, std::string arg_e_date, etype arg_e_type);
  std::string GetEmployee();
  [[nodiscard]] int GetUID() const;
  [[nodiscard]] float GetRate() const;
  [[nodiscard]] const Date &GetEmploymentDate() const;
  [[nodiscard]] etype GetEmpType() const;

  ~Employee() = default;

 private:
  std::string SerializeEType();
 private:
  int m_UID;
  float m_rate;
  Date m_employment_date;
  etype m_emp_type;
};