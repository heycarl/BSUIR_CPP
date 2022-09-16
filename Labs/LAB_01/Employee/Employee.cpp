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

string Employee::GetEmployee() {
  string serialized_employee;

  stringstream ss;
//  ss << " | " << m_UID << setw(4) << " | ";
//  ss << m_rate << setw(6) << " | ";
//  ss << m_employment_date.GetDate() << " | ";
//  ss << SerializeEType() << setw(10) << " | " << endl;

  ss << " | " << std::setw(2) << left << m_UID;
  ss << " | " << std::setw(8) << left << m_rate;
  ss << " | " << std::setw(8) << left << m_employment_date.GetDate();
  ss << " | " << std::setw(9) << left << SerializeEType() << " | " << ends;
  serialized_employee = ss.str();
  return serialized_employee;
}

Employee::Employee(int arg_uid, etype arg_e_type) {
  m_UID = arg_uid;
  m_employment_date.SetDate("22.02.2022");

  default_random_engine oDefaultRandomEngine(arg_uid);
  uniform_real_distribution<double> distribution(0.0, 500.0);
  m_rate = (float)distribution(oDefaultRandomEngine);

  m_emp_type = arg_e_type;
}

void Employee::PutEmployee(int arg_uid, float arg_rate, string arg_e_date, etype arg_e_type) {
  m_UID = arg_uid;
  m_rate = arg_rate;
  m_employment_date.SetDate(std::move(arg_e_date));
  m_emp_type = arg_e_type;
}

Employee::Employee(int arg_uid, float arg_rate, string arg_e_date, etype arg_e_type) {
  m_UID = arg_uid;
  m_rate = arg_rate;
  m_employment_date.SetDate(std::move(arg_e_date));
  m_emp_type = arg_e_type;
}