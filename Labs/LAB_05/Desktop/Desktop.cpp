//
// Created by Alexandr on 10/13/2022.
//

#include "Desktop.h"
const std::string &Desktop::GetCase() const {
  return m_Case;
}
void Desktop::SetCase(const std::string &arg_case) {
  m_Case = arg_case;
}
