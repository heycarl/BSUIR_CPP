//
// Created by Alexandr on 10/13/2022.
//

#include <iostream>
#include <iomanip>

#include "../errors/Exp_Input.h"

#include "Monoblock.h"
double Monoblock::GetScreenSize() const {
  return m_ScreenSize;
}
void Monoblock::SetScreenSize(double arg_screen_size) {
  if (arg_screen_size < 1 || arg_screen_size > 50)
    throw Exp_Input(1, "Must be in range 1 to 50");
  m_ScreenSize = arg_screen_size;
}
std::string Monoblock::Serialize() {
  std::string serialized_characteristics;
  std::stringstream ss;

  ss << "| " << std::setw(11) << std::left << GetBrand();
  ss << "| " << std::setw(15) << std::left << GetModel();
  ss << "| " << std::setw(15) << std::left << GetCase();
  ss << "| " << std::setw(8) << std::left << m_ScreenSize << " | " << std::endl;

  ss << "|" << std::setfill('-') << std::setw(13) << std::right << "+";
  ss << std::setfill('-') << std::setw(17) << std::right << "+";
  ss << std::setfill('-') << std::setw(17) << std::right << "+";
  ss << std::setfill('-') << std::setw(11) << std::right << "|" << std::endl;

  serialized_characteristics = ss.str();
  return serialized_characteristics;
}
std::string Monoblock::SerializeHeader() {
  std::string serialized_characteristics;
  std::stringstream ss;

  ss << "/" << std::setfill('-') << std::setw(13) << std::right << "T";
  ss << std::setfill('-') << std::setw(17) << std::right << "T";
  ss << std::setfill('-') << std::setw(17) << std::right << "T";
  ss << std::setfill('-') << std::setw(11) << std::right << "\\" << std::endl;

  ss << std::setfill(' ');
  ss << "| " << std::setw(11) << std::left << "Brand";
  ss << "| " << std::setw(15) << std::left << "Model";
  ss << "| " << std::setw(15) << std::left << "Case";
  ss << "| " << std::setw(8) << std::left << "Screen" << " |" << std::endl;

  ss << "|" << std::setfill('-') << std::setw(13) << std::right << "+";
  ss << std::setfill('-') << std::setw(17) << std::right << "+";
  ss << std::setfill('-') << std::setw(17) << std::right << "+";
  ss << std::setfill('-') << std::setw(11) << std::right << "|" << std::endl;

  serialized_characteristics = ss.str();
  return serialized_characteristics;
}
