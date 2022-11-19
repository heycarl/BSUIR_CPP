//
// Created by Alexandr on 11/19/2022.
//

#include "Exp_Input.h"

#include <utility>
Exp_Input::Exp_Input(int code,std::string borders):Exp(code, "Invalid input") {
  exp_value = std::move(borders);
}
std::string Exp_Input::expected_value() {
  return exp_value;
}
std::string Exp_Input::show() {
  return "Error code: " + std::to_string(GetCode()) + "\n" + Exp::show() + ": " + exp_value;
}
