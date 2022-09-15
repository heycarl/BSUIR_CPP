#include "Employee.h"

#include <sstream>

std::string Employee::SerializeEType() {
    switch (emp_type)
    {
    case labman:
        return "Lab-Man";
    case secretary:
        return "Secretary";
    case manager:
        return "Manager";
    case st_prep_kaf:
        return "Legendary figure";
    default:
        return "UNKNOWN ENUM";
    }
}

std::string Employee::GetEmploy() {
    std::string serialized_employee;
    
    std::stringstream ss;
    ss << " | " << uid << " | ";
    ss << rate  << " | ";
    ss << employment_date.GetDate() << " | " ;
    ss << SerializeEType() << " | "  << std::endl;
    serialized_employee = ss.str();
    return serialized_employee;
}
void Employee::PutEmploy(int uid, float rate, std::string e_date, etype e_type) {
    this->uid = uid;
    this->rate = rate;
    this->employment_date.SetDate(e_date);
    this-> emp_type = e_type;
}

Employee::Employee(int uid, float rate, std::string e_date, etype e_type) {
    PutEmploy(uid, rate, e_date, e_type);
}

Employee::Employee(int uid, std::string e_date) {
    PutEmploy(uid, 0.01, e_date, Employee::labman);
}