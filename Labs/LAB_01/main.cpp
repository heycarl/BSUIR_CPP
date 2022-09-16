#include "Employee/Employee.h"
#include <iostream>

using namespace std;

int main() {
  auto oEmployee = new Employee(1, 0.5, "12.12.2012", Employee::st_prep_kaf);
  auto oEmployee2 = new Employee(2, 0.5, "16.12.2022", Employee::labman);
  auto oEmployee3 = new Employee(3, Employee::manager);

  oEmployee->PutEmploy(1, 0.5, "12.12.2014", Employee::secretary);

  cout << oEmployee->GetEmployee() << endl;
  cout << oEmployee2->GetEmployee() << endl;
  cout << oEmployee3->GetEmployee() << endl;

  return 0;
}
