//
// Created by Alexandr on 10/13/2022.
//

#include <iomanip>
#include "Laptop.h"
#include "../errors/Exp_Output.h"

int Laptop::GetKeyNum() const {
  return m_KeyNum;
}
void Laptop::SetKeyNum(int arg_key_num) {
  m_KeyNum = arg_key_num;
}
std::string Laptop::Serialize() {
  std::string serialized_characteristics;
  std::stringstream ss;

  struct field_width {
    uint8_t brand_w = 11;
    uint8_t model_w = 15;
    uint8_t battery_w = 10;
    uint8_t screen_w = 8;
    uint8_t key_num_w = 7;
  } field_width;

  if (GetBrand().length() > field_width.brand_w)
    throw Exp_Output(2, "Brand length bigger than field size");
  if (GetModel().length() > field_width.model_w)
    throw Exp_Output(2, "Model length bigger than field size");
  if (std::to_string(GetBatteryCharge()).length() > field_width.battery_w)
    throw Exp_Output(2, "Battery charge bigger than field size");
  if (std::to_string(GetKeyNum()).length() > field_width.key_num_w)
    throw Exp_Output(2, "Key num length bigger than field size");

  ss << "| " << std::setw(field_width.brand_w) << std::left << GetBrand()
     << "| " << std::setw(field_width.model_w) << std::left << GetModel()
     << "| " << std::setw(field_width.battery_w) << std::left << GetBatteryCharge()
     << "| " << std::setw(field_width.screen_w) << std::left << GetScreenSize()
     << "| " << std::setw(field_width.key_num_w) << std::left << GetKeyNum() << "| " << std::endl;

  ss << "|" << std::setfill('-') << std::setw(13) << std::right << "+"
     << std::setfill('-') << std::setw(17) << std::right << "+"
     << std::setfill('-') << std::setw(12) << std::right << "+"
     << std::setfill('-') << std::setw(10) << std::right << "+"
     << std::setfill('-') << std::setw(9) << std::right << "|" << std::endl;

  serialized_characteristics = ss.str();
  return serialized_characteristics;
}
std::string Laptop::SerializeHeader() {
  std::string serialized_characteristics;
  std::stringstream ss;

  ss << "/" << std::setfill('-') << std::setw(13) << std::right << "T"
     << std::setfill('-') << std::setw(17) << std::right << "T"
     << std::setfill('-') << std::setw(12) << std::right << "T"
     << std::setfill('-') << std::setw(10) << std::right << "T"
     << std::setfill('-') << std::setw(9) << std::right << "\\" << std::endl;

  ss << std::setfill(' ')
     << "| " << std::setw(11) << std::left << "Brand"
     << "| " << std::setw(15) << std::left << "Model"
     << "| " << std::setw(10) << std::left << "Charge"
     << "| " << std::setw(8) << std::left << "Screen"
     << "| " << std::setw(7) << std::left << "Keys" << "|" << std::endl;

  ss << "|" << std::setfill('-') << std::setw(13) << std::right << "+"
     << std::setfill('-') << std::setw(17) << std::right << "+"
     << std::setfill('-') << std::setw(12) << std::right << "+"
     << std::setfill('-') << std::setw(10) << std::right << "+"
     << std::setfill('-') << std::setw(9) << std::right << "|" << std::endl;

  serialized_characteristics = ss.str();
  return serialized_characteristics;
}

