//
// Created by Alexandr on 10/13/2022.
//

#include <iostream>
#include <iomanip>
#include "Tablet.h"

const std::string &Tablet::GetModem() const {
  return m_Modem;
}
void Tablet::SetModem(const std::string &arg_modem) {
  m_Modem = arg_modem;
}
std::string Tablet::Serialize() {
  std::string serialized_characteristics;
  std::stringstream ss;

  ss << "| " << std::setw(11) << std::left << GetBrand();
  ss << "| " << std::setw(15) << std::left << GetModel();
  ss << "| " << std::setw(10) << std::left << GetBatteryCharge();
  ss << "| " << std::setw(8) << std::left << GetScreenSize();
  ss << "| " << std::setw(7) << std::left << GetModem() << "| " << std::endl;

  ss << "|" << std::setfill('-') << std::setw(13) << std::right << "+";
  ss << std::setfill('-') << std::setw(17) << std::right << "+";
  ss << std::setfill('-') << std::setw(12) << std::right << "+";
  ss << std::setfill('-') << std::setw(10) << std::right << "+";
  ss << std::setfill('-') << std::setw(9) << std::right << "|" << std::endl;

  serialized_characteristics = ss.str();
  return serialized_characteristics;
}
std::string Tablet::SerializeHeader() {
  std::string serialized_characteristics;
  std::stringstream ss;

  ss << "/" << std::setfill('-') << std::setw(13) << std::right << "T";
  ss << std::setfill('-') << std::setw(17) << std::right << "T";
  ss << std::setfill('-') << std::setw(12) << std::right << "T";
  ss << std::setfill('-') << std::setw(10) << std::right << "T";
  ss << std::setfill('-') << std::setw(9) << std::right << "\\" << std::endl;

  ss << std::setfill(' ');
  ss << "| " << std::setw(11) << std::left << "Brand";
  ss << "| " << std::setw(15) << std::left << "Model";
  ss << "| " << std::setw(10) << std::left << "Charge";
  ss << "| " << std::setw(8) << std::left << "Screen";
  ss << "| " << std::setw(7) << std::left << "Modem" << "|" << std::endl;

  ss << "|" << std::setfill('-') << std::setw(13) << std::right << "+";
  ss << std::setfill('-') << std::setw(17) << std::right << "+";
  ss << std::setfill('-') << std::setw(12) << std::right << "+";
  ss << std::setfill('-') << std::setw(10) << std::right << "+";
  ss << std::setfill('-') << std::setw(9) << std::right << "|" << std::endl;

  serialized_characteristics = ss.str();
  return serialized_characteristics;
}