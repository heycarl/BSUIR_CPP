//
// Created by Alexandr on 10/13/2022.
//

#include "Portable.h"
int Portable::GetBatteryCharge() const {
  return m_BatteryCharge;
}
void Portable::SetBatteryCharge(int arg_battery_charge) {
  m_BatteryCharge = arg_battery_charge;
}
double Portable::GetScreenSize() const {
  return m_ScreenSize;
}
void Portable::SetScreenSize(double arg_screen_size) {
  m_ScreenSize = arg_screen_size;
}
