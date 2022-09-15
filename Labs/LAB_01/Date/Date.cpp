#include "Date.h"

#include <utility>

void Date::SetDate(std::string arg_date) {
  this->m_date = std::move(arg_date);
}

std::string Date::GetDate() {
  return m_date;
}