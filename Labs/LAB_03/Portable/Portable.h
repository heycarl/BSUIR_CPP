//
// Created by Alexandr on 10/13/2022.
//

#ifndef LABS_LAB_03_PORTABLE_PORTABLE_H_
#define LABS_LAB_03_PORTABLE_PORTABLE_H_

#include <iostream>

#include "../Computer/Computer.h"
class Portable : public Computer{
 private:
 public:
  int GetBatteryCharge() const;
  void SetBatteryCharge(int arg_battery_charge);
  double GetScreenSize() const;
  void SetScreenSize(double arg_screen_size);
 private:
  int m_BatteryCharge = 100;
  double m_ScreenSize = 10;
};

#endif //LABS_LAB_03_PORTABLE_PORTABLE_H_
