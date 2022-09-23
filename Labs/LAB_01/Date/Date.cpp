#include "Date.h"

#include <utility>

void Date::SetDate(std::string arg_date) {
  m_date = std::move(arg_date);
}

std::string Date::GetDate() {
  return m_date;
}
bool Date::operator==(Date arg_date) {
  return m_date == arg_date.GetDate();
}
