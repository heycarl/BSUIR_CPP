//
// Created by Alexandr on 10/13/2022.
//

#include "Portable.h"
#include "../errors/Exp_Input.h"

int Portable::GetBatteryCharge() const {
  return m_BatteryCharge;
}
void Portable::SetBatteryCharge(int arg_battery_charge) {
  if (arg_battery_charge < 1 || arg_battery_charge > 100)
    throw Exp_Input(1, "Battery percentage in 1 to 100");
  m_BatteryCharge = arg_battery_charge;
}
double Portable::GetScreenSize() const {
  return m_ScreenSize;
}
void Portable::SetScreenSize(double arg_screen_size) {
  if (arg_screen_size < 1 || arg_screen_size > 25)
    throw Exp_Input(1, "Must be in range 1 to 25");
  m_ScreenSize = arg_screen_size;
}
