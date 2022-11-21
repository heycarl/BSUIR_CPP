//
// Created by Alexandr on 10/13/2022.
//

#include <iostream>
#include "../LAB_03/Monoblock/Monoblock.h"
#include "../LAB_03/Laptop/Laptop.h"

#include "errors/Exp_Input.h"
#include "errors/Exp_Output.h"

int main() {
  auto l_Monoblock = Monoblock();
  l_Monoblock.SetBrand("Half");
  l_Monoblock.SetModel("UltraMono-1");

  try {
    l_Monoblock.SetScreenSize(20);
  } catch (Exp_Input& err) {
    std::cout << "Error cached: {\n" << err.show() << "\n}" << std::endl;
  } catch (Exp& err) {
    std::cout << "Unexpected error: {\n" << err.show() << "\n}" << std::endl;
  }

  l_Monoblock.SetCase("PETG Plastic");

  auto l_Laptop = Laptop();
  l_Laptop.SetBrand("Lenovo");
  l_Laptop.SetModel("Thinkpad");
  l_Laptop.SetScreenSize(15.6);

  try {
    l_Laptop.SetBatteryCharge(100);
  } catch (Exp_Input& err) {
    std::cout << "Input error cached: {\n" << err.show() << "\n}" << std::endl;
  } catch (Exp& err) {
    std::cout << "Unexpected error: {\n" << err.show() << "\n}" << std::endl;
  }

  l_Laptop.SetKeyNum(40);

  l_Laptop.SetBrand("asd");

  std::cout << l_Monoblock.SerializeHeader();
  std::cout << l_Monoblock.Serialize() << std::endl;


  std::cout << l_Laptop.SerializeHeader();
  try {
    std::cout << l_Laptop.Serialize() << std::endl;
  } catch (Exp_Output& err) {
    std::cout << "Output error cached: {\n" << err.show() << "\n}" << std::endl;
  } catch (Exp& err) {
    std::cout << "Unexpected error: {\n" << err.show() << "\n}" << std::endl;
  }
}