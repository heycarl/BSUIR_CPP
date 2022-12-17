//
// Created by Alexandr on 10/13/2022.
//

#include "Computer.h"
const std::string &Computer::GetBrand() const {
  return m_Brand;
}
void Computer::SetBrand(const std::string &arg_brand) {
  m_Brand = arg_brand;
}
const std::string &Computer::GetModel()  const {
  return m_Model;
}
void Computer::SetModel(const std::string &arg_model) {
  m_Model = arg_model;
}
