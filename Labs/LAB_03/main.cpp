//
// Created by Alexandr on 10/13/2022.
//

#include <iostream>
#include "Monoblock/Monoblock.h"
#include "Laptop/Laptop.h"
#include "Tablet/Tablet.h"

int main() {
  auto l_Monoblock = Monoblock();
  l_Monoblock.SetBrand("Half");
  l_Monoblock.SetModel("UltraMono-1");
  l_Monoblock.SetScreenSize(20);
  l_Monoblock.SetCase("PETG Plastic");

  auto l_Laptop = Laptop();
  l_Laptop.SetBrand("Lenovo");
  l_Laptop.SetModel("Thinkpad");
  l_Laptop.SetScreenSize(15.6);
  l_Laptop.SetBatteryCharge(98);
  l_Laptop.SetKeyNum(40);

  auto l_Tablet = Tablet();
  l_Tablet.SetBrand("Samsung");
  l_Tablet.SetModel("Galaxy Tab");
  l_Tablet.SetScreenSize(10);
  l_Tablet.SetBatteryCharge(99);
  l_Tablet.SetModem("3G");

  std::cout << l_Monoblock.SerializeHeader();
  std::cout << l_Monoblock.Serialize() << std::endl;

  std::cout << l_Laptop.SerializeHeader();
  std::cout << l_Laptop.Serialize() << std::endl;

  std::cout << l_Tablet.SerializeHeader();
  std::cout << l_Tablet.Serialize();
}