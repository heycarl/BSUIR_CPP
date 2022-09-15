#pragma once

#include <string>
#include "../Date/Date.h"

class Employee
{
public:
    enum etype {
        labman,
        secretary,
        manager, 
        st_prep_kaf
    };
    Employee(int uid, float rate, std::string e_date, etype e_type);
    Employee(int uid, std::string e_date);
    std::string GetEmploy();
    void PutEmploy(int uid, float rate, std::string e_date, etype e_type);
    ~Employee() = default;

private:
    int uid;
    float rate;
    Date employment_date;
    std::string SerializeEType();
    etype emp_type;
};