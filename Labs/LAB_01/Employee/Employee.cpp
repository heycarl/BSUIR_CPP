#include "Employee.h"

#include <sstream>
#include <utility>
#include <random>
#include <iomanip>

using namespace std;

string Employee::SerializeEType() {
  switch (m_emp_type) {
    case labman:return "Lab-Man";
    case secretary:return "Secretary";
    case manager:return "Manager";
    case st_prep_kaf:return "Legendary figure";
    default:return "UNKNOWN ENUM";
  }
}

Employee::Employee(int arg_uid, etype arg_e_type) {
  m_UID = arg_uid;
  m_employment_date.SetDate("22.02.2022");

  default_random_engine oDefaultRandomEngine(arg_uid);
  uniform_real_distribution<double> distribution(0.0, 500.0);
  m_rate = (float) distribution(oDefaultRandomEngine);

  m_emp_type = arg_e_type;
}
Employee::Employee(int arg_uid, float arg_rate, string arg_e_date, etype arg_e_type) {
  m_UID = arg_uid;
  m_rate = arg_rate;
  m_employment_date.SetDate(std::move(arg_e_date));
  m_emp_type = arg_e_type;
}
[[maybe_unused]] Employee::Employee(const Employee &arg_source_employee) {
  m_UID = arg_source_employee.GetUID();
  m_rate = arg_source_employee.GetRate();
  m_emp_type = arg_source_employee.GetEmpType();
  m_employment_date = arg_source_employee.GetEmploymentDate();
}

string Employee::GetEmployee() {
  string serialized_employee;

  stringstream ss;

  ss << " | " << std::setw(2) << left << m_UID;
  ss << " | " << std::setw(8) << left << m_rate;
  ss << " | " << std::setw(8) << left << m_employment_date.GetDate();
  ss << " | " << std::setw(9) << left << SerializeEType() << " | " << ends;
  serialized_employee = ss.str();
  return serialized_employee;
}

void Employee::PutEmployee(int arg_uid, float arg_rate, string arg_e_date, etype arg_e_type) {
  m_UID = arg_uid;
  m_rate = arg_rate;
  m_employment_date.SetDate(std::move(arg_e_date));
  m_emp_type = arg_e_type;
}

Employee *Employee::operator+(float arg_bonus) {
  m_rate += arg_bonus;
  return this;
}

int Employee::operator&(const Employee &arg_employee) const {
  return (int) m_rate & (int) arg_employee.GetRate();
}

int Employee::GetUID() const {
  return m_UID;
}
float Employee::GetRate() const {
  return m_rate;
}
const Date &Employee::GetEmploymentDate() const {
  return m_employment_date;
}
Employee::etype Employee::GetEmpType() const {
  return m_emp_type;
}
