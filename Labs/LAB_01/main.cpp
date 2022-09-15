#include "Employee/Employee.h"
#include <iostream>

using namespace std;

int main()
{
    auto* emp1 =  new Employee(1, "12.12.2012");
    auto* emp2 =  new Employee(1, 0.5, "12.12.2012", Employee::st_prep_kaf);
    emp2->PutEmploy(1, 0.5, "12.12.2014", Employee::secretary);
    cout << emp1->GetEmploy() << endl;
    cout << emp2->GetEmploy() << endl;

    return 0;
}
